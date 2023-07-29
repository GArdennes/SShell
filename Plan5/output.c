#include "sshell.h"

void write_to_buffer(char c, int *i, char *buf)
{
	if (*i >= MAX_ARGS)
	{
		write(1, buf, *i);
		*i = 0;
	}

	buf[(*i)++] = c;
}

void _flush_buffer(int i, char *buf)
{
	if (i > 0)
	{
		write(1, buf, i);
	}
}

int _putchar(char c)
{
	static int i = 0;
	static char buf[MAX_ARGS];

	if (c != -1)
		write_to_buffer(c, &i, buf);
	else
	{
		_flush_buffer(i, buf);
		i = 0;
	}

	return (0);
}

void _puts(char *str)
{
	int i = 0;

	if (str == NULL)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

void print_error(char *str)
{
	_eputs(fname);
	_eputs(": ");
	print_d(line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(argv[0]);
	_eputs(": ");
	_eputs(str);
}

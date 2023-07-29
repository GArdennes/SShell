#include "sshell.h"

static int i = 0;
static char buf[MAX_ARGS];

void write_to_buffer(char c)
{
	if (i >= MAX_ARGS)
	{
		write(1, buf, i);
		i = 0;
	}

	buf[i++] = c;
}

void _flush_buffer(void)
{
	if (i > 0)
	{
		write(1, buf, i);
		i = 0;
	}
}

int _putchar(char c)
{
	if (c != -1)
		write_to_buffer(c);
	else
		_flush_buffer();
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
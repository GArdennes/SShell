#include "sshell.h"

/**
 * write_to_buffer - write a string to the buffer
 * @c: the character to write
 * @i: the index of the character
 * @buf: the buffer to write
 */
void write_to_buffer(char c, int *i, char *buf)
{
	if (*i >= MAX_ARGS)
	{
		write(1, buf, *i);
		*i = 0;
	}

	buf[(*i)++] = c;
}

/**
 * _flush_buffer - flush the buffer
 * @i: the index of the buffer to flush
 * @buf: the buffer to flush
 */
void _flush_buffer(int i, char *buf)
{
	if (i > 0)
	{
		write(1, buf, i);
	}
}

/**
 * _putchar - put a character
 * @c: the character
 * Return: On success int
 */
int _putchar(char c)
{
	static int i;
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

/**
 * _puts - prints the given string
 * @str: the string to print
 */
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

/**
 * print_error - print an error message
 * @str: the string to print
 */
void print_error(char *str)
{
	err_puts(fname);
	err_puts(": ");
	print_d(line_count, STDERR_FILENO);
	err_puts(": ");
	err_puts(argv[0]);
	err_puts(": ");
	err_puts(str);
}

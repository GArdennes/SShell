#include "sshell.h"

/**
 * convert_to_string - convert a string
 * @num: number
 * @base: number base
 * @flags: number flags
 * Return: On success char*
 */
char *convert_to_string(unsigned long num, int base, int flags)
{
static char buffer[MAX_ARGS];
char *ptr = &buffer[MAX_ARGS - 1];
const char *array = flags & 1 ? "0123456789abcdef" : "0123456789ABCDEF";

*ptr = '\0';

do {
*--ptr = array[num % base];
num /= base;
} while (num != 0);

return (ptr);
}

/**
 * handle_sign - command to handle signature
 * @str: string
 * @num: number
 * @flags: number flags
 * Return: On success char*
 */
char *handle_sign(char *str, long int num, int flags)
{
if (!(flags & 2) && num < 0)
*--str = '-';
return (str);
}

/**
 * convert_number - convert a number
 * @num: number to convert
 * @base: base to convert
 * @flags: flags to convert
 * Return: On success char*
 */
char *convert_number(long int num, int base, int flags)
{
char *str = convert_to_string(num < 0 ? -num : num, base, flags);

return (handle_sign(str, num, flags));
}

/**
 * ffree - frees the memory allocated
 * @str: the string to free
 */
void ffree(char **str)
{
char **a = str;

if (str == NULL)
return;

while (*str != NULL)
free(*str++);
free(a);
}

/**
 * print_d: print the information
 * @input: the input number
 * @fd: the file descriptor
 * Return: On success int
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = err_putchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

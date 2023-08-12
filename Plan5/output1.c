#include "sshell.h"

/**
 * ewrite_to_buffer - write a string to the specified buffer
 * @c: the character to write
 * @j: the index of the character to write
 * @buf: the string to write
 */
void ewrite_to_buffer(char c, int *j, char *buf)
{
if (*j >= MAX_ARGS)
{
write(2, buf, *j);
*j = 0;
}

buf[(*j)++] = c;
}

/**
 * eflush_buffer - flush the buffer
 * @j: the index of the buffer
 * @buf: the buffer to flush
 */
void eflush_buffer(int j, char *buf)
{
if (j > 0)
{
write(2, buf, j);
}
}

/**
 * _eputchar - prints the error character
 * @c: the error character
 * Return: On success int
 */
int _eputchar(char c)
{
static int j;
static char buf[MAX_ARGS];

if (c != -1)
ewrite_to_buffer(c, &j, buf);
else
{
eflush_buffer(j, buf);
j = 0;
}

return (0);
}

/**
 * _eputs - converts a string to the STDERR
 * @str: the string to be converted
 */
void _eputs(char *str)
{
int j = 0;

if (str == NULL)
return;
while (str[j] != '\0')
{
_eputchar(str[j]);
j++;
}
}

/**
 * _erratoi - converts ASCII string to integer for STDERR
 * @s: the string to convert
 * Return: On success int
 */
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;

if (*s == '+')
s++;

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result *= 10;
result += (s[i] - '0');
if (result > 1024)
return (-1);
}
else
return (-1);
}
return (result);
}

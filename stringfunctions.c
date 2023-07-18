#include "shell.h"

size_t _strcspn(char *str, char *reject)
{
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; reject[j] != '\0'; j++)
		{
			if (str[i] == reject[j])
				return (i);
		}
	}
	return (i);
}

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

int _strncmp(char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] == s2[i] && s1[i] != '\0'; i++)
		;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * _puts - prints string
 * @str: characters to print
 * Returns: On success, string is printed
 */
void _puts(char *str)
{
	int count = 0;

	if (str == NULL)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - prints single character
 * @ch: character to be inserted
 * Return: On success the character
 */
char _putchar(char ch)
{
	return (write(1, &ch, 1));
}
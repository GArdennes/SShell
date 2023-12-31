#include "sshell.h"

/**
 * _getenv - get the environment variable
 * @name: the name of the variable
 * Return: On success char*
 */
char *_getenv(char *name)
{
	int i, b, c;
	size_t len1, len2;
	char *value = NULL;

	len1 = _strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(name, environ[i], len1) == 0)
		{
			len2 = _strlen(environ[i]) - len1 - 1;
			value = malloc(sizeof(char) * (len2 + 1));
			if (value == NULL)
			{
				perror(name);
				return (NULL);
			}
			b = 0;
			for (c = len1 + 1; environ[i][c]; c++, b++)
				value[b] = environ[i][c];
			value[b] = '\0';
			return (value);
		}
	}
	return (value);
}

/**
 * _memset - set value of memory
 * @s: pointer to memory
 * @b: pointer to character
 * @n: number of bytes to set
 * Return: On success char*
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

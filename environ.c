#include "shell.h"


void printenv(void)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}

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

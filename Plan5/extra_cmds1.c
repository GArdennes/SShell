#include "sshell.h"

/**
 *_unsetenv - duplicate of unsetenv inbuilt function
 *@name: string to check
 *Return: On success flag
 */
int _unsetenv(char *name)
{
int i, j;
int len = _strlen(name);

for (i = 0; environ[i] != NULL; i++)
{
if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
{
for (j = i; environ[j] != NULL; j++)
environ[j] = environ[j + 1];
return (0);
}
}
return (-1);
}

/**
 * _mysetenv - set the environment
 * Return: On success call another function
 */
int _mysetenv(void)
{
if (argv[2] == NULL)
{
err_puts("setenv error");
return (1);
}
if (_setenv(argv[1], argv[2]))
return (0);
return (1);
}

/**
 * _myunsetenv - unset the environment variable
 * Return: On success int
 */
int _myunsetenv(void)
{
int i;

if (argv[1] == NULL)
{
err_puts("unsetenv error");
return (1);
}
for (i = 1; i <= argc; i++)
{
_unsetenv(argv[i]);
}
return (0);
}

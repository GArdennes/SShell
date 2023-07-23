#include "shell.h"

/**
 *_getenv - duplicate of getenv inbuilt function
 *@name: string to check
 *Return: On success string

char *_getenv(char *name)
{
int i;
int len = _strlen(name);

for (i = 0; environ[i] != NULL; i++)
{
if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
{
return (environ[i] + len + 1);
}
}
return;
}
*/

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
 *_setenv - duplicate of setenv inbuilt function
 *@name: string to check
 *@value: string to check
 *Return: On success flag
 */
int _setenv(char *name, char *value)
{
int i, nlen = _strlen(name), vlen = _strlen(value);
int env_size = 0, entry_len;
char *new_entry, **new_environ;

while (environ[env_size] != NULL)
env_size++;

for (i = 0; environ[i] != NULL; i++)
{
if (strncmp(environ[i], name, nlen) == 0 && environ[i][nlen] == '=')
{
entry_len = nlen + vlen + 2;
new_entry = (char *)malloc(entry_len);
if (new_entry == NULL)
return (-1);
/*
_memcpy(new_entry, name, nlen);
new_entry[nlen] = '=';
_memcpy(new_entry + nlen + 1, value, vlen);
new_entry[entry_len - 1] = '\0';
*/
_strcpy(new_entry, name);
_strcat(new_entry, "=");
_strcat(new_entry, value);


free(environ[i]);
environ[i] = new_entry;
return (0);
}
}

entry_len = nlen + vlen + 2;
new_entry = (char *)malloc(entry_len);
if (new_entry == NULL)
return (-1);
/*
memcpy(new_entry, name, nlen);
new_entry[nlen] = '=';
memcpy(new_entry + nlen + 1, value, vlen);
new_entry[entry_len - 1] = '\0';
*/
_strcpy(new_entry, name);
_strcat(new_entry, "=");
_strcat(new_entry, value);

new_environ = (char **)malloc((env_size + 2) * sizeof(char *));
if (new_environ == NULL)
{
free(new_entry);
return (-1);
}

for (i = 0; environ[i] != NULL; i++)
new_environ[i] = environ[i];

new_environ[env_size] = new_entry;
new_environ[env_size + 1] = NULL;

free(environ);
environ = new_environ;

return (0);
}

/**
 * _mysetenv - set the environment
 * @args: Arguments to check
 * Return: On success call another function
 */
void _mysetenv(char **args)
{
    if (args[2] == NULL)
    {
        perror("setenv");
        return;
    }
    if (_setenv(args[1], args[2]))
        return;
}

void _myunsetenv(char **args)
{
    if (args[1] == NULL)
    {
        perror("unsetenv");
        return;
    }
    if (_unsetenv(args[1]))
        return;
}

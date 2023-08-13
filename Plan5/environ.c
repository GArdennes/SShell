#include "sshell.h"

/**
 * get_env_size - get the size of the environment
 * @environ: the environment
 * Return: On success int
 */
int get_env_size(char **environ)
{
int size = 0;
while (environ[size] != NULL)
size++;
return (size);
}

/**
 * create_new_entry - function to create a new entry in the environment array
 * @name: string to check
 * @value: string to check
 * Return: On success char*
 */
char *create_new_entry(char *name, char *value)
{
int nlen = _strlen(name), vlen = _strlen(value);
int entry_len = nlen + vlen + 2;

char *new_entry = (char *)malloc(entry_len);
if (new_entry == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
_strcpy(new_entry, name);
_strcat(new_entry, "=");
_strcat(new_entry, value);

return (new_entry);
}

/**
 * free_environment - free the environment array
 *
 */
void free_environment(void)
{
int i;

for (i = 0; environ[i] != NULL; i++)
free(environ[i]);
}

/**
 * _setenv - sets the environment variable
 * @name: string to check
 * @value: string to check
 * Return: On success int
 */
int _setenv(char *name, char *value)
{
int nlen = _strlen(name), i, vlen = _strlen(value);
int env_size, entry_len;
char *new_entry;
char **new_environ;

entry_len = nlen + vlen + 2;
new_entry = (char *)malloc(entry_len);
if (new_entry == NULL)
return (-1);
for (i = 0; environ[i] != NULL; i++)
{
if (_strncmp(environ[i], name, nlen) == 0 && environ[i][nlen] == '=')
{
/*printf("Updating existing entry: %s\n", environ[i]);*/
new_entry = create_new_entry(name, value);
free(environ[i]);
environ[i] = new_entry;
return (0);
}
}

/*printf("Creating new entry\n");*/
new_entry = create_new_entry(name, value);
env_size = get_env_size(environ);
new_environ = (char **)malloc((env_size + 2) * sizeof(char *));
if (new_environ == NULL)
{
free(new_entry);
return (-1);
}
for (i = 0; environ[i] != NULL; i++)
new_environ[i] = environ[i];
environ[env_size] = new_entry;
environ[env_size + 1] = NULL;
/*printf("Free environment array\n");*/
/*free_environment();*/
/*environ = new_environ;*/

return (0);
}

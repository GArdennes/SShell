#include "sshell.h"

/**
 * _strcat - strcat function
 * @dest: the destination string 
 * @src: the source string 
 * Return: On success char* 
 */
char *_strcat(char *dest, char *src)
{
    char *ptr;

    if (dest == NULL || src == NULL)
        return (NULL);
    
    ptr = dest;
    while (*ptr != '\0')
        ptr++;
    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';

    return (dest);
}

/**
 * _strcpy - strcpy function
 * @dest: destination string 
 * @src: source string 
 * Return: On success char* 
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * handle_comments - handle comments
 * @command: the command string 
 */
void handle_comments(char *command)
{
	int i;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '#')
		{
			command[i] = '\0';
			break;
		}
	}
}
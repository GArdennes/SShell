#include "sshell.h"

/**
 * replace_string - replace an old string with a new string
 * @src: the old string 
 * @dest: the new string 
 * Return: On success int 
 */
int replace_string(char **src, char *dest)
{
    free(*src);
    *src = dest;
    return (1);
}

/**
 * _strlen - Returns the length of the string
 * @s: The string to check 
 * Return: On success int 
 */
int _strlen(char *s)
{
    int i = 0;

    if (s == NULL)
        return (0);
    
    while (*s++)
        i++;
    return (i);
}

/**
 * _strcmp - strcmp function
 * @s1: string to compare 
 * @s2: the second string to compare 
 * Return: On success int 
 */
int _strcmp(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (0);
    
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

/**
 * _strchr - strchr function
 * @s: string to check 
 * @c: character 
 * Return: On success char* 
 */
char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (s);
        s++;
    }

    if (c == '\0')
        return (s);
    
    return (NULL);
}

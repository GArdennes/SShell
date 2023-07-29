#include "sshell.h"

int replace_string(char **src, char *dest)
{
    free(*old);
    *old = new;
    return (1);
}

int _strlen(char *s)
{
    int i = 0;

    if (s == NULL)
        return (0);
    
    while (*s++)
        i++;
    return (i);
}

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
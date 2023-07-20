#include "shell.h"

int _strlen(char *s)
{
    int i = 0;

    if (!s)
        return (0);
    while (*s++)
        i++;
    return (i);
}

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
    ssize_t r = 0;

    if (*i)
        return (0);
    r = read(info->readfd, buf, READ_BUF_SIZE);
    if (r >= 0)
        *i = r;
    return (r);
}

char *_strchr(char *s, char c)
{
    do {
        if (*s ==c)
            return (s);
    } while (*s++ != '\0');

    return (NULL);
}

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;

    if (!ptr)
        return (malloc(new_size));
    if (!new_size)
        return (free(ptr), NULL);
    if (new_size == old_size)
        return (ptr);
    
    p = malloc(new_size);
    if (!p)
        return (NULL);
    
    old_size = old_size < new_size ? old_size : new_size;
    while (old_size--)
        p[old_size] = ((char *)ptr)[old_size];
    free(ptr);
    return (p);
}

char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    if (j < n)
        dest[i] = '\0';
    return (s);
}
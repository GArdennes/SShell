#include "sshell.h"

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
#include "sshell.h"

/**
 * _strncat - strncat function
 * @dest: destination
 * @src: source
 * @len: destination length
 * Return: On success char*
 */
char *_strncat(char *dest, char *src, int len)
{
char *ptr = dest;

while (*ptr != '\0')
ptr++;

while ((*src != '\0') && len > 0)
{
*ptr = *src;
ptr++;
src++;
len--;
}

*ptr = '\0';

return (ptr);
}

/**
 * _strncpy - strncpy function
 * @dest: destination string
 * @src: source string
 * @len: length of string
 * Return: On success char*
 */
char *_strncpy(char *dest, char *src, int len)
{
int i;

for (i = 0; i < len && src[i] != '\0'; i++)
dest[i] = src[i];

for (; i < len; i++)
dest[i] = '\0';

return (dest);
}

/**
 * _strncmp - strncmp function
 * @s1: string
 * @s2: string
 * @len: number of characters
 * Return: On success int
 */
int _strncmp(char *s1, char *s2, size_t len)
{
	size_t i;

	for (i = 0; i < len && s1[i] == s2[i] && s1[i] != '\0'; i++)
		;
	if (i == len)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * dup_chars - duplicate characters
 * @str: the string to duplicate
 * @start: the start
 * @stop: the stop
 * Return: On success char*
 */
char *dup_chars(char *str, int start, int stop)
{
char *result;
int i, j, len;

if (str == NULL || start < 0 || stop < start || start >= _strlen(str))
return (NULL);

len = stop - start + 1;

result = (char *)malloc((len + 1) * sizeof(char));
if (result == NULL)
return (NULL);

if (len <= 0)
return (NULL);

for (i = start, j = 0; i <= stop; i++, j++)
result[j] = str[i];

result[j] = '\0';
return (result);
}

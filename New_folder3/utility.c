#include "sshell.h"

/**
 * _strcat - duplicate of strcat
 * @dest: string to check
 * @src: string to check
 * Return: char*
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int dest_len = _strlen(dest);

	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strlen - duplicate of strlen
 * @str: string to check
 * Return: size_t
 */
size_t _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcpy - duplicate of strcpy
 * @dest: string to check
 * @src: string to check
 * Return: char*
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - duplicate of strcmp
 * @s1: string to check
 * @s2: string to check
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] < s2[i] ? -1 : 1);
}

/**
 * _strncmp - duplicate of strncmp
 * @s1: string to check
 * @s2: string to check
 * @len: length of string
 * Return: int
 */
int _strncmp(char *s1, const char *s2, size_t len)
{
	size_t i;

	for (i = 0; i < n && s1[i] == s2[i] && s1[i] != '\0'; i++)
		;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


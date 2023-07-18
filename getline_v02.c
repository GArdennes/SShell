#include "shell.h"

/**
 * _memcpy - function to act like memcpy
 * @dest: String to check
 * @src: String to check
 * @n: Number to check
 * Return: On success a string
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _realloc - function to act like realloc
 * @ptr: placeholder
 * @olds: number to check
 * @news: number to check
 * Return: On success placeholder
 */
void *_realloc(void *ptr, unsigned int olds, unsigned int news)
{
	void *new_ptr;

	if (news == olds)
		return (ptr);
	if (news == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(news);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		_memcpy(new_ptr, ptr, olds);
		free(ptr);
	}

	return (new_ptr);
}

/**
 * _getline - function to act as getline
 * Return: On success a string
 */
char *_getline()
{
	int i, bufsize = MAX_ARGS, rd;
	static char c;
	char *buf = malloc(MAX_ARGS);

	c = 0;
	if (buf == NULL)
		return (NULL);
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buf);
			exit(EXIT_SUCCESS);
		}
		buf[i] = c;
		if (buf[0] == '\n')
		{
			free(buf);
			return("\0");
		}
		if (i >= bufsize)
		{
			buf = _realloc(buf, bufsize, bufsize + 1);
			if (buf == NULL)
				return (NULL);
			bufsize++;
		}
	}
	buf[i] = '\0';
	handle_comments(buf);
	return (buf);
}

/**
 * _memset - fill a block of memory with a given value
 * @s: string to check
 * @b: character to check
 * @n: number to check 
 * Return: On success memory allocated
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *string = s;

	while (n > 0)
	{
		*s = b;
		s++;
		n--;
	}

	return (string);
}
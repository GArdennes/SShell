#include "sshell.h"

/**
 * is_delim - function to check if a string is a delimiter
 * @c: the character to check 
 * @delim: the string to check 
 * Return: On success int 
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
			return (1);
	}
	return (0);
}

/**
 * input_buf - function to read input 
 * @buf: input buffer 
 * @len: length of input buffer 
 * Return: On success ssize_t 
 */
ssize_t input_buf(char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
		r = getline(buf, &len_p, stdin);
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			linecount_flag = 1;
			handle_comments(*buf);
			*len = r;
			cmd_buf = buf;
		}
	}
	return (r);
}

/**
 * get_input - get input from commandline
 * Return: On success ssize_t 
 */
ssize_t get_input(void)
{
	static char *buf; 
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(arg), *p;

	_putchar(-1);
	r = input_buf(&buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)
	{
		j = i; 
		p = buf + i;

        while (j < len && buf[j] != ';')
            j++;

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
		}

		*buf_p = p; 
		return (_strlen(p));
	}

	*buf_p = buf;
	return (r);
}

/**
 * is_cmd - returns true if the command is a command
 * @pp: command string 
 * Return: On success int 
 */
int is_cmd(char *pp)
{
	struct stat st;

	if (pp == NULL || stat(pp, &st))
		return (0);

	if (st.st_mode & S_IFREG)
		return (1);
	return (0);
}





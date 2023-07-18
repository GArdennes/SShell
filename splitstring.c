#include "shell.h"

unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

char *_strtok(char *str, char *delim)
{
	static char *ts;
	static char *nt;
	unsigned int i;

	if (str == NULL && delim == NULL)
		return (NULL);
	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (check_delim(ts[i], delim) == 0)
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
	{
		if (check_delim(nt[i], delim) == 1)
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}

char **split_str(char *input, char *delim)
{
	char **tokens = malloc(sizeof(char *) * MAX_ARGS), **new_tokens;
	char *token;
	int i = 0;

	if (input == NULL)
		return (NULL);

	if (tokens == NULL)
		return (NULL);

	token = _strtok(input, delim);
	while (token != NULL)
	{
		if (i >= MAX_ARGS)
		{
			new_tokens = realloc(tokens, sizeof(char *) * (MAX_ARGS * 2));
			if (new_tokens == NULL)
			{
				free(tokens);
				return (NULL);
			}
			tokens = new_tokens;
		}
		tokens[i] = token;
		token = _strtok(NULL, delim);
		i++;
	}

	if (token == NULL && i == 0)
	{
		free(tokens);
		return (NULL);
	}

	return (tokens);
}

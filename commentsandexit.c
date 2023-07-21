#include "shell.h"

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

void exit_shell(char **args)
{
	int i;

	if (args[1] != NULL)
	{
		i = _eatoi(args[1]);
		if (i == -1)
		{
			free(args);
			exit(EXIT_FAILURE);
		}
		free(args);
		exit(i);
	}
}

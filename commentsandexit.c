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

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
	exit(EXIT_SUCCESS);
}

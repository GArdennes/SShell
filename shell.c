#include "shell.h"

int main(void)
{
	char **commands;
	char *user_input = malloc(sizeof(char) * MAX_ARGS);

	if (user_input == NULL)
	{
		perror("shell");
		exit(EXIT_FAILURE);
	}

	user_input[0] = '\0';
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		user_input = _getline();

		if (user_input[0] == '\0')
		{
			continue;
		}

		commands = split_str(user_input, "\t|;&\n");

		execute_commands(commands);

		free(commands);
	}
	free(user_input);

	return (0);
}

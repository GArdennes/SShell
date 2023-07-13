#include "header.h"

#define MAX_ARGS 1024

char **parse_input(char *input)
{
	int i = 0;
	char **args;
	char *token;

	args = malloc(sizeof(char *) * (MAX_ARGS));

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \n");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;

	return args;
}

int main(void)
{
	char *input;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status;

	input = NULL;
	while (1)
	{
		printf("$ ");
		read = getline(&input, &len, stdin);

		if (read == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		if (strcmp(input, "exit\n") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		char **args = parse_input(input);

		pid = fork();
		if (pid == -1) 
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			} else {
				wait(&status);
			}
			free(args);
		}
	}
	return 0;
}

		

#include "shell.h"

/*
void execute_single_command(char **args)
{
	if (_strcmp(args[0], "cd") == 0)
		_cd(args[1]);
	else if (_strcmp(args[0], "echo") == 0)
		echo_func(args);
	else if (_strcmp(args[0], "exit") == 0)
		exit_shell(args);
	else if (_strcmp(args[0], "env") == 0)
		printenv();
	else
		execute_command(args);
}
*/

/**
 * execute_commands - function to select command
 * @commands: Array of strings to check
 */
void execute_commands(char **commands)
{
	int i = 0;
	char **args;

	if (commands[i] != NULL)
	{
		args = split_str(commands[i], " \t\n");
		if (args[0] != NULL && args !=NULL)
		{
			if (_strcmp(args[0], "cd") == 0)
				_cd(args[1]);
			else if (_strcmp(args[0], "echo") == 0)
				echo_func(args);
			else if (_strcmp(args[0], "exit") == 0)
				exit_shell(args);
			else if (_strcmp(args[0], "env") == 0)
				printenv();
			else if (_strcmp(args[0], "setenv") == 0)
				_mysetenv(args);
			else if (_strcmp(args[0], "unsetenv") == 0)
				_myunsetenv(args);
			else
				execute_command(args);
		}
		free(args);
	}
}

/**
 * execute_command - function to execute cmd
 * @command: Array of strings to check
 */
void execute_command(char **command)
{
	pid_t pid = fork();
	char path[100] = "/bin/";
	int status;

	if (*command == NULL)
		return;

	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		if (_strncmp(*command, "./", 2) != 0 && _strncmp(*command, "/", 1) != 0)
		{
			strcat(path, *command);
			if (execve(path, command, environ) == -1)
				perror(command[0]);
		}
		if (execve(*command, command, environ) == -1)
			perror(command[0]);
		exit_status = 1;
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
}

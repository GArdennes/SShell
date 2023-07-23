#include "shell.h"

void print_number(unsigned int n);

void printecho(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (*cmd == NULL)
		return;
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
			return;
		exit_status = 1;
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

void echo_func(char **cmd)
{
	char *path, *env_var;
	unsigned int pid = getpid();

	if (cmd[1] != NULL)
	{
		if (_strncmp(cmd[1], "$?", 2) == 0)
		{
			_puts(exit_status);
			write(STDOUT_FILENO, "\n", 1);
		}
		else if (_strncmp(cmd[1], "$$", 2) == 0)
		{
			print_number((unsigned int)pid);
			write(STDOUT_FILENO, "\n", 1);
		}
		else if ((cmd[1][0] == "$") && (cmd[1] + 1 != NULL))
		{
			env_var = cmd[1] + 1;
			path = _getenv(env_var);
			write(STDOUT_FILENO, path, _strlen(path));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
			printecho(cmd);
	}
	else
		write(STDOUT_FILENO, "\n", 1);
}

void print_number(unsigned int n)
{
	char *str;
	int len = 0;
	unsigned int x = n;

	do {
		len++;
		x /= 10;
	} while (x != 0);
	str = malloc(len + 1);

	if (str == NULL)
	{
		perror("malloc");
		return;
	}
	str[len] = '\0';

	x = n;
	do {
		len--;
		str[len] = '0' + (x % 10);
		x /= 10;
	} while (x != 0);
	write(STDOUT_FILENO, str, len + 1);
	free(str);
	write(STDOUT_FILENO, "\n", 1);
}

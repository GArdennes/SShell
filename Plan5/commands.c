#include "sshell.h"

char *starts_with(const char *s1, const char *s2)
{
	while (*s2)
	{
		if (*s2++ != *s1++)
			return (NULL);
	}
	return ((char *)s1);
}

void wait_for_child(int *status)
{
	wait(status);
}

void handle_child_status(int status)
{
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		if (status == 126)
			print_error("Permission denied\n");
	}
}

void execute_cmd(void)
{
	if (execve(path, argv, environ) == -1)
	{
		free_info(1);
		if (errno == EACCES)
			exit(126);
		exit(1);
	}
}

void fork_cmd(void)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:")
		return;
	}

	if (child_pid == 0)
		execute_cmd();
	else
	{
		wait_for_child(&status);
		handle_child_status(status);
	}
}
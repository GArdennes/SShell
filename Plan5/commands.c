#include "sshell.h"

/**
 * starts_with - starts with function
 * @s1: string to check 
 * @s2: string to check 
 * Return: On success char* 
 */
char *starts_with(const char *s1, const char *s2)
{
	while (*s2)
	{
		if (*s2++ != *s1++)
			return (NULL);
	}
	return ((char *)s1);
}

/**
 * wait_for_child - function to wait for child process
 * @status: status of child process 
 */
void wait_for_child(int *status)
{
	wait(status);
}

/**
 * handle_child_status - handle child status
 * @status: status of child process 
 */
void handle_child_status(int status)
{
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		if (status == 126)
			print_error("Permission denied\n");
	}
}

/**
 * execute_cmd - execute command 
 */
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

/**
 * fork_cmd - fork a command 
 */
void fork_cmd(void)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
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

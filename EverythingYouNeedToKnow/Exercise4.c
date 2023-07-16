#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child, parent;
	int count = 0;
	//int status;
	char *command[] = {"ls", "-l", " /tmp"};

	parent = getpid();
	for (count = 0; count < 5; count++)
	{
		child = fork();
		if (child == 0)
			execve("/bin/", command, NULL);
		if (parent == getpid())
			wait(NULL);
	}

	return 0;
}

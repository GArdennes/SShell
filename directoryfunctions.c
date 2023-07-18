#include "shell.h"

int _cd(char *dir)
{
	if (dir == NULL)
	{
		if (chdir(_getenv("HOME")) == -1)
		{
			perror("chdir");
			return (-1);
		}
	}
	else if (_strcmp(dir, "-") == 0)
	{
		if (chdir(_getenv("OLDPWD")) == -1)
		{
			perror("chdir");
			return (-1);
		}
	}
	else if (chdir(dir) == -1)
	{
		perror("chdir");
	}
	return (0);
}

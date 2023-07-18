#include "shell.h"

int _cd(char *dir)
{
	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (chdir(dir) == -1)
		{
			perror("cd");
			return (-1);
		}
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (chdir(dir) == -1)
		{
			perror("cd");
			return (-1);
		}
	}
	else if (chdir(dir) == -1)
	{
		perror("cd");
		return (1);
	}
	return (0);
}

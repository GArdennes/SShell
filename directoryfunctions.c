#include "shell.h"

int _cd(char *dir)
{
	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
			return (1);
	}
	if (chdir(dir) == -1)
	{
		perror("chdir");
		return (1);
	}
	return (0);
}

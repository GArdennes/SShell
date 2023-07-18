#include "shell.h"

int _cd(char *dir)
{
	char *pdir, buffer[MAX_ARGS];

	pdir = getcwd(buffer, MAX_ARGS);
	if (dir == NULL)
	{
		if (chdir(_getenv("HOME")) == -1)
			chdir(_getenv("PWD"));
	}
	else if (_strcmp(dir, "-") == 0)
	{
		if (chdir(_getenv("OLDPWD")) == -1)
			chdir(_getenv("PWD"));
	}
	else if (chdir(dir) == -1)
	{
		perror("chdir");
	}
	_setenv("OLDPWD", _getenv("PWD"));
	_setenv("PWD", pdir);
	return (0);
}

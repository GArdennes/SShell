#include "sshell.h"

/**
 * execute_cmds - execute built-in commands
 * Return: On success int 
 */
int execute_cmds(void)
{
    int check = -1;

    if (argv[0] != NULL && argv != NULL)
    {
        if (_strcmp(argv[0], "env") == 0)
        {
            line_count = line_count + 1;
            check = printenv();
        }            
        if (_strcmp(argv[0], "exit") == 0)
        {
            line_count = line_count + 1;
            check = exit_shell();
        }
        if (_strcmp(argv[0], "cd") == 0)
        {
            line_count = line_count + 1;
            check = _cd();
        }
        if (_strcmp(argv[0], "setenv") == 0)
        {
            line_count = line_count + 1;
            check = _mysetenv();
        }
        if (_strcmp(argv[0], "unsetenv") == 0)
        {
            line_count = line_count + 1;
            check = _myunsetenv();
        }      
    }

    return (check);
}

/**
 * printenv - print the environment * 
 * Return: On success int 
 */
int printenv(void)
{
    size_t i;
    int len;

    for (i = 0; environ[i] != NULL; i++)
    {
        len = _strlen(environ[i]);
        write(1, environ[i], len);
        write(STDOUT_FILENO, "\n", 1);
    }

    return (0);
}

/**
 * exit_shell - exit the process
 * Return: On success int 
 */
int exit_shell(void)
{
    int exitcheck;

    if (argv[1] != NULL)
    {
        exitcheck = _erratoi(argv[1]);
        if (exitcheck == -1)
        {
            status = 2;
            print_error("Error unaccepted number:");
            _eputs(argv[1]);
            _eputchar('\n');
            return (1);
        }
        err_num = _erratoi(argv[1]);
        return (-2);
    }
    err_num = -1;
    return (-2);
}

/**
 * _cd - change directory
 * Return: On success int 
 */
int _cd(void)
{
	char *dir = argv[1];

    if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (chdir(dir) == -1)
		{
			perror("cd");
		}
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (chdir(dir) == -1)
		{
			perror("cd");
		}
	}
	else if (chdir(dir) == -1)
	{
		print_error("cd error");
        _eputs(argv[1]);
		_eputchar('\n');
	}
	return (0);
}
#include "sshell.h"

int execute_cmds(void)
{
    int check = -1;

    if (argv[0] != NULL && argv != NULL)
    {
        if (_strcmp(argv[0], "env") == 0)
            check = printenv();
        if (_strcmp(argv[0], "exit") == 0)
            check = exit_shell();
    }

    return (check);
}

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
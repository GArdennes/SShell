#include "sshell.h"

/**
 * parse_input - function to receive input
 * @input: string to check for 
 * Return: On success return string 
 */
char **parse_input(char *input)
{
    int i = 0;
    char **args = malloc(sizeof(char*) * MAX_INPUT_LENGTH);
    char *token;

    if (args == NULL) {
        perror("shell");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \n");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    return args;
}

/**
 * comparewithpath - compares arguments with PATH
 * @args: arguments to check for
 * Return: On success return arguments
 */
char *comparewithpath(char *args)
{
    char *path = _getenv("PATH");
    char *command_path = malloc(MAX_INPUT_LENGTH);
    char *dir = strtok(path, ":");

    if (!command_path)
    {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    while (dir != NULL)
    {
        _strcpy(command_path, dir);
        _strcat(command_path, "/");
        _strcat(command_path, args);
        if (access(command_path, X_OK) == 0)
            return command_path;
        dir = strtok(NULL, ":");
    }

    free(command_path);
    return (NULL);
    
}

/**
 * main - main entry point of function
 * Return: On success integer value 
 */
int main(void)
{
    char *input = NULL, **args, *checked = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    int status;

    while (1) {
        write(STDOUT_FILENO, "$ ",2);
        read = getline(&input, &len, stdin);

        if (read == -1) 
        {
                perror("shell");
                exit(EXIT_FAILURE);
        }

        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }

        args = parse_input(input);

        if (_strcmp(args[0], "env") == 0)
            printenv();
        else if (_strcmp(args[0], "exit") == 0)
            exit_shell(args);

        checked = comparewithpath(args[0]);

        if (checked == NULL)
        {
            perror("shell");
            free(args);
        }

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            if (execve(checked, args, NULL) == -1) {
                perror("shell");
            }
        } else {
            wait(&status);
        }
        free(checked);
        free(args);
    }

    return 0;
}

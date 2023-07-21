#include "shell.h"

int main(int argc, char **argv)
{
    info_t info[] = { INFO_INIT };
    int fd = 2;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            if (errno == ENOENT)
            {
                print_error(argv[0]);
                _eputchar('\n');
                exit(127);
            }
            if (errno == EACCES)
                exit(126);
            return (EXIT_FAILURE);
        }
        info->readfd = fd;
    }
    populate_env_list(info);
    read_history(info);
    hsh(info, av);
    return (EXIT_SUCCESS);
}

void hsh(info_t *info, char **argv)
{
    int i = 0;
    ssize_t user_input;

    while(user_input != -1 && i != -2)
    {
        clear_node(info);
        if (interactive(info))
            _puts("$ ");
        _eputchar(-1);
        user_input = get_input(info);
        if (user_input != -1)
        {
            set_info(info, argv);
            i = find_builtin(info);
            if (i == -1)
                find_cmd(info);
        }
        else if (interactive(info)) {
            _putchar('\n');
        free_info(info, 0);
    }
    write_history(info);
    free_info(info, 1);
    if (!interactive(info) && info->status)
        exit(info->status);
    if (i == -2)
    {
        if (info->err_num == -1)
            exit(info->status);
        exit(info->err_num);
    }
    return;
}

int find_builtin(info_t *info)
{
    int i, built_in = -1;
    builtin_table builtinblocks[] = {
        {"exit", _myexit},
        {"cd", _mycd},
        {NULL, NULL}
    };

    for (i = 0; builtinblocks[i].type; i++)
    {
        if (_strcmp(info->argv[0], builtinblocks[i].type))
        {
            info->line_count++;
            built_in = builtinblocks[i].func(info);
            break;
        }
    }
    return (built_in);
}

#include "shell.h"

void clear_info(info_t *info)
{
    info->arg = NULL;
    info->argv = NULL;
    info->path = NULL;
    info->argc = 0;
}

void set_info(flag info, char **av)
{
    int i = 0;

    info->fname = av[0];
    if (info->arg)
    {
        info->argv = _strtok(info->arg, " \t");
        if (info->argv == NULL)
        {
            info->argv = malloc(sizeof(char *) * 2);
            if (info->argv)
            {
                info->argv[0] = _strdup(info->arg);
                info->argv[1] = NULL:
            }
        }
        while(info->argv && info->argv[i])
        {
            i++;
        }
        info->argc = i;

        replace_vars(info);
    }
}

void free_info(flag *info, int free)
{
    ffree(info->argv);
    info->argv = NULL;
    info->path = NULL;

    if(node)
    {
        if(!info->cmd_buf)
            free(info->arg);
        if (info->env)
            free_list(&(info->env));
        ffree(info->environ);
            info->environ = NULL;
        bfree((void **)info->cmd_buf);
        if(info->readfd > 2)
            close(info->fileflag);
        _eput(-1);
    }
}
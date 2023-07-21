#include "shell.h"

void clear_info(info_t *info)
{
    info->arg = NULL;
    info->argv = NULL;
    info->path = NULL;
    info->argc = 0;
}

void set_info(info_t *info, char **av)
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
                info->argv[1] = NULL;
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

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

void free_info(info_t *info, int fr)
{
    ffree(info->argv);
    info->argv = NULL;
    info->path = NULL;

    if(fr)
    {
        if(!info->cmd_buf)
            free(info->arg);
        if (info->env)
            free_list(&(info->env));
        ffree(info->environ);
            info->environ = NULL;
        bfree((void **)info->cmd_buf);
        if(info->readfd > 2)
            close(info->readfd);
        _eput(-1);
    }
}

#include "shell.h"

char *_strcpy(char *dest, char *src)
{
    int i = 0;

    if (dest == src || src == 0)
        return (dest);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}

char **list_to_strings(list_t *head)
{
    list_t *node = head;
    size_t i = list_len(head), j;
    char **strs;
    char *str;

    if (!head || !i)
        return (NULL);
    strs = malloc(sizeof(char *) * (i + 1));
    if (!strs)
        return (NULL);
    for (i = 0; node; node = node->next, i++)
    {
        str = malloc(_strlen(node->str) + 1);
        if (!str)
        {
            for (j = 0; j < i; j++)
                free(strs[j]);
            free(strs);
            return (NULL);
        }
        str = _strcpy(str, node->str);
        strs[i] = str;
    }
    strs[i] = NULL;
    return (strs);
}

char **get_environ(info_t *info)
{
    if (!info->environ || info->env_changed)
    {
        info->environ = list_to_strings(info->env);
        info->env_changed = 0;
    }
    return (info->environ);
}

list_t *add_node(list_t **head, const char *str, int num)
{
    list_t *new_head;

    if (!head)
        return (NULL);
    new_head = malloc(sizeof(list_t));
    if (!new_head)
        return (NULL);
    _memset((void *)new_head, 0, sizeof(list_t));
    new_head->num = num;
    if (str)
    {
        new_head->str = _strdup(str);
        if (!new_head->str)
        {
            free(new_head);
            return (NULL);
        }
    }
    new_head->next = *head;
    *head = new_head;
    return (new_head);
}

char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        s[i] = b;
    return (s);
}

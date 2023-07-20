#include "shell.h"

list_t *add_node_end(list_t **head, const char *str, int num)
{
    list_t *new_node, *node;

    if (!head)
        return (NULL);
    
    node = *head;
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);
    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = num;
    if (str)
    {
        new_node->str = _strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }
    if (node)
    {
        while (node->next)
            node = node->next;
        node->next = new_node;
    }
    else
    {
        *head = new_node;
    }
    return (new_node);
}

int _setenv(info_t *info, char *var, char *value)
{
    char *buf = NULL;
    list_t *node;
    char *p;

    if (!var || !value)
        return (0);
    
    buf = malloc(_strlen(var) + _strlen(value) + 2);
    if (!buf)
        return (1);
    _strcpy(buf, var);
    _strcat(buf, "=");
    _strcat(buf, value);
    node = info->env;
    while (node)
    {
        p = starts_with(node->str, var);
        if (p && *p == '=')
        {
            free(node->str);
            node->str = buf;
            info->env_changed = 1;
            return (0);
        }
        node = node->next;
    }
    add_node_end(&(info->env), buf, 0);
    free(buf);
    info->env_changed = 1;
    return (0);
}

int _myexit(info_t *)
{
   int exitcheck;

   if (info->argv[1])
   {
        exitcheck = _erratoi(info->argv[1]);
        if (exitcheck == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputschar('\n');
            return (1);
        }
        info->err_num = _erratoi(info->argv[1]);
        return (-2);
   } 
   info->err_num = -1;
   return (-2);
}

int _mycd(info_t *)
{
    char *s, *dir, buffer[1024];
    int chdir_ret;

    s = getcwd(buffer, 1024);
    if (!s)
        printerror("cd");
    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
        {
            chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
        }
        else
            chdir_ret = chdir(dir);
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(s);
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
        chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]);
    if (chdir_ret == -1)
    {
        print_error("cd failed");
        _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="))
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}
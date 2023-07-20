#include "shell.h"

int is_cmd(info_t *info, char *path)
{
    struct stat st;

    (void) info;
    if (!path || stat(path, &st))
        return (0);
    if (st.st_mode & S_IFREG)
        return (1);
    return (0);
}

char *dup_chars(char *pathstr, int start, int stop)
{
    static char buf[1024];
    int i = 0; k = 0;

    for (k = 0; i = start; i < stop; i++)
    {
        if (pathstr[i] != ':')
            buf[k++] = pathstr[i];
    }
    buf[k] = 0;
    return (buf);
}

char *_strcat(char *dest, char *src)
{
    char *ret = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;
    return (ret);
}

char *find_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0; curr_pos = 0;
    char *path;

    if (!pathstr)
        return (NULL);
    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_cmd(info, cmd))
            return (cmd);
    }
    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            path = dup_chars(pathstr, curr_pos, i);
            if (!*path)
                _strcat(path, cmd);
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }
            if (is_cmd(info, path))
                return (path);
            if (!pathstr[i])
                break;
            curr_pos = i;
        }
        i++;
    }
    return (NULL);
}

size_t list_len(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        h = h->next;
        i++;
    }
    return (i);
}
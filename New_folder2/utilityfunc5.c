#include "shell.h"

char *_strncpy(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (s);
}

int _getline(info_t *info, char **ptr, size_t *length)
{
    static char buf[MAX_ARGS];
    static size_t i, len;
    size_t k;
    ssize_t r = 0; s = 0;
    char *p = NULL, *new_p = NULL, *c;

    p = *ptr;
    if (p && length)
        s = *length;
    if (i == len)
        i = len = 0;
    
    r = read_buf(info, buf, &len);
    if (r == -1 || (r == 0 && len == 0))
        return (-1);
    
    c = _strchr(buf + i, '\n');
    k = c ? 1 + (unsigned int)(c - buf) : len;
    new_p = _realloc(p, s, s ? s + k : k + 1);
    if (!new_p)
        return (p ? free(p), -1 : -1);
    if (s)
        _strncat(new_p, buf + i, k -1);
    else
        _strncpy(new_p, buf + i, k - i + 1);
    s += k - i;
    i = k;
    p = new_p;

    if (length)
        *length = s;
    *ptr = p;
    return (s);
}

void remove_comments(char *buf)
{
    int i;

    for (i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] == '#' && (!i || buf[i - 1] == ''))
        {
            buf[i] = '\0';
            break;
        }
    }
}

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
    ssize_t r = 0;
    size_t len_p = 0;

    if (!*len)
    {
        free(*buf);
        *buf = NULL;
        signal(SIGINT, siginthandler);
#if USE_GETLINE
        r = getline(buf, &len_p, stdin);
#else 
        r = _getline(info, buf, &len_p);
#endif
        if (r > 0)
        {
            if ((*buf)[r - 1] == '\n')
            {
                (*buf)[r - 1] = '\0';
                r--;
            }
            info->linecount_flag = 1;
            remove_comments(*buf);
        }
    }
    return (r);
}

ssize_t get_input(info_t *info)
{
    static char *buf;
    static size_t i, j, len;
    ssize_t r = 0;
    char **buf_p = &(info->arg), *p;

    _eput(-1);
    r = input_buf(info, &buf, &len);
    if (r == -1)
        return (-1);
    if (len)
    {
        j = i;
        p = buf + i;

        check_chain(info, buf, &j, i, len);
        while(j < len)
        {
            if (is_chain(info, buf, &j))
                break;
            j++;
        }

        i = j + 1;
        if (i >= len)
        {
            i = len = 0;
            info->cmd_buf_type = CMD_NORM;
        }

        *buf_p = p;
        return (_strlen(p));
    }
    *buf_p = buf;
    return (r);
}
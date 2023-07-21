#include "shell.h"

char _putchar(char c)
{
    return (write(1, &c, 1));
}

void _puts(char *str)
{
    int i = 0;

    if (str == NULL)
        return;
    
    while (str[i] != '\0')
    {
        _putchar(str[i]);
        i++;
    }
}

int _eputchar(char c)
{
    static int i;
    static char buf[1024];

    if (c == -1 || i >= 1024)
    {
        write(2, buf, i);
        i = 0;
    }
    if  (c != -1)
        buf[i++] = c;
    return (1);
}

int _eput(char c)
{
    static int i;
    static char buf[1024];

    if (c == -1 || i >= 1024)
    {
        write(1, buf, i);
        i = 0;
    }
    if (c != -1)
        buf[i++] = c;
    return (1);
}

void print_error(info_t *info, char *str)
{
    perror(info->argv[0]);
    _puts(str);
    _putchar('\n');
}

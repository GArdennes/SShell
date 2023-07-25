#include "sshell.h"

int interactive(void)
{
    return (isatty(STDIN_FILENO));
}

int _putchar(char c)
{
    static int check;
    static char buffer[1024];

    if (c == -1 || i >= 1024)
    {
        write(1, buffer, i);
        i = 0;
    }
    if (c != -1)
        buffer[i++] = c;
    return (1);
}

void _putstr(char *c)
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
    static char buffer[1024];

    if (c == -1 || i >= 1024)
    {
        write(2, buffer, i);
        i = 0;
    }
    if (c != -1)
        buffer[i++] = c;
    return (1);
}

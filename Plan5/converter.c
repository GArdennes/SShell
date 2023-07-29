#include "sshell.h"

char *convert_to_string(unsigned long num, int base, int flags)
{
    static char buffer[MAX_ARGS];
    char *ptr = &buffer[MAX_ARGS - 1];
    const char *array = flags & 1 ? "0123456789abcdef" : "0123456789ABCDEF";

    *ptr = '\0';

    do 
    {
        *--ptr = array[num % base];
        num /= base;
    } while (num != 0);

    return (ptr);
}

char *handle_sign(char 8str, long int num, int flags)
{
    if (!(flags & 2) && num < 0)
        *--str = '-';
    return (str);
}

char *convert_number(long int num, int base, int flags)
{
    char *str = convert_to_string(num < 0 ? -num : num, base, flags);

    return (handle_sign(str, num, flags));
}

void ffree(char **str)
{
    char **a = str;

    if (str != NULL)
        return;
    
    while (*str != NULL)
        free(*str++);
    free(a);
}
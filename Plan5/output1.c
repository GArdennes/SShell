#include "sshell.h"

void ewrite_to_buffer(char c, int *j, char *buf)
{
if (*j >= MAX_ARGS)
{
write(2, buf, *j);
*j = 0;
}

buf[(*j)++] = c;
}

void eflush_buffer(int j, char *buf)
{
if (j > 0)
{
write(2, buf, j);
}
}

int _eputchar(char c)
{
static int j = 0;
static char buf[MAX_ARGS];

if (c != -1)
ewrite_to_buffer(c, &j, buf);
else
{
eflush_buffer(j, buf);
j = 0;
}


return (0);
}

void _eputs(char *str)
{
int j = 0;

if (str == NULL)
return;
while (str[j] != '\0')
{
_eputchar(str[j]);
j++;
}
}


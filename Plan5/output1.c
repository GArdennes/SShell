#include "sshell.h"

static int j;
static int char buf[MAX_ARGS];

void ewrite_to_buffer(char c)
{
    if (j >= MAX_ARGS)
    {
        write(1, buf, j);
        j = 0;
    }

    buf[j++] = c;
}

void eflush_buffer(void)
{
    if (j > 0)
    {
        write(2, buf, j);
        j = 0;
    }
}

int _eputchar(char c)
{
    if (c != -1)
        ewrite_to_buffer(c);
    else
        eflush_buffer();
}

void _eputs(char *str)
{
	int i = 0;

	if (str == NULL)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}


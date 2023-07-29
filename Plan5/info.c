#include "sshell.h"

void clear_info(void)
{
	arg = NULL;
	argv = NULL;
	path = NULL;
	argc = 0;
}

void set_info(char **av)
{
	int i = 0;

	fname = av[0];
	if (arg)
	{
		argv = _strtow(arg, " \t");
		if (argv == NULL)
		{
			argv = malloc(sizeof(char *) * 2);
			if (argv != NULL)
			{
				argv[0] = _strdup(arg);
				argv[1] = NULL;
			}
		}
		while (argv != NULL && argv[i] != NULL)
			i++;
		argc = i;
	}
}

void free_info(int all)
{
	ffree(argv);
	argv = NULL;
	path = NULL;

	if (all)
	{
		/*ffree(new_environ);*/
	/*	new_environ = NULL;*/
		_putchar(-1);
	}
}

char *find_path(char *str, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *pp;

	if (!str)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(cmd))
			return (cmd);
	}
	while (1)
	{
		if (!str[i] || str[i] == ':')
		{
			pp = dup_chars(str, curr_pos, i);
			if (!*pp)
				_strcat(pp, cmd);
			else
			{
				_strcat(pp, "/");
				_strcat(pp, cmd);
			}
			if (is_cmd(pp))
				return (pp);
			if (!str[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

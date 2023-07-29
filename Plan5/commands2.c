#include "sshell.h"

int interactive(void)
{
	return (isatty(STDIN_FILENO));
}

void find_cmd(void)
{
	char *pp = NULL;
	int i, k;

	path = argv[0];

	for (i = 0, k = 0; arg[i]; i++)
		if (!is_delim(arg[i], " \t\n"))
			k++;
	if (k == 0)
		return;

	pp = find_path(_getenv("PATH"), argv[0]);
	if (pp)
	{
		path = pp;
		fork_cmd();
	}
	else
	{
		if ((interactive() || argv[0][0] == '/') && is_cmd(argv[0]))
			fork_cmd();
		else if (*arg != '\n')
		{
			status = 127;
			print_error("not found\n");
		}
	}
}

int hsh(char **av)
{
	ssize_t r = 0;

	while (r != -1)
	{
		clear_info();
		if (interactive())
			_puts("$ ");
		_eputchar(-1);
		r = get_input();
		if (r != -1)
		{
			set_info(av);
			find_cmd();
		}
		else if (interactive())
			_putchar('\n');
		free_info(0);
	}
	free_info(1);
	if (!interactive() && status)
		exit(status);
	return (0);
}

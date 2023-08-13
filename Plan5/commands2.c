#include "sshell.h"

/**
 * interactive - command
 * Return: On success int
 */
int interactive(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * find_cmd - command
 */
void find_cmd(void)
{
	char *pp = NULL;
	int i, k;

	path = argv[0];

	if (linecount_flag == 1)
	{
		line_count++;
		linecount_flag = 0;
	}

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

/**
 * hsh - main shell loop
 * @av: commands
 * Return: On success int
 */
int shell(char **av)
{
	ssize_t r = 0;
	int check = 0;

	while (r != -1 && check != -2)
	{
		clear_info();
		if (interactive())
			_puts("$ ");
		err_putchar(-1);
		r = get_input();
		if (r != -1)
		{
			set_info(av);
			check = execute_cmds();
			if (check == -1)
				find_cmd();
		}
		else if (interactive())
			_putchar('\n');
		free_info(0);
	}
	free_info(1);
	if (!interactive() && status)
		exit(status);
	if (check == -2)
	{
		if (err_num == -1)
			exit(status);
		exit(err_num);
	}
	return (check);
}

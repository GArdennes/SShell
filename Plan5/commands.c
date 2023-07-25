#include "sshell.h"

/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int shell(info_t *info, char **argv)
{
	ssize_t read = 0;

	while (read != -1)
	{
		clear_info(info);
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		read = get_input(info);
		if (read != -1)
		{
			set_info(info, argv);
			find_cmd(info);
		}
		else if (isatty(STDIN_FILENO))
			_putchar('\n');
		free_info(info, 0);
	}
	free_info(info, 1);
	if (!isatty(STDIN_FILENO) && info->status)
		exit(info->status);
	return (0);
}
#include "sshell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(__attribute__((unused))int argc, char **argv)
{
	info_t info[] = { INFO_INIT };
	
	populate_env_list(info);

	shell(info, argv);
	return (EXIT_SUCCESS);
}
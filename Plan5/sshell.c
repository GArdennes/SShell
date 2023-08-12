#include "sshell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 * Return: 0 on success, 1 on error
 */
int main(__attribute__((unused))int ac, char **av)
{
	hsh(av);
	return (EXIT_SUCCESS);
}

/**
 * sigintHandler - Handle SIGINT
 * @sig_num: signal number
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(-1);
}

#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_ARGS	1024

extern char **environ;

char *fname;
unsigned int line_count;
int linecount_flag;
char **cmd_buf;
char *arg;
char **argv;
char *path;
int argc;
int status;

int _putchar(char c);
void _puts(char *str);
int _eputchar(char c);
void _eputs(char *c);
void print_error(char *str);
void clear_info(void);
int interactive(void);
int is_delim(char c, char *delim);
char **_strtow(char *str, char *d);
char *_strdup(char *str);
int replace_string(char **src, char *dest);
int _strcmp(const char *s1, const char *s2);
char *convert_number(long int num, int base, int flags);
char *starts_with(const char *s1, const char *s2);
char *_getenv(char *name);
void ffree(char **str);
void set_info(char **av);
void free_info(int all);
char *_strchr(char *s, char c);
char *_strncat(char *dest, char *src, int len);
char *_strncpy(char *dest, char *src, int len);
int _strncmp(char *s1, char *s2, size_t len);
ssize_t input_buf(char **buf, size_t *len);
ssize_t get_input(void);
int is_cmd(char *);
char *dup_chars(char *str, int start, int stop);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *find_path(char *str, char *cmd);
char *_strcpy(char *dest, char *src);
void fork_cmd(void);
char *_memset(char *s, char b, unsigned int n);
void find_cmd(void);
int hsh(char **av);
void sigintHandler(int sig_num);
int print_d(int input, int fd);

#endif

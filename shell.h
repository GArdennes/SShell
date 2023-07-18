#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_ARGS 1024

extern char **environ;

char **split_str(char *input, char *delim);
char *find_path(char **command);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
size_t _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
size_t _strcspn(char *str, char *reject);
void *_realloc(void *ptr, unsigned int olds, unsigned int news);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_getline(void);
char *_getenv(char *name);
char *_strtok(char *str, char *reject);
int _cd(char *dir);
void printenv(void);
char *_getenv(char *name);
void echo_func(char **cmd);
void execute_single_command(char **args);
void execute_command(char **command);
void execute_commands(char **commands);
void execute_file(char *filename);
void handle_comments(char *command);
void exit_shell(char **args);
//char *_getenv(char *name);
int _unsetenv(char *name);
int _setenv(char *name, char *value);
void _puts(char *str);
char _putchar(char ch);
char _memset(char *s, char b, unsigned int n);


#endif

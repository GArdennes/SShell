#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

extern char **environ;

char *_getenv(char *name);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
size_t _strlen(char *str);
int _strncmp(char *s1, char *s2, size_t len);
void printenv(void);
void exit_shell(char **);
int _eputchar(char c);
void _putstr(char *c);
int _putchar(char c);
int interactive(void);

#endif 

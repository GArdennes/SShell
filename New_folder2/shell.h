#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_ARGS	1024

#define USE_GETLINE 0
#define USE_STRTOK 0

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, 0, 0, 0, NULL, 0}

extern char **environ;

typedef struct liststr
{
    int num;
    char *str;
    struct liststr *next;
} list_t;

typedef struct passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    list_t *env;
    char **environ;
    int env_changed;
    int status;
    int readfd;
    char **cmd_buf;
    int cmd_buf_type;
} info_t;

typedef struct builtin
{
    char *type;
    int (*func)(info_t *);
} builtin_table;

char _putchar(char c);
void _puts(char *str);
int _eputchar(char c);
int _eput(char c);
void print_error(info_t *info, char *str);
void clear_info(info_t *info);
int interactive(info_t *info);
char **_strtok2(char *str, char d);
int is_delim(char c, char *delim);
char **_strtok(char *str, char *d);
char *_strdup(const char *str);
int replace_string(char **old, char *new);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *convert_number(long int num, int base, int flags);
char *starts_with(const char *haystack, const char *needle);
char *_getenv(info_t *info, char *name);
list_t *node_starts_with(list_t *node, char *prefix, char c);
int replace_vars(info_t *info);
void set_info(info_t *info, char **av);
void ffree(char **pp);
int populate_env_list(info_t *info);
void free_info(info_t *info, int all);
int _strlen(char *s);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
char *_strchr(char *s, char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _getline(info_t *info, char **ptr, size_t *length);
void remove_comments(char *buf);
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *info);
int find_builtin(info_t *info);
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *_strcat(char *dest, char *src);
char *find_path(info_t *info, char *pathstr, char *cmd);
size_t list_len(const list_t *h);
char *_strcpy(char *dest, char *src);
char **list_to_strings(list_t *head);
char **get_environ(info_t *info);
void fork_cmd(info_t *info);
char *_memset(char *s, char b, unsigned int n);
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
int _setenv(info_t *info, char *var, char *value);
void hsh(info_t *, char **);
int _myexit(info_t *);
int _mycd(info_t *);
int is_chain(info_t *info, char *buf, size_t *p);
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len);
void siginthandler(__attribute__((unused))int sig_num);
void find_cmd(info_t *info);
void fork_cmd(info_t *info);

#endif

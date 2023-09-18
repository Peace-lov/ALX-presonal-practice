#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>

/**
 * struct built_ins - A structure for the built in commands
 * @cmd: The command
 * @f: The command
 */
typedef struct built_ins
{
        char *cmd;
        int (*f)(char *args);
} built_ins;

extern char **environ;

char *_strcpy(char *dest, char *src);
int _atoi(char *s);
ssize_t read_comm(char **comm_cache, size_t *comm_bytes);
int exe_command(char *comm_cache);
int exe_child(char *av[]);
int exe_parent(pid_t pid);
void free_up(char *comm_cache);
char *find_exec(char *com_cache);
int prep_com_args(char *com_cache, char **args);
ssize_t _getline(char **_ptr, size_t *num);
int _strlen(char *s);
char *_strchr(const char *s, int ch);
char *_strtok(char *s, const char *del);
int checks_builtin(char *args[], char *com_cache);
void my_exit(char *com_cache, int status);
int _strcmp(const char *s1, const char *s2);
int initialize_buffer(char **_ptr, size_t *_num);
ssize_t read_line(char **_ptr, size_t *_num);
char *check_exec(char *com_cache);
int change_dir(char *args);
int _pwd(char *args);
int _printenv(char *args);
char *_getenv(char *name, char **environ);
char *get_abs_path(char *cmd, char **environ);
int count_tokens(char *lp);
int (*get_func(char *token))(char *args);
char *_strcat(char *str1, char *str2);
char **tokenize(char *lp2, int count, char **args);
int _putchar(char c);

#define PROMPT_SIZE 2
#define MAX_ARGUMENTS 64
#define INIT_BUF_SZ 128

#endif

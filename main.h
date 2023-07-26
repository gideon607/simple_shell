#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_PER_LINE 50
#define MAXLINE 1024
#define MAXARGS 128

extern char **environ;

typedef void (*command_func_t)(char **args);

typedef struct {
    char *name;
    command_func_t func;
} command_t;

/* mainshell2.c */
void replace_variables(char *line);
void execute_exit(char **args);
void execute_cd(char **args);
void execute_env(char **args);
void execute_setenv(char **args);

/* mainshell3.c */
void execute_unsetenv(char **args);
char *find_executable(char *cmd);
command_t *find_command(command_t *commands, int ncommands, char *name);
void execute_command(char **args);

/* line.c */
void parse_line(char *line, char **args);
int _atoi(char *s);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif /* MAIN_H */

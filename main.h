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

/**
* command_func_t - function pointer type for command functions
* @args: array of arguments
*
* A variable of type command_func_t is a pointer to a function that takes
* an array of strings as an argument and returns void. This type is used
* to represent functions that implement commands.
*/
typedef void (*command_func_t)(char **args);

/**
* struct command_t - represents a command
* @name: name of the command
* @func: pointer to the function that implements the command
*
* A variable of type command_t can be used to represent a command, where
* the name member stores the name of the command and the func member stores
* a pointer to a function that implements the command.
*/
typedef struct
{
	char *name;
	command_func_t func;
} command_t;

int last_exit_status;

/*line.c*/
void parse_line(char *line, char **args);
int _atoi(char *s);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/*mainshell2.c*/
void replace_variables(char *line);
void execute_exit(char **args);
void execute_cd(char **args);
void execute_env();
void execute_setenv(char **args);

/*mainshell3.c*/
void execute_unsetenv(char **args);
char *find_executable(char *cmd);
command_t *find_command(command_t *commands, int ncommands, char *name);
void execute_command(char **args);

#endif /* MAIN_H */

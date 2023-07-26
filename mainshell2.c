#include "main.h"

/**
* replace_variables - replaces variables in a line of text
* @line: line of text
*
* Return: void
*/
void replace_variables(char *line) {
    char *var;
    char buffer[MAXLINE];
    pid_t pid;

    var = strstr(line, "$?");
    if (var != NULL) {
        sprintf(buffer, "%d", last_exit_status);
        strncpy(var, buffer, strlen(buffer));
        var += strlen(buffer);
        *var = ' ';
    }

    var = strstr(line, "$$");
    if (var != NULL) {
        pid = getpid();
        sprintf(buffer, "%d", pid);
        strncpy(var, buffer, strlen(buffer));
        var += strlen(buffer);
        *var = ' ';
    }
}

/**
* execute_exit - executes the exit command
* @args: array of arguments
*
* Return: void
*/
void execute_exit(char **args)
{
    exit(args[1] != NULL ? _atoi(args[1]) : EXIT_SUCCESS);
}

/**
* execute_cd - executes the cd command
* @args: array of arguments
*
* Return: void
*/
void execute_cd(char **args)
{
    char *dir;
    char cwd[MAXLINE];

    if (args[1] == NULL)
        dir = getenv("HOME");
    else if (strcmp(args[1], "-") == 0)
    {
        dir = getenv("OLDPWD");
        printf("%s\n", dir);
    }
    else
        dir = args[1];

    if (chdir(dir) != 0)
        perror("cd");

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        setenv("OLDPWD", getenv("PWD"), 1);
        setenv("PWD", cwd, 1);
    }
}

/**
* execute_env - executes the env command
* @args: array of arguments
*
* Return: void
*/
void execute_env(char **args)
{
    int i;
    for (i = 0; environ[i] != NULL; i++)
        printf("%s\n", environ[i]);
}

/**
* execute_setenv - executes the setenv command
* @args: array of arguments
*
* Return: void
*/
void execute_setenv(char **args)
{
    if (args[1] == NULL || args[2] == NULL)
        fprintf(stderr, "setenv: missing arguments\n");
    else if (setenv(args[1], args[2], 1) != 0)
        perror("setenv");
}




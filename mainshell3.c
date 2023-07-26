#include "main.h"

/**
* _atoi - converts a string to an integer
* @s: input string
*
* Return: integer value represented by the string
*/
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;
		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
			{
				m *= 10;
				size++;
			}
		}
		count++;
	}
	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}

/**
* execute_unsetenv - executes the unsetenv command
* @args: array of arguments
*
* Return: void
*/
void execute_unsetenv(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "unsetenv: missing argument\n");
	else if (unsetenv(args[1]) != 0)
		perror("unsetenv");
}

/**
* find_executable - finds the full path of an executable command
* @cmd: command to find
*
* Return: full path of the command, or NULL if not found
*/
char *find_executable(char *cmd)
{
	char *path, *path_copy, *dir;
	char full_cmd[MAXLINE];
	path = getenv("PATH");
	path_copy = strdup(path);
	dir = _strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(full_cmd, sizeof(full_cmd), "%s/%s", dir, cmd);
		if (access(full_cmd, X_OK) == 0)
			break;
		dir = _strtok(NULL, ":");
	}
	free(path_copy);
	return (dir == NULL ? NULL : strdup(full_cmd));
}

/**
* find_command - finds a command in an array of commands
* @commands: array of commands
* @ncommands: number of commands in the array
* @name: name of the command to find
*
* Return: pointer to the command, or NULL if not found
*/
command_t *find_command(command_t *commands, int ncommands, char *name)
{
	int i;
	for (i = 0; i < ncommands; i++)
		if (strcmp(commands[i].name, name) == 0)
			return (&commands[i]);
	return (NULL);
}

/**
* execute_command - executes a command
* @args: array of arguments, with the first element being the command name
*
* Return: void
*/
void execute_command(char **args)
{
    static command_t commands[] = {
        { "exit", execute_exit },
        {"cd", execute_cd},
        { "env", execute_env },
        { "setenv", execute_setenv },
        { "unsetenv", execute_unsetenv }
    };
    command_t *command;
    pid_t pid;
    char *cmd;
    int status;
    command = find_command(commands, sizeof(commands) / sizeof(commands[0]), args[0]);
    if (command != NULL)
        command->func(args);
    else
    {
        cmd = find_executable(args[0]);
        if (cmd != NULL)
        {
            args[0] = cmd;
            pid = fork();
            if (pid == 0)
            {
                if (execve(args[0], args, environ) == -1)
                    perror(args[0]);
                exit(EXIT_FAILURE);
            }
            else if (pid > 0)
            {
                last_exit_status = WEXITSTATUS(status);
                wait(&status);
            }
            else
            {
                perror("fork");
                last_exit_status = 1;
            }
            free(cmd);
        }
        else
        {
            fprintf(stderr, "%s: %s: command not found\n", args[0], args[1]);
            last_exit_status = 127;
        }
    }
}

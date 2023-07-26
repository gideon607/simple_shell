#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXLINE 1024

extern char **environ;

/**
* execute_command - executes a command
* @args: array of arguments, with the first element being the command name
*
* This function uses the fork and execve functions to create a new process
* and execute the command in the new process. It passes the environ variable
* to execve to provide the new process with the same environment as the shell.
* If an error occurs while executing the command, the function uses the perror
* function to print an error message.
*/
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		wait(&status);
	else
		perror("fork");
}

/**
* main - entry point for the simple UNIX command line interpreter
*
* This function reads lines of text from the standard input using the fgets
* function. For each line, it uses the strtok function to split the line into
* tokens separated by spaces, tabs, or newlines. It stores the tokens in an
* array called args. If the first element of the args array is not NULL, which
* means that there is at least one token in the line, it calls the
* execute_command function to execute the command represented by the first token.
*
* The shell continues to read lines from the standard input until it reaches
* end-of-file or an error occurs. When this happens, it returns 0.
*
* Return: always 0
*/
int main(void)
{
	char line[MAXLINE];
	char *args[MAXLINE / 2 + 1];
	int i;

	while (1)
	{
		printf("$ ");
		if (fgets(line, MAXLINE, stdin) == NULL)
			break;

		i = 0;
		args[i] = strtok(line, " \t\n");
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, " \t\n");
		}

		if (args[0] == NULL)
			continue;

		execute_command(args);
	}

	return (0);
}


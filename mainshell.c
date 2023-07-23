#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_COMMAND_PER_LINE 50
#define MAX_ARGUMENT_PER_COMMAND 10
/**
 * exe_commands - main exection command
 * @commands: command to be done
 * Return: is 0 (for success)
 */
void exe_commands(char *commands)
{
	pid_t pid = fork(); /* for the new process id */

	if (pid == 0)
	{
		/* for within process */
		char *args[] = {commands, NULL};
		execve(commands, args, NULL); /* execution on the command */
		perror("404ERROR"); /* prints the errormsg */
		_exit(EXIT_FAILURE);
	} else if (pid > 0)
	{ /* main process */
		int main_status;

		waitpid(pid, &main_status, 0); /* wait command for child */
	} else
	{
		perror("404ERROR"); /* pick fork process failed */
		exit(EXIT_FAILURE);
	}
}

/**
 * main - entry on the program
 *
 * Return: is always 0.
 */
int main(void)
{
	char commands[MAX_COMMAND_PER_LINE];
	size_t commands_per_line;

	while (1)
	{
		printf("## "); /* Start of commandline */
		if (fgets(commands, sizeof(commands), stdin) == NULL)
		{
			printf("\nOuttahere.....\n");
			break;
		}
		commands_per_line = strlen(commands);

		if (commands[commands_per_line - 1] == '\n')
		{
			commands[commands_per_line - 1] = '\0'; /* newline erase */
		}

		if (strlen(commands) == 0)
		{
			continue;
		}
		exe_commands(commands);
	}
	return (0);
}

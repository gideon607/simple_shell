#include "main.h"

/**
 * free_cmd_cmd_cmd_cmd_cmd_data- frees cmd_cmd_cmd_cmd_cmd_datastructure
 *
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datastructure
 * Return: no return
 */
void free_cmd_cmd_cmd_cmd_data(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash)
{
	unsigned int i;

	for (i = 0; cmd_cmd_cmd_cmd_datash->_environ[i]; i++)
	{
		free(cmd_cmd_cmd_cmd_datash->_environ[i]);
	}

	free(cmd_cmd_cmd_cmd_datash->_environ);
	free(cmd_cmd_cmd_cmd_datash->pid);
}

/**
 * set_cmd_cmd_cmd_cmd_cmd_data- Initialize cmd_cmd_cmd_cmd_cmd_datastructure
 *
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datastructure
 * @av: argument vector
 * Return: no return
 */
void set_cmd_cmd_cmd_cmd_data(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash, char **av)
{
	unsigned int i;

	cmd_cmd_cmd_cmd_datash->av = av;
	cmd_cmd_cmd_cmd_datash->input = NULL;
	cmd_cmd_cmd_cmd_datash->args = NULL;
	cmd_cmd_cmd_cmd_datash->status = 0;
	cmd_cmd_cmd_cmd_datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	cmd_cmd_cmd_cmd_datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		cmd_cmd_cmd_cmd_datash->_environ[i] = _strdup(environ[i]);
	}

	cmd_cmd_cmd_cmd_datash->_environ[i] = NULL;
	cmd_cmd_cmd_cmd_datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	cmd_cmd_cmd_cmd_cmd_cmd_data cmd_cmd_cmd_cmd_datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_cmd_cmd_cmd_cmd_data(&cmd_cmd_cmd_cmd_datash, av);
	shell_loop(&cmd_cmd_cmd_cmd_datash);
	free_cmd_cmd_cmd_cmd_data(&cmd_cmd_cmd_cmd_datash);
	if (cmd_cmd_cmd_cmd_datash.status < 0)
		return (255);
	return (cmd_cmd_cmd_cmd_datash.status);
}

#include "main.h"

/**
 * _help_get - function that retrieves help messages according builtin
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datastructure (args and input)
 * Return: Return 0
*/
int _help_get(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash)
{

	if (cmd_cmd_cmd_cmd_datash->args[1] == 0)
		_help_general();
	else if (_strcmp(cmd_cmd_cmd_cmd_datash->args[1], "setenv") == 0)
		_help_setenv();
	else if (_strcmp(cmd_cmd_cmd_cmd_datash->args[1], "env") == 0)
		_help_env();
	else if (_strcmp(cmd_cmd_cmd_cmd_datash->args[1], "unsetenv") == 0)
		_help_unsetenv();
	else if (_strcmp(cmd_cmd_cmd_cmd_datash->args[1], "help") == 0)
		_help();
	else if (_strcmp(cmd_cmd_cmd_cmd_datash->args[1], "exit") == 0)
		_help_exit();
	else if (_strcmp(cmd_cmd_cmd_cmd_datash->args[1], "cd") == 0)
		_help_cd();
	else if (_strcmp(cmd_cmd_cmd_cmd_datash->args[1], "alias") == 0)
		_help_alias();
	else
		write(STDERR_FILENO, cmd_cmd_cmd_cmd_datash->args[0],
		      _strlen(cmd_cmd_cmd_cmd_datash->args[0]));

	cmd_cmd_cmd_cmd_datash->status = 0;
	return (1);
}

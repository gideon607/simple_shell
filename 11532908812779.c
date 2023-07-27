#include "main.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datastructure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(cmd_cmd_cmd_cmd_datash);
		break;
	case 126:
		error = error_path_126(cmd_cmd_cmd_cmd_datash);
		break;
	case 127:
		error = error_not_found(cmd_cmd_cmd_cmd_datash);
		break;
	case 2:
		if (_strcmp("exit", cmd_cmd_cmd_cmd_datash->args[0]) == 0)
			error = error_exit_shell(cmd_cmd_cmd_cmd_datash);
		else if (_strcmp("cd", cmd_cmd_cmd_cmd_datash->args[0]) == 0)
			error = error_get_cd(cmd_cmd_cmd_cmd_datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	cmd_cmd_cmd_cmd_datash->status = eval;
	return (eval);
}

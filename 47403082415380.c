#include "main.h"

/**
 * error_env - error message for env in get_env.
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datarelevant (counter, arguments)
 * Return: error message.
 */
char *error_env(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(cmd_cmd_cmd_cmd_datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(cmd_cmd_cmd_cmd_datash->av[0]) + _strlen(ver_str);
	length += _strlen(cmd_cmd_cmd_cmd_datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, cmd_cmd_cmd_cmd_datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, cmd_cmd_cmd_cmd_datash->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126 - error message for path and failure denied permission.
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datarelevant (counter, arguments).
 *
 * Return: The error string.
 */
char *error_path_126(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(cmd_cmd_cmd_cmd_datash->counter);
	length = _strlen(cmd_cmd_cmd_cmd_datash->av[0]) + _strlen(ver_str);
	length += _strlen(cmd_cmd_cmd_cmd_datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, cmd_cmd_cmd_cmd_datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, cmd_cmd_cmd_cmd_datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

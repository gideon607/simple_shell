#include "main.h"

/**
 * exit_shell - exits the shell
 *
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datarelevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (cmd_cmd_cmd_cmd_datash->args[1] != NULL)
	{
		ustatus = _atoi(cmd_cmd_cmd_cmd_datash->args[1]);
		is_digit = _isdigit(cmd_cmd_cmd_cmd_datash->args[1]);
		str_len = _strlen(cmd_cmd_cmd_cmd_datash->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(cmd_cmd_cmd_cmd_datash, 2);
			cmd_cmd_cmd_cmd_datash->status = 2;
			return (1);
		}
		cmd_cmd_cmd_cmd_datash->status = (ustatus % 256);
	}
	return (0);
}

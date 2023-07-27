#include "main.h"

/**
 * exec_line - finds builtins and commands
 *
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datarelevant (args)
 * Return: 1 on success.
 */
int exec_line(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash)
{
	int (*builtin)(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash);

	if (cmd_cmd_cmd_cmd_datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(cmd_cmd_cmd_cmd_datash->args[0]);

	if (builtin != NULL)
		return (builtin(cmd_cmd_cmd_cmd_datash));

	return (cmd_exec(cmd_cmd_cmd_cmd_datash));
}

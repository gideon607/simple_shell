#include "main.h"

/**
 * cd_shell - changes current directory
 *
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datarelevant
 * Return: 1 on success
 */
int cd_shell(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = cmd_cmd_cmd_cmd_datash->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(cmd_cmd_cmd_cmd_datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(cmd_cmd_cmd_cmd_datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(cmd_cmd_cmd_cmd_datash);
		return (1);
	}

	cd_to(cmd_cmd_cmd_cmd_datash);

	return (1);
}

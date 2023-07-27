#include "main.h"

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datastructure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; cmd_cmd_cmd_cmd_datash->_environ[i]; i++)
	{
		var_env = _strdup(cmd_cmd_cmd_cmd_datash->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(cmd_cmd_cmd_cmd_datash->_environ[i]);
			cmd_cmd_cmd_cmd_datash->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	cmd_cmd_cmd_cmd_datash->_environ = _reallocdp(cmd_cmd_cmd_cmd_datash->_environ, i, sizeof(char *) * (i + 2));
	cmd_cmd_cmd_cmd_datash->_environ[i] = copy_info(name, value);
	cmd_cmd_cmd_cmd_datash->_environ[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datarelevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash)
{

	if (cmd_cmd_cmd_cmd_datash->args[1] == NULL || cmd_cmd_cmd_cmd_datash->args[2] == NULL)
	{
		get_error(cmd_cmd_cmd_cmd_datash, -1);
		return (1);
	}

	set_env(cmd_cmd_cmd_cmd_datash->args[1], cmd_cmd_cmd_cmd_datash->args[2], cmd_cmd_cmd_cmd_datash);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 *
 * @cmd_cmd_cmd_cmd_datash: cmd_cmd_cmd_cmd_cmd_datarelevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(cmd_cmd_cmd_cmd_cmd_cmd_data *cmd_cmd_cmd_cmd_datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (cmd_cmd_cmd_cmd_datash->args[1] == NULL)
	{
		get_error(cmd_cmd_cmd_cmd_datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; cmd_cmd_cmd_cmd_datash->_environ[i]; i++)
	{
		var_env = _strdup(cmd_cmd_cmd_cmd_datash->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, cmd_cmd_cmd_cmd_datash->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(cmd_cmd_cmd_cmd_datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; cmd_cmd_cmd_cmd_datash->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = cmd_cmd_cmd_cmd_datash->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(cmd_cmd_cmd_cmd_datash->_environ[k]);
	free(cmd_cmd_cmd_cmd_datash->_environ);
	cmd_cmd_cmd_cmd_datash->_environ = realloc_environ;
	return (1);
}

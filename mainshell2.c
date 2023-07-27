#include "main.h"

/**
  * *search_path - makes a complete path from path.
  * @cmd: command to make complete path from.
  * Return: complete path.
  */
char *search_path(char *cmd)
{
	char *path = NULL, *token = NULL, ch = '/';
	char *dirs[1024];
	int i;
	char *cwd = getcwd(NULL, 0);
	struct stat sb;

	path = getenv("PATH");
	token = strtok(path, ":");
	if (dirs == NULL)
	i = 0;
	while (token != NULL)
	{
		dirs[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	dirs[i] = NULL;

	i = 0;
	while (dirs[i] != NULL)
	{
		chdir(dirs[i]);
		if (stat(cmd, &sb) == 0)
		{
			dirs[i] = concat_str(dirs[i], &ch, 1);
			cmd = str_concat(dirs[i], cmd);
			break;
		}
		i++;
	}
	chdir(cwd);
	return (cmd);
}

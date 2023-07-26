#include "main.h"

/**
* main - entry on the program
*
* Return: is always 0.
*/
int main(void)
{
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	char *args[MAXLINE / 2 + 1];
	while (1)
	{
	char *comment;

	linelen = _getline(&line, &linecap, stdin);
	if (linelen <= 0)
		break;

	comment = strchr(line, '#');
	if (comment != NULL)
		*comment = '\0';

	line[linelen - 1] = '\0';

	replace_variables(line);

	parse_line(line, args);

		if (args[0] == NULL)
			continue;

		execute_command(args);
	}

	free(line);
	return (0);
}

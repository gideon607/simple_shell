#include "main.h"

#define BUFFER_SIZE 1024

/**
* parse_line - splits a line into tokens separated by spaces
* @line: line to split
* @args: array of pointers to strings to store tokens
*
* Return: void
*/
void parse_line(char *line, char **args)
{
	int i = 0;
	args[0] = _strtok(line, " ");

	while (args[i] != NULL)
		args[++i] = _strtok(NULL, " ");
}

/**
* _getline - reads an entire line from a file stream
* @lineptr: pointer to the buffer that stores the line
* @n: size of the buffer
* @stream: file stream to read from
*
* Return: number of characters read, including newline character, but not
* including terminating null byte. -1 on error or end-of-file.
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static size_t start=0;
	static size_t end=0;
	size_t total_len=0;
	ssize_t bytes_read;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*lineptr = malloc(BUFFER_SIZE);
		if (*lineptr == NULL)
			return (-1);

		*n = BUFFER_SIZE;
	}

	while (1)
	{
	if (start >= end)
	{
		bytes_read = read(fileno(stream), buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		start = 0;
		end = bytes_read;
	}
	if (total_len >= *n - 1)
	{
		*n *= 2;
		*lineptr = realloc(*lineptr, *n);
		if (*lineptr == NULL)
			return (-1);
	}

	(*lineptr)[total_len++] = buffer[start++];
	if ((*lineptr)[total_len - 1] == '\n')
		break;
	}
	(*lineptr)[total_len] = '\0';
	return (total_len > 0 ? (ssize_t)total_len : bytes_read);
	
}

/**
 * _strtok - splits a string into tokens based on a delimiter
 * @str: the string to split
 * @delim: the delimiter to split the string on
 *
 * Return: pointer to the first token found in the string.
 * NULL is returned when there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *lasts;
	int ch;

	if (str == 0)
		str = lasts;
	do {
		if ((ch = *str++) == '\0')
			return (0);
	} while (strchr(delim, ch));
	--str;
	lasts = str + strcspn(str, delim);
	if (*lasts != 0)
		*lasts++ = 0;
	return (str);
}

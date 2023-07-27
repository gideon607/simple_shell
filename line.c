#include "main.h"

/**
  * **parse_strings - splits the string entered by the user.
  * @buffer: string to be split.
  * Return: splitted string.
  */
char **parse_strings(char *buffer)
{
	char **cmd = NULL;
	char *token, *delimeter = " \n";
	int i;

	cmd = malloc(sizeof(char *) * 1024);
	if (cmd == NULL)
	{
		perror("memory could not be allocated");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delimeter);
	i = 0;
	while (token != NULL)
	{
		cmd[i] = token;
		token = strtok(NULL, delimeter);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

/**
 * *str_concat - concatenates two strings.
 *
 * @dest: resulting string.
 * @src: source string.
 * Return: pointer to dest
 */
char *str_concat(char *dest, char *src)
{
	int i, n;

	n = find_len(dest);
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[n + i] = src[i];
	}
	dest[n + i] = '\0';
	return (dest);
}

/**
 * *locate_char - locates a character in a string.
 *
 * @s: string.
 * @c: character to be located.
 * Return: pointer to first occurrence of NULL if no character found.
 */
char *locate_char(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return (0);
}

/**
  * find_len - finds the length of a string.
  * Return: length of c.
  * @pointer: pointer.
  */
int find_len(char *pointer)
{
	int c = 0;

	while (*(pointer + c) != '\0')
	{
		c++;
	}
	return (c);
}

/**
 * concat_str - concatenates two strings.
 *
 * @dest: resulting string.
 * @src: source string.
 * @n: string length.
 * Return: pointer to dest
 */

char *concat_str(char *dest, char *src, int n)
{
	int i, m;

	m = find_len(dest);
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[m + i] = src[i];
	}
	dest[m + i] = '\0';
	return (dest);
}

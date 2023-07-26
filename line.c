#include "main.h"

#define BUFFER_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {
    static char buffer[BUFFER_SIZE];
    static size_t start = 0, end = 0;
    size_t len = 0;
    size_t total_len = 0;
    ssize_t bytes_read;

    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;
    }

    if (*lineptr == NULL) {
        *lineptr = malloc(BUFFER_SIZE);
        if (*lineptr == NULL) {
            return -1;
        }
        *n = BUFFER_SIZE;
    }

    while (1) {
        if (start >= end) {
            bytes_read = read(fileno(stream), buffer, BUFFER_SIZE);
            if (bytes_read <= 0) {
                break;
            }
            start = 0;
            end = bytes_read;
        }

        if (total_len >= *n - 1) {
            *n *= 2;
            *lineptr = realloc(*lineptr, *n);
            if (*lineptr == NULL) {
                return -1;
            }
        }

        (*lineptr)[total_len++] = buffer[start++];
        if ((*lineptr)[total_len - 1] == '\n') {
            break;
        }
    }

    (*lineptr)[total_len] = '\0';
    return total_len > 0 ? total_len : bytes_read;
}


void parse_line(char *line, char **args)
{
    int i = 0;

    args[0] = strtok(line, " ");

    while (args[i] != NULL)
        args[++i] = strtok(NULL, " ");
}


/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
        unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

        while (*(s + count) != '\0')
        {
                if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
                        break;

                if (*(s + count) == '-')
                        pn *= -1;

                if ((*(s + count) >= '0') && (*(s + count) <= '9'))
                {
                        if (size > 0)
                                m *= 10;
                        size++;
                }
                count++;
        }

        for (i = count - size; i < count; i++)
        {
                oi = oi + ((*(s + i) - 48) * m);
                m /= 10;
        }
        return (oi * pn);
}

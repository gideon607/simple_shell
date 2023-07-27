#ifndef MAIN_H
#define MAIN_H
extern char **environ;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
void print_environ(void);
int str_comp(char *s1, char *s2);
char **parse_strings(char *buffer);
char *search_path(char *cmd);
char *concat_str(char *dest, char *src, int n);
int find_len(char *pointer);
char *str_concat(char *dest, char *src);
char *locate_char(char *s, char c);
#endif /* MAIN_H */

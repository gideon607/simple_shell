#ifndef MAIN_H
#define MAIN_H
#include <dirent.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#include "main.h"

#define MAX_COMMAND_PER_LINE 50

void exe_commands(char *commands);
void exe_commands(char *commands_line);
char *find_command(const char *commands);

#endif /* MAIN_H */

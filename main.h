#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <dirent.h>

extern char **environ:

char **tokenize(char *buffer);
void print_env(void);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void free_grid(char **grid);
char *_strcpy(char *dest, char *src);
char *_strstr(char *haystack, char *needle);

#endif

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

extern char **environ;

char **tokenize(char *buffer);
void print_env(void);
void free_grid(char **grid);
char *get_env(char *token_path);
char *attach_path(char *buffer, char **token);
int execute(char **token, char *buffer, int counter, int parameters);
int _fork(char **token, char *buffer, int parameters);
char *_strdup(char *str);
void print_env(void);
void shell_exit(char **token, char *buffer, int parameters)

#endif

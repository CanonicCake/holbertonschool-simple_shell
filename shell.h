#ifndef SHELL_H
#define SHELL_H

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

typedef struct simple_shell{
	int
	char
	*function
	void(*f)(char*)
} shell;

unsigned long int simple_shell(shell_struct *parameter);

#endif

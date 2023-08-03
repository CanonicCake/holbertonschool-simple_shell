#include <stdio.h>
#include <stdlib.h>
#include <shell.h>

int shell (const char *parameters, unsigned long int command)
{
	while(1)
	{
		type_print;
		read_command(command, parameters);
		if (fork() !=0)
		{
			wait(NULL);
		}
		else
		{
			exceve(command, parameters, 0);
		}
	}
}

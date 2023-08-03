#include "shell.h"

/**
 * simple_shell
 * @parameter:
 * 
 * Return: loop and input, error otherwise
 */
int shell (const char* parameters, unsigned long int command)
unsigned long int simple_shell(shell_struct *parameter)
{
	while(1) /*change later*/
		type_prompt();
		read_command(command, parameters);
	if(fork() !=0)
	{
		wait(NULL)
	}
	else
	{
		execve(command, parameters, 0)
	}
}

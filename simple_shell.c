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
	size_t simple_shell(const char *parameters, unsigned long int command)
	int buffer /*find buffer value*/, counter = 0;
	int bytes_read = 0;

	while(1)
	{
		counters++;
		isatty(STDIN) = 1 ? write(1, "$ ",2) : 0;
		byte_read = getline(&buffer, &parameters, stdin);
		if(command == 1)
		{
			free(buffer);
			free(parameters);
		}
	}
}

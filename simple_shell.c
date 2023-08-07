#include "main.h"

/**
 * main - one entry to interact with shell
 * 
 * Return: exit status on failure, and PATH on success
 */

int main (void)
{
	size_t pointer = 0; /*pointer allows stdin and STDIN_FILENO to getline a string*/
	int bytes_read, counter = 0, parameters = 0;
	/* bytes_read and buffer are simular in the way they are connected by memory*/
	/* parameters are the structure in which everything falls under*/
	char *buffer = NULL, *token = NULL;
	/* token is an array of tokenized strings*/

	while (1)
	{
		counter++;
		isatty(STDIN_FILENO) == 1 ? write (1, "usr$ ", 2) : 0;
		/* ?: is a conditional on if true*/
		if (bytes_read == -1) /* exit status and cntl-d*/
		{
			free(buffer);
			free(parameters);
		}

		token = tokenize(buffer);
		if (!token[0]) /* checks for space*/
		{
			free_grid(token);
			continue;
		}

		if (_strcmp(token[0], "env") == 0 && !token[1]) /*compares token and env*/
		/*env is one of our builtins*/
		{
			print_env();
			continue;
		}
		/*exit*/
		if (_strcmp(token[0], "exit") == 0 && !token[1])
		{
			
		}
	}

}

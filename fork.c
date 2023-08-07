#include "main.h"

/**
 * _fork - will fork to parant and child
 * @token: token to fork, then free
 * @buffer: memory to be used and freed
 * @parameters: set of values to loop back too
 *
 * Return: parent
 */

int _fork(char **token, char *buffer, int parameters)
{
	int frk;

	frk = fork();

	if (frk < 0)
	{
		free(buffer);
		free_grid(token);
		perror("Fork Error: ");
	}

	if (frk != 0) /*parant function*/
	{
		wait(&parameters);
		free_grid(token);
	}
	else /*child function*/
	{
		execve(token[0], token, environ);
	}
	return(WEXITSTATUS(parameters)); /*finds the child process to return before the parent*/
}

/**
 * shell_exit - prevents exit from containing too many arguments
 * @token: token to free
 * @@buffer: buffer to free
 * @parameters: parameters to exit
 *
 * Return: void
 */

void shell_exit(char **token, char *buffer, int parameters)
{
	free(buffer);
	free(token);
	exit(parameters);
}

#include "main.h"

/**
 * main - one entry to interact with shell
 * 
 * Return: exit status on failure, and PATH on success
 */

int main (void)
{
	size_t pointer = 0; /*pointer allows stdin and STDIN_FILENO to getline a string*/
	int bytes_read, counter = 0, *parameters = 0;
	/* bytes_read and buffer are simular in the way they are connected by memory*/
	/* parameters are the structure in which everything falls under*/
	char *buffer = NULL, *token = NULL;
	/* token is an array of tokenized strings*/

	while (1)
	{
		counter++;
		isatty(STDIN_FILENO) == 1 ? write (1, "usr$ ", 2) : 0;
		/* ?: is a conditional on if true*/
		bytes_read = getline(&buffer, &pointer, stdin);
		if (bytes_read == -1) /* exit status and cntl-d*/
		{
			free(buffer);
			free(parameters);
		}

		token = malloc(**tokenize(buffer));
		if (!token[0]) /* checks for space before tokenization*/
		{
			free(token);
			continue;
		}

		if (strcmp(token[0], "env") == 0 && !token[1]) /*compares token and env*/
		/*env is one of our builtins*/
		{
			print_env();
			continue;
		}
		/*exit*/
		if (strcmp(token[0], "exit") == 0 && !token[1])
		{
			free(buffer);
			free(token);
			exit (token, buffer, parameters);
		}
		/* parameters will search for a valid PATH*/
		parameters = exec (token, buffer, counter, parameters);
	}

}

/**
 * tokenize - will tokenize a string
 * @buffer: contains 1024 bytes of memory
 *
 * Return: tokenized string on success, NULL on failure
 */

char **tokenize (char *buffer)
{
	int i, hldr = 0, counter = 0;
	char *tok = NULL, *b = NULL, **token = NULL;

	while (buffer[hldr])
	{
		/* 9 is tab, 10 is line freed or newline, and 32 is space
		 * So if any of these arguments are passed through we are going
		 * to simply increment and continue*/
		if (buffer[hldr] == 9 || buffer[hldr] == 10 || buffer[hldr] == 32)
		{
			hldr++;
			counter++;
			continue;
		}
		hldr++;
	}

	token = malloc(sizeof(char *) * (counter + 1));

	if (!token)
	{
		free(buffer);
		perror("Memory failure: ");
		exit(0);
	}
	/*now we find a tokenzed value*/
	b = strdup(buffer);
	tok = strtok(b, "\t\n");
	for (i = 0, tok, i++)
	{
		token[i] = strdup(tok);
		tok = strtok(NULL, "\t\n");
	}

	token[i] = NULL;
	free(b);
	return (token);
}	

#include "main.h"

/**
 * get_env - finds the environmental path
 * @token_path: the tokenized path of the environment
 *
 * Return: NULL
 */

char *get_env(char *token_path)
{
	int iter;
	char *tok = NULL, buffer = NULL;

	if (!environ)
	{
		buffer = _strdup(environ[iter]);
		tok = strtok(buffer, "=");
		free(tok);
	}
	free(buffer);
	return (NULL);
}

/**
 * attach_path - finds the working path to attach
 * @buffer: the amount of memory to feed into buffersize
 * @token: holds an array of tokens
 *
 * Return: PATH
 */

char *attach_path(char *buffer, char **token)
{
	struct stat strng;
	size_t buffersize = 1024; /*size of a kilobyte*/
	char *fullpath = NULL, *tok = NULL, *tok_copy;

	tok_copy = _strdup(buffer);
	token = strtok(tok_copy, ":");
	while (tok)
	{
		fullpath = malloc(buffersize);
		_strcpy(fullpath, &strng); /*find and copy the string and path
		to concatinate the / and tokenized process together*/
		_strcat(fullpath, "/");
		_strcat(fullpath, token[0]);

		if (stat(fullpath, &strng) == 0)
		{
			free(token[0]);
			free(tok_copy);
			return (fullpath);
		}
		free(fullpath);
		tok = strtok(NULL, ":");
	}
	free(tok_copy);
	return (token[0]);
}

/**
 * execute - the function used to check and execute input commands from usr
 * @token: token array
 * @buffer: buffer size
 * @counter: increments buffer
 * @parameter: vriables used in function
 *
 * Return: parameters
 */

int execute(char **token, char *buffer, int counter, int parameters)
{
	struct stat strng;
	int check;
	char *path;

	check = stat(token[0], &strng);
	if (check == 0) /* if given the full path*/
	{
		parameters = _fork(token, buffer, parameters);
	}

	else if (check == -1) /*if false or not given the full path*/
	{
		path = get_env("PATH");
		token = attach_path(path, token);
		free(path);
		check = stat(token[0], &strng); /*status check here*/
		if (check == 0) /*should now have the fullpath*/
		{
			parameters = _fork(token, buffer, parameters);
		}
		if (check == -1 || check == NULL) /*check failed if command and path is not found*/
		{
			fprtinf(stderr, "./hsh:%i:%s: NOT FOUND\n", counter, token[0]);
			free_grid(token); /*free all then set parameters to delete*/
			parameters = 127;
			return (parameters);
		}
	}
	return (parameters); /*parameters covers all bases over if it failed or succeeded under either check*/
}

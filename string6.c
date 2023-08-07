#include "main.h"

/**
 * _strdup - string duplication
 * @str: string to point too
 *
 * Return: value of character
 */

char *_strdup(char *str)
{

	unsigned int i, a;
	char *s;

	if (str == NULL)
		return (NULL);

	i = a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	a++;
	s = malloc(a * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	while (i <= a)
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}

#include "holberton.h"

/**
 * *_strcat - the connection string
 * @dest: string variable destination
 * @src: string variable source
 * Return: the pointer pointing
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, n;

	while (dest[i])
	{
		i++;
	}
	for (n = 0; src[n] != 0; n++)
	{
		dest[i] = src[n];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

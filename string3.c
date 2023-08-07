#include "main.h"

/**
 * _strcmp - compares two stings
 * @s1: string 1
 * @s2: string 2
 * Return: number equvilent to string comparison
 */

int _strcmp(char *s1, char *s2)
{

	int a = 0, b = 0, c = 0, i = 0, len;

	while (s1[a])
	{
		a++;
	}

	while (s2[b])
	{
		b++;
	}
	if (a <= b)
	{
		len = a;
	}
	else
	{
		len = b;
	}
	while (c <= len)
	{
		if (s1[c] == s2[c])
		{
			c++;
			continue;
		}
		else
		{
			i = s1[c] - s2[c];
			break;
		}
		c++;
	}
	return (i);
}

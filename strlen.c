#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to be checked.
 * Return: The length of s.
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

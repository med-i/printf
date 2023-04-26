#include "main.h"

/**
 * _isdigit - function that checks if @c is a digit
 * @c: the character to check
 *
 * Return: 1 of @c is a digit, 0 otherwise.
*/
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
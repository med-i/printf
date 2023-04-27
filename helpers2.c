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
/**
 * _tohex - converts @n to base 16
 * @n: int to convert
 *
 * Return: n
*/
char _tohex(int n)
{
	if (n < 10)
		return (n + '0');
	else
		return (n - 10 + 'A');
}
/**
 * get_code - function that converts @c to its hexadecimal ASCII representation
 * @c: the character to be converted.
 *
 * Return: a string containing the hexadecimal ASCII representation of @c.
 */
char *get_code(char c)
{
	char *code = malloc(3 * sizeof(char));
	int code_int = (int)c;

	if (code_int < 16)
	{
		code[0] = '0';
		code[1] = _tohex(code_int);
	}
	else
	{
		code[0] = _tohex(code_int / 16);
		code[1] = _tohex(code_int % 16);
	}

	code[2] = '\0';

	return (code);
}

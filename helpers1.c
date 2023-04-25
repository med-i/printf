#include "main.h"

/**
 * get_code - function that converts @c to its hexadecimal ASCII representation
 * @c: the character to be converted.
 *
 * Return: a string containing the hexadecimal ASCII representation of @c.
 */
char *get_code(char c)
{
	char *code = malloc(3 * sizeof(char));

	code = _itoa((int)c, 16);

	if (_strlen(code) < 2)
		code[1] = '0';

	code[2] = '\0';
	code = _strrev(code);
	_toupper(code);

	return (code);
}

/**
 * get_flag - gets the flag character.
 * @c: the character to check.
 *
 * Return: the flag character, otherwise -1.
 * supporter flags are: + ' ' # 0 -.
 */
char get_flag(char c)
{
	if (c == '+' || c == ' ' || c == '#' || c == '0' || c == '-')
		return (c);

	return (-1);
}

char get_length(char c)
{
	if (c == 'l' || c == 'h')
		return (c);

	return (-1);
}

long int get_int(va_list ap, char length)
{
	if (length == 'l')
		return (va_arg(ap, long int));
	else if (length == 'h')
		return ((short int)va_arg(ap, int));
	else
		return ((int)va_arg(ap, int));
}

unsigned long int get_unsigned_int(va_list ap, char flag)
{
	if (flag == 'l')
		return (va_arg(ap, unsigned long int));
	else if (flag == 'h')
		return ((unsigned short int)va_arg(ap, unsigned int));
	else
		return ((unsigned int)va_arg(ap, unsigned int));
}

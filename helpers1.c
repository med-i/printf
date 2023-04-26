#include "main.h"

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
/**
 * get_length - function that checks for length modifier
 * @c: the character to check
 *
 * Return: @c if it is 'l' or 'h', -1 otherwise.
*/
char get_length(char c)
{
	if (c == 'l' || c == 'h')
		return (c);

	return (-1);
}
/**
 * get_width - function that extracts the width value from a format specifier
 * @format: pointer to a pointer to the format specifier string
 *
 * Return: the width value as an integer, or 0 if not npecified.
*/
int get_width(const char **format)
{
	int width = 0;

	while (_isdigit(**format))
	{
		width *= 10;
		width += **format - '0';
		(*format)++;
	}
	return (width);
}
/**
 * get_int - resizes @ap to @length
 * @ap: the va_list to extract the integer from.
 * @length: the length specifier for the integer type
 * 'l' for long, 'h' for short.
 *
 * Return: the resized int.
*/
long int get_int(va_list ap, char length)
{
	if (length == 'l')
		return (va_arg(ap, long int));
	else if (length == 'h')
		return ((short int)va_arg(ap, int));
	else
		return ((int)va_arg(ap, int));
}
/**
 * get_unsigned_int - resizes @ap to @length
 * @ap: the va_list to extract the integer from.
 * @length: the length specifier for the integer type
 * 'l' for long, 'h' for short.
 *
 * Return: the resized int.
*/
unsigned long int get_unsigned_int(va_list ap, char length)
{
	if (length == 'l')
		return (va_arg(ap, unsigned long int));
	else if (length == 'h')
		return ((unsigned short int)va_arg(ap, unsigned int));
	else
		return ((unsigned int)va_arg(ap, unsigned int));
}

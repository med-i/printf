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
int get_flag(const char **format_p)
{
	const char *format = *format_p;
	int flag = -1;

	if (*format == '+' || *format == ' ' || *format == '#' || *format == '0' || *format == '-')
	{
		flag = *format;
		format++;
	}
	
	*format_p = format;
	return (flag);
}

int get_length(const char **format_p)
{
	const char *format = *format_p;
	int length = -1;

	if (*format == 'l' || *format == 'h')
	{
		length = *format;
		format++;
	}
	*format_p = format;
	return (length);
}

long int resize_int(long int num, int length)
{
	if (length == 'l')
		return (num);
	else if (length == 'h')
		return ((short) num);
	
	return ((int) num);
}

/* void padding(char c, int n)
{
    while (n-- > 0)
        write(1, &c, 1);
}
 */
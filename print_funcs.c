#include "main.h"

/**
 * print - prints entire string.
 * @str: the string to print.
 *
 * Return: the count of printed characters.
 */
int print(const char *str)
{
	int i = 0;

	while (str[i])
		_putchar(str[i++]);

	return (i);
}

/**
 * print_range - printsa substring.
 * @str: the string to print.
 * @start: the starting index of the substring.
 * @end: the ending index of the substring.
 *
 * Return: the count of printed characters.
 */
int print_range(const char *str, int start, int end)
{
	int i;

	for (i = start; i < end; i++)
		_putchar(str[i]);

	return (--i);
}

/**
 * print_char - prints a character.
 * @ap: the character to print.
 *
 * Return: 1.
 */
int print_char(va_list ap)
{
	char c = va_arg(ap, int);

	return (_putchar(c));
}

/**
 * print_str - prints a string.
 * @ap: the string to print.
 *
 * Return: the count of printed characters.
 */
int print_str(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i = 0;

	while (str[i])
		_putchar(str[i++]);

	return (i);
}

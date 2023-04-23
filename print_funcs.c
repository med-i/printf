#include "main.h"

/**
 * print_char - prints a character.
 * @ap: the character to print.
 *
 * Return: 1.
 */
int print_char(va_list ap)
{
	char chr = va_arg(ap, int);

	return (write(1, &chr, 1));
}

/**
 * print_str - prints a string.
 * @ap: the string to print.
 *
 * Return: the count of printed characters.
 */
int print_str(va_list ap)
{
	int len;
	char *str;

	if (!va_arg(ap, char *))
		str = "(null)";
	else
		str = va_arg(ap, char *);

	len = _strlen(str);

	return (write(1, str, len));
}

/**
 * print_percent - prints a string.
 * @ap: maco.
 *
 * Return: 1.
 */
int print_percent(va_list ap)
{
	char percent = '%';
	(void)ap;

	return (write(1, &percent, 1));
}

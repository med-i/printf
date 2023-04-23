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
	char *str = va_arg(ap, char *);

	if (!str)
		return (write(1, "(null)", 6));

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

/**
 * print_int - prints an integer.
 * @ap: the integer to print.
 *
 * Return: the count of printed characters.
 */
int print_int(va_list ap)
{
	int n = va_arg(ap, int);
	char buf[12];
	int i = 0, sign = 0, count = 0;

	if (n < 0)
	{
		n = -n;
		sign = 1;
	}

	do {
		buf[i++] = n % 10 + '0';
		n /= 10;
	} while (n > 0);

	if (sign)
		buf[i++] = '-';

	while (i >= 0)
		count += write(1, &buf[--i], 1);

	return (count);
}

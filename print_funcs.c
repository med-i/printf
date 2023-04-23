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
	unsigned int num = n;
	int div = 1, count = 0;
	char c;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}

	while (num / div >= 10)
		div *= 10;

	while (div >= 1)
	{
		c = '0' + num / div;
		count += write(1, &c, 1);
		num %= div;
		div /= 10;
	}

	return (count);
}

#include "main.h"

/**
 * print_char - prints a character.
 * @ap: the character to print.
 *
 * Return: 1.
 */
int print_char(va_list ap, char flag)
{
	char chr = va_arg(ap, int);
	(void)flag;

	return (write(1, &chr, 1));
}

/**
 * print_str - prints a string.
 * @ap: the string to print.
 *
 * Return: the count of printed characters.
 */
int print_str(va_list ap, char flag)
{
	int len;
	char *str = va_arg(ap, char *);
	(void)flag;

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
int print_percent(va_list ap, char flag)
{
	char percent = '%';
	(void)ap;
	(void)flag;

	return (write(1, &percent, 1));
}

/**
 * print_int - prints an integer.
 * @ap: the integer to print.
 *
 * Return: the count of printed characters.
 */
int print_int(va_list ap, char flag)
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
	else if (flag == '+')
		count += write(1, "+", 1);
	else if (flag == ' ')
		count += write(1, " ", 1);

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
/**
 * print_binary - prints @ap in base 2.
 * @ap: arg.
 *
 * Return: the count of printed characters.
 */
int print_binary(va_list ap, char flag)
{
	unsigned int n = va_arg(ap, unsigned int);
	int i, count = 0;
	int size = sizeof(n) * 8;
	(void)flag;

	for (i = size - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
			count += write(1, "1", 1);
		else if (count > 0 || i == 0)
			count += write(1, "0", 1);
	}

	return (count);
}

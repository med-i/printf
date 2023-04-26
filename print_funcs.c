#include "main.h"

/**
 * print_char - prints a character.
 * @ap: the character to print.
 * @flag: the flag character.
 * @width: ...
 * @length: ...
 *
 * Return: 1.
 */
int print_char(va_list ap, char flag, int width, char length)
{
	char chr = va_arg(ap, int);
	int count = 0;
	int padding = width - 1;
	(void)length;

	if (flag == '-')
	{
		count += write(1, &chr, 1);
		while (padding-- > 0)
			count += write(1, " ", 1);
	}
	else if (flag == '0')
	{
		while (padding-- > 0)
			count += write(1, "0", 1);
		count += write(1, &chr, 1);
	}
	else
	{
		while (padding-- > 0)
			count += write(1, " ", 1);
		count += write(1, &chr, 1);
	}
	return (count);
}

/**
 * print_str - prints a string.
 * @ap: the string to print.
 * @flag: the flag character.
 * @width: ...
 * @length: ...
 *
 * Return: the count of printed characters.
 */
int print_str(va_list ap, char flag, int width, char length)
{
	int len, count = 0;
	char *str = va_arg(ap, char *);
	int padding_len;
	char padding;
	(void)flag;
	(void)width;
	(void)length;

	if (!str)
		return (write(1, "(null)", 6));

	len = _strlen(str);

	if (width > len)
	{
		padding_len = width - len;
		padding = (flag == '0') ? '0' : ' ';
		if (flag == '-')
		{
			count += write(1, str, len);
			while (padding_len--)
				count += write(1, &padding, 1);
		}
		else
		{
			while (padding_len--)
				count += write(1, &padding, 1);
			count += write(1, str, len);
		}
	}
	else
		count += write(1, str, len);

	return (count);
}

/**
 * print_percent - prints a string.
 * @ap: maco.
 * @flag: the flag character.
 * @width: ...
 * @length: ...
 *
 * Return: 1.
 */
int print_percent(va_list ap, char flag, int width, char length)
{
	char percent = '%';
	(void)ap;
	(void)flag;
	(void)width;
	(void)length;

	return (write(1, &percent, 1));
}

/**
 * print_int - prints an integer.
 * @ap: the integer to print.
 * @flag: the flag character.
 * @width: ...
 * @length: ...
 *
 * Return: the count of printed characters.
 */
int print_int(va_list ap, char flag, int width, char length)
{
	long int n;
	unsigned int num;
	int div = 1, count = 0, num_digits = 1;
	char c, pad_char = ' ';
	int padding;

	n = get_int(ap, length);
	num = n;

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
	{
		div *= 10;
		num_digits++;
	}
	padding = width - num_digits;
	while (padding-- > 0)
		count += write(1, &pad_char, 1);
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
 * @flag: the flag character.
 * @width: ...
 * @length: ...
 *
 * Return: the count of printed characters.
 */
int print_binary(va_list ap, char flag, int width, char length)
{
	unsigned int n = va_arg(ap, unsigned int);
	int i, count = 0;
	int size = sizeof(n) * 8;
	(void)flag;
	(void)width;
	(void)length;

	for (i = size - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
			count += write(1, "1", 1);
		else if (count > 0 || i == 0)
			count += write(1, "0", 1);
	}

	return (count);
}

#include "main.h"

/**
 * print_unsigned_int - prints an unsigned integer
 * @ap: arg.
 * Return: the count of printed characters.
 */
int print_unsigned_int(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = _itoa(num, 10);
	int count = 0;

	count += write(1, str, _strlen(str));
	free(str);
	return (count);
}
/**
 * print_octal - prints an unsigned integer in octal format
 * @ap: arg.
 * Return: the count of printed characters.
 */
int print_octal(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = _itoa(num, 8);
	int count = 0;

	count += write(1, str, _strlen(str));
	free(str);
	return (count);
}
/**
 * print_hex - prints an unsigned integer in lowercase hexadecimal
 * @ap: arg.
 *
 * Return: the count of printed characters.
 */
int print_hex(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = _itoa(num, 16);
	int count = 0;

	count += write(1, str, _strlen(str));
	free(str);
	return (count);
}
/**
 * print_hex_uppercase - prints an unsigned integer in uppercase hexadecimal
 * @ap: arg.
 *
 * Return: the count of printed characters.
 */
int print_hex_uppercase(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *hex_str = malloc(sizeof(char) * 9);
	int i, rem, count = 0;

	for (i = 0; i < 8; i++)
		hex_str[i] = '\0';

	while (i > 0)
	{
		rem = num % 16;
		if (rem < 10)
			hex_str[i] = rem + '0';
		else
			hex_str[i] = rem + 'A' - 10;
		num = num / 16;
		i--;
	}
	_toupper(hex_str);
	count += write(1, hex_str, sizeof(char) * 9);
	free(hex_str);
	return (count);
}

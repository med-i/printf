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
	char *str = _itoa(num, 16);
	int count = 0;

	_toupper(str);
	count += write(1, str, _strlen(str));
	free(str);
	return (count);
}

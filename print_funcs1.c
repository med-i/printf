#include "main.h"

/**
 * print_unsigned_int - prints an unsigned integer
 * @ap: arg.
 * @flag: the flag character.
 *
 * Return: the count of printed characters.
 */
int print_unsigned_int(va_list ap, char flag, int width, char length)
{
	unsigned long int num;
	char *str;
	int count = 0;
	(void)flag;
	(void)width;

	num = get_unsigned_int(ap, length);
	str = _itoa(num, 10);

	count += write(1, str, _strlen(str));

	free(str);
	return (count);
}

/**
 * print_octal - prints an unsigned integer in octal format
 * @ap: arg.
 * @flag: the flag character.
 *
 * Return: the count of printed characters.
 */
int print_octal(va_list ap, char flag, int width, char length)
{
	unsigned long int num;
	char *str;
	int count = 0;
	(void)width;

	num = get_unsigned_int(ap, length);
	str = _itoa(num, 8);

	if (flag == '#')
		count += write(1, "0", 1);
	count += write(1, str, _strlen(str));

	free(str);
	return (count);
}

/**
 * print_hex - prints an unsigned integer in lowercase hexadecimal
 * @ap: arg.
 * @flag: the flag character.
 *
 * Return: the count of printed characters.
 */
int print_hex(va_list ap, char flag, int width, char length)
{
	unsigned long int num;
	char *str;
	int count = 0;
	(void)width;

	num = get_unsigned_int(ap, length);
	str = _itoa(num, 16);

	if (flag == '#')
		count += write(1, "0x", 2);
	count += write(1, str, _strlen(str));

	free(str);
	return (count);
}

/**
 * print_hex_uppercase - prints an unsigned integer in uppercase hexadecimal
 * @ap: arg.
 * @flag: the flag character.
 *
 * Return: the count of printed characters.
 */
int print_hex_uppercase(va_list ap, char flag, int width, char length)
{
	unsigned long int num;
	char *str;
	int count = 0;
	(void)width;

	num = get_unsigned_int(ap, length);
	str = _itoa(num, 16);

	if (flag == '#')
		count += write(1, "0X", 2);
	_toupper(str);
	count += write(1, str, _strlen(str));

	free(str);
	return (count);
}

/**
 * print_str_wide - function that prints @ap while converting non-printable
 * characters to their hexadecimal ASCII representation.
 * @ap: the string to be printed.
 * @flag: the flag character.
 *
 * Return: the count of printed characters.
 */
int print_str_wide(va_list ap, char flag, int width, char length)
{
	char *str = va_arg(ap, char *);
	int i, count = 0;
	char *code;
	(void)flag;
	(void)width;
	(void)length;

	if (!str)
		return (write(1, "(null)", 6));

	for (i = 0; str[i]; i++)
		if (_isprint(str[i]))
			count += write(1, &str[i], 1);
		else
		{
			count += write(1, "\\x", 2);
			code = get_code(str[i]);
			count += write(1, code, _strlen(code));
			free(code);
		}

	return (count);
}

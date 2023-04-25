#include "main.h"

/**
 * print_pointer - function that prints the adress of @ap
 * @ap: the pointer
 * @flag: the flag character.
 *
 * Return: the count of printed characters.
 */
int print_pointer(va_list ap, char flag)
{
	void *ptr = va_arg(ap, void *);
	unsigned long int add;
	char *str;
	int count = 0;
	(void)flag;

	if (!ptr)
		return (write(1, "(nil)", 5));

	add = (unsigned long int)ptr;
	str = _itoa(add, 16);
	count += write(1, "0x", 2);
	count += write(1, str, _strlen(str));

	free(str);
	return (count);
}

/**
 * print_reverse - function that prints a string in reverse.
 * @ap: the string.
 * @flag: the flag character.
 *
 * Return: the count of printed characters.
 */
int print_reverse(va_list ap, char flag)
{
	char *str = va_arg(ap, char *);
	int i, count = 0;
	(void)flag;

	if (!str)
		str = "(NULL)";
	for (i = _strlen(str) - 1; i >= 0; i--)
		count += write(1, &str[i], 1);

	return (count);
}

/**
 * print_rot13 - function that encodes and prints @ap using the ROT13 cipher
 * @ap: the string.
 * @flag: the flag character.
 *
 * Return: the count of printed characters
 */
int print_rot13(va_list ap, char flag)
{
	char *str = va_arg(ap, char *);
	char letters[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char rot13[] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";
	int i, j, count = 0;
	(void)flag;

	if (str == NULL)
		str = "(NULL)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; rot13[j]; j++)
			if (letters[j] == str[i])
			{
				count += write(1, &rot13[j], 1);
				break;
			}

		if (!letters[j])
			count += write(1, &str[i], 1);
	}

	return (count);
}

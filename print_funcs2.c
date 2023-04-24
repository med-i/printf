#include "main.h"

/**
 * print_pointer - function that prints the adress of @ap
 * @ap: the pointer
 *
 * Return: the count of printed characters.
*/
int print_pointer(va_list ap)
{
	void *ptr = va_arg(ap, void *);
	unsigned long int add;
	char *str;
	int count = 0;

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
 *
 * Return: the count of printed characters.
*/
int print_reverse(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i, count = 0;

	if (!str)
		str = "(NULL)";
	for (i = _strlen(str); i >= 0; i--)
		count += write(1, &str[i], 1);
	return (count);
}

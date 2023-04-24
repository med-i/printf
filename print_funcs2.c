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

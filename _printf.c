#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format:
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	cs spe[] = {
	    {'c', print_char},
	    {'s', print_str}};

	va_list ap;
	unsigned int count = 0;
	char s;
	int idx;
	int len = _strlen(format);

	get_conspe(format, &s, &idx);

	va_start(ap, format);

	if (s)
	{
		count = print_range(format, 0, idx);

		switch (s)
		{
		case 'c':
			count += spe[0].f(ap);
			break;
		case 's':
			count += spe[1].f(ap);
			break;
		}

		count += print_range(format, idx + 2, len);
	}
	else
	{
		count = print(format);
	}

	va_start(ap, format);

	return (count);
}

#include "main.h"

static con_spe conspe[] = {
{'c', print_char},
{'s', print_str},
{'%', print_percent},
{'0', NULL}};

/**
 * _printf - produces output according to a format.
 * @format:
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int count = 0, i;

	if (!format || (*format == '%' && *(format + 1) == '\0'))
		return (1);

	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			i = 0;
			while (conspe[i].spe)
			{
				if (conspe[i].spe == *format)
				{
					count += conspe[i].func(ap);
					format++;
					break;
				}
				i++;
			}
		}
		else
		{
			count += write(1, format, 1);
			format++;
		}
	}

	va_end(ap);

	return (count);
}

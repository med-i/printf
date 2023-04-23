#include "main.h"

static con_spe conspe[] = {
{'c', print_char},
{'s', print_str},
{'%', print_percent},
{'X', NULL}};

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

	if (!format || (*format == '%' && !*(format + 1)))
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);
			while (*format == ' ')
				format++;
			if (!*format)
				return (-1);

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

			if (!conspe[i].spe)
				count += print_percent(ap);
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

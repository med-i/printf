#include "main.h"

static con_spe conspe[] = {
{'c', print_char},
{'s', print_str},
{'%', print_percent},
{'i', print_int},
{'d', print_int},
{'b', print_binary},
{'u', print_unsigned_int},
{'o', print_octal},
{'x', print_hex},
{'X', print_hex_uppercase},
{'S', print_str_wide},
{'p', print_pointer},
{'r', print_reverse},
{'R', print_rot13}};
/**
 * _printf - produces output according to a format.
 * @format:
 *
 * Return: the number of characters printed, otherwise -1.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int count = 0, i;
	char flag, length;

	if (!format)
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{

			flag = get_flag(*(format + 1));
			if (flag != -1)
				format++;
			length = get_length(*(format + 1));
			if (length != -1)
				format++;
			format++;
			while (*format == ' ')
				format++;
			if (!*format)
				return (-1);

			if (*format == 'l' || *format == 'h')
				format++;

			for (i = 0; conspe[i].spe; i++)
				if (conspe[i].spe == *format)
				{
					count += conspe[i].func(ap, flag, length);
					format++;
					break;
				}

			if (!conspe[i].spe)
				count += print_percent(ap, flag, length);
		}
		else
			count += write(1, format++, 1);
	}

	va_end(ap);
	return (count);
}

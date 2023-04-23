#include "main.h"

/**
 * print_char - prints a character.
 * @ap: the character to print.
 *
 * Return: 1.
 */
int print_char(va_list ap)
{
	char chr = va_arg(ap, int);

	return (write(1, &chr, 1));
}

/**
 * print_str - prints a string.
 * @ap: the string to print.
 *
 * Return: the count of printed characters.
 */
int print_str(va_list ap)
{
	int len;
	char *str = va_arg(ap, char *);

	if (!str)
		return (write(1, "(null)", 6));

	len = _strlen(str);

	return (write(1, str, len));
}

/**
 * print_percent - prints a string.
 * @ap: maco.
 *
 * Return: 1.
 */
int print_percent(va_list ap)
{
	char percent = '%';
	(void)ap;

	return (write(1, &percent, 1));
}

/**
 * print_int - prints an integer.
 * @ap: the integer to print.
 *
 * Return: the count of printed characters.
 */
int print_int(va_list ap)
{
	int n = va_arg(ap, int);
	unsigned int num = n;
	int div = 1, count = 0;
	char c;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}

	while (num / div >= 10)
		div *= 10;

	while (div >= 1)
	{
		c = '0' + num / div;
		count += write(1, &c, 1);
		num %= div;
		div /= 10;
	}

	return (count);
}
int print_binary(va_list ap) 
{
    unsigned int n = va_arg(ap, unsigned int);
    int size = sizeof(n) * 8;
    char *buf = malloc(size + 1);
	int i, leading_zeros, count = 0;
	
    buf[size] = '\0';
    for (i = size - 1; i >= 0; i--)
	{
        buf[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
	leading_zeros = 0;
    for (i = 0; i < size; i++) 
	{
        if (buf[i] == '0')
			leading_zeros++;
		else
		break;
    }
    if (leading_zeros == size) 
	{
        write(1, "0", 1);
    } 
	else 
	{
        count += write(1, buf + leading_zeros, size - leading_zeros);
    }
    free(buf);
	return (count);
}
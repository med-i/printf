#include "main.h"

/**
 * get_conspe - checks if a string has conversion specifiers.
 * @str: the string to check.
 * @s: the specifier to set.
 * @idx: the index of the specifier.
 */
void get_conspe(const char *str, char *s, int *idx)
{
	int i = 0;
	char c, c1;

	while (str[i + 1])
	{
		c = str[i], c1 = str[i + 1];

		if (c == '%' &&
		    c1 != '%' && c1 != ' ' && c1 != '\n' && c1 != '\0')
		{
			*s = *(str + i + 1);
			*idx = i;
			return;
		}

		i++;
	}
}

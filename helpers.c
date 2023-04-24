#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to be checked.
 * Return: The length of s.
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}
/**
 * _strrev - reverses the string @str
 * @str: the string to reverse
 * Return: the new string
 */
char *_strrev(char *str)
{
	int i, len = _strlen(str);
	char *rev = malloc((len + 1) * sizeof(char));

	for (i = 0; i < len; i++)
		rev[i] = str[len - i - 1];
	rev[len] = '\0';
	return (rev);
}
/**
 * _itoa - changes the number @num to @base
 * @num: the number
 * @base: the desired base
 * Return: the new number.
 */
char *_itoa(unsigned long int num, int base)
{
	char *str = malloc(32 * sizeof(char));
	int i = 0, rem;

	if (num == 0)
		str[i++] = '0';
	else
		while (num != 0)
		{
			rem = num % base;
			str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
			num /= base;
		}

	str[i] = '\0';
	str = _strrev(str);
	return (str);
}
/**
 * _toupper - converts lowercase letters to uppercase
 * @str: the string
 * Return: the new sqtring
 */
void _toupper(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
}
/**
 * _isprint - function that checks if @c is printable
 * @c: the character to check
 *
 * Return: 1 if printable, 0 otherwise.
*/
int _isprint(char c)
{
	return (c >= 32 && c < 127);
}


#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct cs - conversion specifiers.
 * @cs: the specifier character.
 * @f: pointer to print function.
 */
typedef struct cs
{
	char cs;
	int (*f)(va_list ap);
} cs;

int _putchar(char c);
int _strlen(const char *s);
int _printf(const char *format, ...);
void get_conspe(const char *str, char *s, int *idx);
int print(const char *str);
int print_range(const char *str, int start, int end);
int print_str(va_list ap);
int print_char(va_list ap);

#endif

#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct con_spe - conversion specifiers.
 * @spe: the specifier character.
 * @func: pointer to print function.
 */
typedef struct con_spe
{
	char spe;
	int (*func)(va_list ap);
} con_spe;

int _printf(const char *format, ...);

/* print functions*/
int print_char(va_list ap);
int print_str(va_list ap);
int print_percent(va_list ap);
int print_int(va_list ap);
int print_binary(va_list ap);
int print_unsigned_int(va_list ap);
int print_octal(va_list ap);
int print_hex(va_list ap);
int print_hex_uppercase(va_list ap);
int print_str_wide(va_list ap);
int print_pointer(va_list ap);

/* helper functions */
int _strlen(const char *s);
char *_strrev(char *str);
char *_itoa(unsigned long int num, int base);
void _toupper(char *str);
int _isprint(char c);
char *get_code(char c);

#endif

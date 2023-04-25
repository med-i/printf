#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct con_spe - conversion specifiers.
 * @spe: the specifier character.
 * @func: pointer to print function.
 */
typedef struct con_spe
{
	char spe;
	int (*func)(va_list ap, int flag, int length);
} con_spe;

int _printf(const char *format, ...);

/* print functions*/
int print_char(va_list ap, int flag, int length);
int print_str(va_list ap, int flag, int length);
int print_percent(va_list ap, int flag, int length);
int print_int(va_list ap, int flag, int length);
int print_binary(va_list ap, int flag, int length);
int print_unsigned_int(va_list ap, int flag, int length);
int print_octal(va_list ap, int flag, int length);
int print_hex(va_list ap, int flag, int length);
int print_hex_uppercase(va_list ap, int flag, int length);
int print_str_wide(va_list ap, int flag, int length);
int print_pointer(va_list ap, int flag, int length);
int print_reverse(va_list ap, int flag, int length);
int print_rot13(va_list ap, int flag, int length);

/* helper functions */
int _strlen(const char *s);
char *_strrev(char *str);
char *_itoa(unsigned long int num, int base);
void _toupper(char *str);
int _isprint(char c);
char *get_code(char c);
int get_flag(const char **format_p);
int get_length(const char **format_p);
long int resize_int(long int num, int length);
void padding(char c, int n);
long int resize_u(unsigned long int num, int length);

#endif

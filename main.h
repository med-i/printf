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
	int (*func)(va_list ap, char flag);
} con_spe;

int _printf(const char *format, ...);

/* print functions*/
int print_char(va_list ap, char flag);
int print_str(va_list ap, char flag);
int print_percent(va_list ap, char flag);
int print_int(va_list ap, char flag);
int print_binary(va_list ap, char flag);
int print_unsigned_int(va_list ap, char flag);
int print_octal(va_list ap, char flag);
int print_hex(va_list ap, char flag);
int print_hex_uppercase(va_list ap, char flag);
int print_str_wide(va_list ap, char flag);
int print_pointer(va_list ap, char flag);
int print_reverse(va_list ap, char flag);
int print_rot13(va_list ap, char flag);

/* helper functions */
int _strlen(const char *s);
char *_strrev(char *str);
char *_itoa(unsigned long int num, int base);
void _toupper(char *str);
int _isprint(char c);
char *get_code(char c);
char get_flag(char flag);
long int get_int(va_list ap, char flag);

#endif

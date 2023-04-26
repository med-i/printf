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
	int (*func)(va_list ap, char flag, int width, char length);
} con_spe;

int _printf(const char *format, ...);

/* print functions*/
int print_char(va_list ap, char flag, int width, char length);
int print_str(va_list ap, char flag, int width, char length);
int print_percent(va_list ap, char flag, int width, char length);
int print_int(va_list ap, char flag, int width, char length);
int print_binary(va_list ap, char flag, int width, char length);
int print_unsigned_int(va_list ap, char flag, int width, char length);
int print_octal(va_list ap, char flag, int width, char length);
int print_hex(va_list ap, char flag, int width, char length);
int print_hex_uppercase(va_list ap, char flag, int width, char length);
int print_str_wide(va_list ap, char flag, int width, char length);
int print_pointer(va_list ap, char flag, int width, char length);
int print_reverse(va_list ap, char flag, int width, char length);
int print_rot13(va_list ap, char flag, int width, char length);

/* helper functions */
int _strlen(const char *s);
char *_strrev(char *str);
char *_itoa(unsigned long int num, int base);
void _toupper(char *str);
int _isprint(char c);
char *get_code(char c);
char get_flag(char flag);
char get_length(char c);
int get_width(const char **format);
int _isdigit(char c);
long int get_int(va_list ap, char length);
unsigned long int get_unsigned_int(va_list ap, char length);

#endif

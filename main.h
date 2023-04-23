#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

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

/* helper functions */
int _strlen(const char *s);

#endif

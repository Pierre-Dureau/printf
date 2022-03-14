#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Specifier
{
	char c;
	int (*f)(va_list list);
} spec_t;

int _printf(const char *format, ...);
int (*get_specifier(char c))(va_list);

int _putchar(char c);
int _puts(char *str);
void print_number(int n);

int print_string(va_list list);
int print_char(va_list list);
int countDigit(int n);
int print_int(va_list list);

int print_binary(va_list);
int print_octal(va_list);
int print_hex(va_list);
int print_hex_maj(va_list);
int print_unsigned(va_list);

#endif /* MAIN_H */

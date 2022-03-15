#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct Flag - Struct Flag
 *
 * @plus: '+' char
 * @space: ' ' char
 * @diese: '#' char
 * @count: number of flags
 */
typedef struct Flag
{
	int plus;
	int space;
	int diese;
	int count;
} flag_t;

/**
 * struct Specifier - Struct specifier
 * @c: The specifier
 * @f: The function
 */
typedef struct Specifier
{
	char c;
	int (*f)(va_list, flag_t);
} spec_t;

int _printf(const char *format, ...);
int (*get_specifier(char c))(va_list, flag_t);
int _putchar(char c);
int _puts(char *str);
void print_number(int n);
int print_string(va_list, flag_t);
int print_char(va_list, flag_t);
int countDigit(int n);
int print_int(va_list, flag_t);
int print_binary(va_list, flag_t);
int print_octal(va_list, flag_t);
int print_hex(va_list, flag_t);
int print_hex_maj(va_list, flag_t);
int print_unsigned(va_list, flag_t);
int print_custom(va_list, flag_t);
int print_rot13(va_list, flag_t);
int print_rev(va_list, flag_t);
int print_adresse(va_list, flag_t);
flag_t get_flags(const char *s);

#endif /* MAIN_H */

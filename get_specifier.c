#include "main.h"

/**
 * get_specifier - Get the specifier object
 *
 * @c: The specifier
 * Return: The pointer to the function
 */

int (*get_specifier(char c))(va_list)
{
	int i;
	spec_t function[] = {
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hex_maj},
		{'u', print_unsigned},
		{'r', print_rev},
		{'R', print_rot13},
		{'p', print_adresse},
		{'S', print_custom}
		};

	for (i = 0; i < 13; i++)
	{
		if (function[i].c == c)
			return (function[i].f);
	}
	return (NULL);
}

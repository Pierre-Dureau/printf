#include "main.h"

/**
 * get_specifier - Get the specifier object
 *
 * @param c
 * @return int(*)(va_list)
 */

int (*get_specifier(char c))(va_list)
{
	int i;
	spec_t function[] = {
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'i', print_int},
		};

	for (i = 0; i < 4; i++)
	{
		if (function[i].c == c)
			return (function[i].f);
	}
	return (NULL);
}

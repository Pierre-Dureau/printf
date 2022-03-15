#include "main.h"

/**
 * print_string - Print a string
 * @flag: Flag parameters
 * @list: A string of the list
 * Return: Number of char printed
 */

int print_string(va_list list, flag_t flag)
{
	char *s = va_arg(list, char *);

	if (!s)
		s = "(null)";

	(void)flag;
	return (_puts(s));
}

/**
 * print_char - Print a char
 * @flag: Flag parameters
 * @list: A char of the list
 * Return: Number of char printed
 */

int print_char(va_list list, flag_t flag)
{
	(void)flag;
	return (_putchar(va_arg(list, int)));
}


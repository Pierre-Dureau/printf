#include "main.h"

/**
 * print_string - Print a string
 * @list: A string of the list
 * Return: Number of char printed
 */

int print_string(va_list list)
{
	return(_puts(va_arg(list, char *)));
}

/**
 * print_char - Print a char
 * @list: A char of the list
 * Return: Number of char printed
 */

int print_char(va_list list)
{
	return(_putchar(va_arg(list, int)));
}

#include "main.h"

/**
 * print_adresse - Print an adresse of a pointer
 *
 * @list: An adresse of the list
 * Return: Number of char printed
 */

int print_adresse(va_list list)
{
	unsigned long int num = va_arg(list, unsigned long int);
	static const char number[] = "0123456789abcdef";
	static char buffer[20];
	char *ptr;

	ptr = &buffer[19];
	*ptr = '\0';
	do {
		*--ptr = number[num % 16];
		num /= 16;
	} while (num != 0);

	*--ptr = 'x';
	*--ptr = '0';

	return (_puts(ptr) + 1);
}

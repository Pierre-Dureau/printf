#include "main.h"

/**
 * countDigit - Count the number of digit in an int
 * @n: The int
 * Return: The count
 */

int countDigit(int n)
{
	int i = 0, m = 0;

	if (n < 0)
		m = 1;
	while (n /= 10)
		i++;

	return (i + m + 1);
}

/**
 * print_int - Print an int
 * @list: An int of the list
 * Return: Number of char printed
 */

int print_int(va_list list)
{
	int n = va_arg(list, int);
	int count = countDigit(n);

	print_number(n);
	return(count);
}

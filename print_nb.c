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

int u_countDigit(unsigned int n)
{
	int len = 1;

	while (n / 10)
	{
		n /= 10;
		len *= 10;
	}
	return (len);
}

int print_unsigned(va_list arg)
{
	int nb_char = 0, digit, c;
	unsigned int n = va_arg(arg, unsigned int);

	digit = u_countDigit(n);
	while (digit)
	{
		c = n / digit + '0';
		write(1, &c, 1);
		nb_char++;
		n %= digit;
		digit /= 10;
	}
	return (nb_char);
}

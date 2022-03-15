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

int print_int(va_list list, flag_t flag)
{
	int n = va_arg(list, int);
	int count = countDigit(n);

	if (flag.plus == 1 && n >= 0)
		count += _putchar('+');
	if (flag.space == 1 && flag.plus == 0)
		count += _putchar(' ');

	print_number(n);
	return (count);
}

/**
 * u_countDigit - Count the number of digit in an unsigned int
 * @n: The unsigned int
 * Return: The count
 */
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

/**
 * print_unsigned - Print an unsigned int
 * @arg: parameter to print
 * Return: Number of printed char
 */
int print_unsigned(va_list arg, flag_t flag)
{
	int nb_char = 0, digit;
	unsigned int n = va_arg(arg, unsigned int);

	digit = u_countDigit(n);
	while (digit)
	{
		_putchar(n / digit + '0');
		nb_char++;
		n %= digit;
		digit /= 10;
	}
	return (nb_char);
}

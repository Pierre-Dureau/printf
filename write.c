#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	write(1, &c, 1);

	return (1);
}

/**
 * _puts - Print a string
 * @str: the string
 * Return: Number of char printed
 */

int _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i - 1);
}

/**
 * print_number - Print an int
 * @n: The int
 */

void print_number(int n)
{
	int a = 0;

	if (n == -2147483648)
	{
		n /= 10;
		a = 1;
	}

	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}

	if (n / 10)
		print_number(n / 10);

	_putchar(n % 10 + '0');

	if (a == 1)
		_putchar('8');
}

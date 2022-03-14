#include "main.h"

/**
 * print_string - Print a string
 * @list: A string of the list
 * Return: Number of char printed
 */

int print_string(va_list list)
{
	char *s = va_arg(list, char *);

	if (!s)
		s = "(null)";

	return (_puts(s));
}

/**
 * print_char - Print a char
 * @list: A char of the list
 * Return: Number of char printed
 */

int print_char(va_list list)
{
	return (_putchar(va_arg(list, int)));
}

/**
 * heX - convert into hex and print
 * @num: number to convert
 * Return: number of printed char
 */
int heX(unsigned int num)
{
	int nb_char;
	unsigned int base = num;
	static const char number[] = "0123456789ABCDEF";
	static char buffer[10];
	char *ptr;

	ptr = &buffer[9];
	*ptr = '\0';
	do {
		*--ptr = number[num % 16];
		num /= 16;
	} while (num != 0);
	if (base <= 15)
		*--ptr = '0';
	nb_char = print_str(ptr);
	return (nb_char);
}
/**
 * custom_string - print a string even non printable one via their hex value
 * @arg: parameter to print
 * Return: number of printed char
 */
int custom_string(va_list arg)
{
	int i, nb_char = 0;
	char *str = va_arg(arg, char *);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			nb_char += _putchar('\\');
			nb_char += _putchar('x');
			nb_char += heX(str[i]);
		}
		else
			nb_char += _putchar(str[i]);
	}
	return (nb_char);
}

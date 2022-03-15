#include "main.h"

/**
 * print_custom - print a string even non printable one via their hex value
 * @arg: parameter to print
 * Return: number of printed char
 */
int print_custom(va_list arg)
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

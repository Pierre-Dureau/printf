#include "main.h"

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
	nb_char = _puts(ptr);
	return (nb_char);
}

/**
 * print_custom - print a string even non printable one via their hex value
 * @arg: parameter to print
 * @flag: Flag parameters
 * Return: number of printed char
 */
int print_custom(va_list arg, flag_t flag)
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

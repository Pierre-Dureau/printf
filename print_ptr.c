#include "main.h"

/**
 * print_adresse - Print an adresse of a pointer
 * @flag: Flag parameters
 * @list: An adresse of the list
 * Return: Number of char printed
 */

int print_adresse(va_list list, flag_t flag)
{
	unsigned long int num = va_arg(list, unsigned long int);

	if (num)
	{
		static const char number[] = "0123456789abcdef";
		static char buffer[20];
		char *ptr;
		int m = 0;

		if (flag.plus == 1)
		{
			_putchar('+');
			m = 1;
		}
		if (flag.space == 1 && flag.plus != 1)
		{
			_putchar(' ');
			m = 1;
		}

		ptr = &buffer[19];
		*ptr = '\0';
		do {
			*--ptr = number[num % 16];
			num /= 16;
		} while (num != 0);

		*--ptr = 'x';
		*--ptr = '0';

		return (_puts(ptr) + m);
	}
	else
		return (_puts("(nil)") + 1);

}

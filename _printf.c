#include "main.h"

/**
 * _printf - Produce output according to a format
 * @format: The string containing the format
 * Return: Number of printed char
 */

int _printf(const char *format, ...)
{
	int nb = 0, i = 0;
	int (*ptr)(va_list);
	va_list list;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(list, format);

	for (; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				nb += _putchar('%');
				continue;
			}
			ptr = get_specifier(format[i]);
			if (ptr)
				nb += ptr(list);
			else
				_putchar('%');
		}
		else
			nb += _putchar(format[i]);
	}

	va_end(list);
	return (nb);
}

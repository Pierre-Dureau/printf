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

	va_start(list, format);

	if (!format || (format[i] == '%' && !format[i + 1]))
		return (-1);

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
		}
		else
			nb += _putchar(format[i]);
	}

	va_end(list);
	return (nb);
}

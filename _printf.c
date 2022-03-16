#include "main.h"
#include <string.h>

/**
 * get_flags - Get the flags object
 * @s: The string
 * Return: The flag
 */

flag_t get_flags(const char *s)
{
	flag_t flag = {0, 0, 0, 0};

	while (*s == '+' || *s == ' ' || *s == '#')
	{
		if (*s == '+')
			flag.plus = 1;
		if (*s == ' ')
			flag.space = 1;
		if (*s == '#')
			flag.diese = 1;
		s++;
		flag.count += 1;
	}

	return (flag);
}

/**
 * _printf - Produce output according to a format
 * @format: The string containing the format
 * Return: Number of printed char
 */

int _printf(const char *format, ...)
{
	int nb = 0;
	int (*ptr)(va_list, flag_t);
	va_list list;
	flag_t flag = {0, 0, 0, 0};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(list, format);

	for (; *format; format++)
	{
		memset(&flag, 0, sizeof(flag_t));
		if (*format == '%')
		{
			format++;
			if (!*format)
				break;
			if (*format == '+' || *format == ' ' || *format == '#')
			{
				flag = get_flags(format);
				format += flag.count;
			}
			ptr = get_specifier(*format);
			if (ptr)
				nb += ptr(list, flag);
			else
			{
				nb += _putchar('%');
				nb += _putchar(*format);
			}
		}
		else
			nb += _putchar(*format);
	}
	va_end(list);
	return (nb);
}

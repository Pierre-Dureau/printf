#include "main.h"

/**
 * @brief
 *
 * @param format
 * @param ...
 * @return int
 */

int _printf(const char *format, ...)
{
	int nb = 0, i = 0;
	int (* ptr)(va_list);
	va_list list;

	va_start(list, format);

	if (!format)
		return (0);

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

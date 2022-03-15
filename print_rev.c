#include "main.h"
/**
 * _strlen - return the length of a string
 * @s: char value
 * Return: length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;
	return (length);
}
/**
 * print_rev - print a string in reverse
 * @arg: parameter to print
 * @flag: Flag parameters
 * Return: number of printed characters
 */
int print_rev(va_list arg, flag_t flag)
{
	int length, i, nb_char = 0;
	char *s = va_arg(arg, char *);

	length = _strlen(s) - 1;
	for (i = length; i >= 0; i--)
	{
		_putchar(s[i]);
		nb_char++;
	}
	return (nb_char);
}

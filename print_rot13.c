#include "main.h"
/**
 * print_rot13 - print a string encoded using rot13
 * @flag: Flag parameters
 * @arg: parameter to encode
 * Return: number of printed char
 */
int print_rot13(va_list arg, flag_t flag)
{
	int i, j, nb_char = 0;
	char ch1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ch2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(arg, char *);

	for (i = 0; str[i]; i++, nb_char++)
	{
		for (j = 0; ch1[j]; j++)
		{
			if (str[i] == ch1[j])
			{
				_putchar(ch2[j]);
				break;
			}
		}
		if (str[i] != ch1[j])
			_putchar(str[i]);
	}
	(void)flag;
	return (nb_char);
}

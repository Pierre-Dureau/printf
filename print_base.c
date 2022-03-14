#include "main.h"

int print_str(char *str)
{
	int i, nb_char = 0;

	for (i = 0; str[i]; i++)
	{
		write(1, &str[i], 1);
		nb_char++;
	}
	return (nb_char);
}

int print_binary(va_list arg)
{
	int nb_char, num = va_arg(arg, int);
	static char buffer[33];
	char *ptr;

	ptr = &buffer[32];
	*ptr = '\0';
	do
	{
		*--ptr = (num % 2) + '0';
		num /= 2;
	}while(num != 0);
	nb_char = print_str(ptr);
	return(nb_char);
}

int print_octal(va_list arg)
{
	int nb_char;
	unsigned int num = va_arg(arg, unsigned int);
	static char buffer[13];
	char *ptr;

	ptr = &buffer[12];
	*ptr = '\0';
	do
	{
		*--ptr = (num % 8) + '0';
		num /= 8;
	}while(num != 0);
	nb_char = print_str(ptr);
	return(nb_char);
}

int print_hex(va_list arg)
{
	int nb_char;
	unsigned int num = va_arg(arg, unsigned int);
	static char number[] = "0123456789abcdef";
	static char buffer[10];
	char *ptr;

	ptr = &buffer[9];
	*ptr = '\0';
	do
	{
		*--ptr = number[num % 16];
		num /= 16;
	}while(num != 0);
	nb_char = print_str(ptr);
	return(nb_char);
}

int print_hex_maj(va_list arg)
{
	int nb_char;
	unsigned int num = va_arg(arg, unsigned int);
	static char number[] = "0123456789ABCDEF";
	static char buffer[10];
	char *ptr;

	ptr = &buffer[9];
	*ptr = '\0';
	do
	{
		*--ptr = number[num % 16];
		num /= 16;
	}while(num != 0);
	nb_char = print_str(ptr);
	return(nb_char);
}

#include "main.h"
/**
 * print_binary - convert into binary and print
 * @arg: parameter to convert
 * @flag: flag parameter
 * Return: number of printed char
 */
int print_binary(va_list arg, flag_t flag)
{
	int nb_char;
	unsigned int num = va_arg(arg, unsigned int);
	static char buffer[33];
	char *ptr;

	ptr = &buffer[32];
	*ptr = '\0';
	do {
		*--ptr = (num % 2) + '0';
		num /= 2;
	} while (num != 0);
	nb_char = _puts(ptr);
	return (nb_char);
}
/**
 * print_octal - convert into octal and print
 * @arg: parameter to convert
 * @flag: flag parameter
 * Return: number of printed char
 */
int print_octal(va_list arg, flag_t flag)
{
	int nb_char;
	unsigned int num = va_arg(arg, unsigned int);
	static char buffer[13];
	char *ptr;

	ptr = &buffer[12];
	*ptr = '\0';
	do {
		*--ptr = (num % 8) + '0';
		num /= 8;
	} while (num != 0);
	if (flag.diese == 1)
		nb_char += _putchar('0');
	nb_char += _puts(ptr);
	return (nb_char);
}
/**
 * print_hex - convert into hex and print
 * @arg: parameter to convert
 * @flag: flag parameter
 * Return: number of printed char
 */
int print_hex(va_list arg, flag_t flag)
{
	int nb_char;
	unsigned int num = va_arg(arg, unsigned int);
	static const char number[] = "0123456789abcdef";
	static char buffer[10];
	char *ptr;

	ptr = &buffer[9];
	*ptr = '\0';
	do {
		*--ptr = number[num % 16];
		num /= 16;
	} while (num != 0);
	if (flag.diese == 1)
		nb_char += _puts("0x");
	nb_char += _puts(ptr);
	return (nb_char);
}
/**
 * print_hex_maj - convert into hex and print
 * @arg: parameter to convert
 * @flag: flag parameter
 * Return: number of printed char
 */
int print_hex_maj(va_list arg, flag_t flag)
{
	int nb_char;
	unsigned int num = va_arg(arg, unsigned int);
	static const char number[] = "0123456789ABCDEF";
	static char buffer[10];
	char *ptr;

	ptr = &buffer[9];
	*ptr = '\0';
	do {
		*--ptr = number[num % 16];
		num /= 16;
	} while (num != 0);
	if (flag.diese == 1)
		nb_char += _puts("0X");
	nb_char += _puts(ptr);
	return (nb_char);
}

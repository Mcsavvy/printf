#include "main.h"

/**
 * match_octal - matches a base8 format specifier
 * @fmt: format string
 * Return: the number of characters matched
 */
int match_octal(char *fmt)
{
	if (fmt[0] == 'o')
		return (1);
	return (0);
}

/**
 * print_octal - prints a number from a variadic argument
 *			in base8
 * @fmt: format string
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int print_octal(char *fmt, va_list args)
{
	(void)fmt;
	return (print_unsigned_int(va_arg(args, unsigned int), 8, false));
}

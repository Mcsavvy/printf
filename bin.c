#include "main.h"

/**
 * match_binary - matches a base2 format specifier
 * @fmt: format string
 * Return: the number of characters matched
 */
int match_binary(char *fmt)
{
	if (fmt[0] == 'b')
		return (1);
	return (0);
}

/**
 * print_binary - prints a number from a variadic argument
 *			in base2
 * @fmt: format string
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int print_binary(char *fmt, va_list args)
{
	(void)fmt;
	return (print_unsigned_int(
		va_arg(args, unsigned int),
		2, false)
	);
}

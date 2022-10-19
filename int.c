#include "main.h"

/**
 * match_int - matches an int format specifier
 * @fmt: format string
 * Return: the number of characters matched
 */
int match_int(char *fmt)
{
	if (fmt[0] == 'i' || fmt[0] == 'd')
		return (1);
	return (0);
}

/**
 * match_uint - matches an unsigned int format specifier
 * @fmt: format string
 * Return: the number of characters matched
 */
int match_uint(char *fmt)
{
	if (fmt[0] == 'u')
		return (1);
	return (0);
}


/**
 * print_int - prints an integer from a variadic argument
 * @fmt: format string
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int print_int(char *fmt, va_list args)
{
	(void)fmt;
	return (print_signed_int(va_arg(args, int), 10, false));
}

/**
 * print_uint - prints an unsigned integer from a variadic argument
 * @fmt: format string
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int print_uint(char *fmt, va_list args)
{
	(void)fmt;
	return (print_unsigned_int(va_arg(args, unsigned int), 10, false));
}

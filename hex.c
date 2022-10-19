#include "main.h"

/**
 * match_address - matches an address format specifier
 * @fmt: format string
 * Return: the number of characters matched
 */
int match_address(char *fmt)
{
	if (fmt[0] == 'p')
		return (1);
	return (0);
}

/**
 * match_hexadecimal - matches a hexadecimal format specifier
 * @fmt: format string
 * Return: the number of characters matched
 */
int match_hexadecimal(char *fmt)
{
	if (fmt[0] == 'X' || fmt[0] == 'x')
		return (1);
	return (0);
}


/**
 * print_address - prints an address from a variadic argument
 * @fmt: format string
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int print_address(char *fmt, va_list args)
{
	(void)fmt;
	_putchar('0');
	_putchar('x');
	return (2 + print_unsigned_long(va_arg(args, unsigned long), 16, false));
}

/**
 * print_hexadecimal - prints a hexadecimal from a variadic argument
 * @fmt: format string
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int print_hexadecimal(char *fmt, va_list args)
{
	bool uppercase = (fmt[0] == 'X') ? true : false;

	return (print_unsigned_int(va_arg(args, unsigned int), 16, uppercase));
}

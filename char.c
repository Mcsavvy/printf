#include "main.h"

/**
 * match_char - matches a character format specifier
 * @fmt: format string
 * Return: the number of characters matched
 */
int match_char(char *fmt)
{
	if (fmt[0] == 'c')
		return (1);
	return (0);
}

/**
 * match_percent - matches a %% format specifier
 * @fmt: format string
 * Return: the number of characters matched
 */
int match_percent(char *fmt)
{
	if (fmt[0] == '%')
		return (1);
	return (0);
}

/**
 * print_char - prints a character from a variadic argument
 * @fmt: format string
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int print_char(char *fmt, va_list args)
{
	(void)fmt;
	return (_putchar(va_arg(args, int)));
}

/**
 * print_percent - prints a percent from a variadic argument
 * @fmt: format string
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int print_percent(char *fmt, va_list args)
{
	(void)fmt;
	(void)args;
	return (_putchar('%'));
}

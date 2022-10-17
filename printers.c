#include "headers/parser.h"
#include "headers/strings.h"
#include "headers/macros.h"
#include "headers/numbers.h"
#include <stdarg.h>

int print_char(char *b, va_list args)
{
	(void)b;
	return (_putchar(va_arg(args, int)));
}

int print_string(char *b, va_list args)
{
	b = va_arg(args, char *);
	return (print(b, lenstr(b)));
}

int print_percent(char *b, va_list args)
{
	(void)b;
	(void)args;
	_putchar('%');
	return (0);
}

int print_int(char *b, va_list args)
{
	(void)b;
	return (print_signed(va_arg(args, int), 10, false));
}

int print_uint(char *b, va_list args)
{
	(void)b;
	return (print_unsigned(va_arg(args, unsigned int), 10, false));
}

int print_address(char *b, va_list args)
{
	(void)b;
	_putchar('0');
	_putchar('x');
	return (2 + print_unsigned_long(va_arg(args, unsigned long), 16, false));
}

int print_hexadecimal(char *b, va_list args)
{
	bool uppercase = (b[0] is 'X') ? true : false;
	return (print_unsigned(va_arg(args, unsigned int), 16, uppercase));	
}

int print_octal(char *b, va_list args)
{
	(void)b;
	return (print_unsigned(va_arg(args, unsigned int), 8, false));
}
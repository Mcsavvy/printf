#include "headers/parser.h"
#include "headers/strings.h"
#include "headers/macros.h"
#include "headers/numbers.h"
#include <stdarg.h>
#include <stdlib.h>

int print_char(char *b, va_list args)
{
	(void)b;
	return (_putchar(va_arg(args, int)));
}

int print_string(char *b, va_list args)
{
	char *s = va_arg(args, char *);
	int length = 0, i;
	char c;

	switch (b[0])
	{
	case 's':
		length = print(s, lenstr(s));
		break;
	case 'S':
		for (i = 0; s[i] isnot nullbyte; i++)
		{
			c = s[i];
			if ((c > 0 and c < 32) or c >= 127)
			{
				length += _putchar('\\');
				length += _putchar('x');
				if (c < 16)
					length += _putchar('0');
				length += print_unsigned(c, 16, true);
			}
			else
				length += _putchar(c);
		}
		break;
	case 'R':
		for (i = 0; s[i] isnot nullbyte; i++)
		{
			c = s[i];
			if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
				c += 13;
			else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
				c -= 13;
			length += _putchar(c);
		}
		break;
	case 'r':
		s = reverse(s);
		if (s == (void *)0)
			break;
		length = print(s, lenstr(s));
		free(s);
		break;
	default:
		break;
	}
	return (length);

}

int print_percent(char *b, va_list args)
{
	(void)b;
	(void)args;
	return (_putchar('%'));
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

int print_binary(char *b, va_list args)
{
	(void)b;
	return (print_unsigned(va_arg(args, unsigned int), 2, false));
}

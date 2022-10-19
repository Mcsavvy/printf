#include "main.h"

/**
 * match_string - matches a string format specifier
 * @fmt: format string
 * Return: the number of characters matched
 */
int match_string(char *fmt)
{
	int i;
	char specifiers[] = "sSRr";

	for (i = 0; i < 4; i++)
		if (fmt[0] == specifiers[i])
			return (1);
	return (0);
}

/**
 * rot13 - prints a rot13ed string
 * @str: target string
 * Return: the number of characters printed
 */
int rot13(char *str)
{
	int i, length = 0;
	char c;

	for (i = 0; str[i] != nullbyte; i++)
	{
		c = str[i];
		if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
			c += 13;
		else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
			c -= 13;
		length += _putchar(c);
	}
	return (length);
}

/**
 * hexed - prints a string where all non-visual
 *		characters are converted to their hex form
 * @str: target string
 * Return: number of characters printed
 */
int hexed(char *str)
{
	char c;
	int i, length = 0;

	for (i = 0; str[i] != nullbyte; i++)
	{
		c = str[i];
		if ((c > 0 && c < 32) || c >= 127)
		{
			length += _putchar('\\');
			length += _putchar('x');
			if (c < 16)
				length += _putchar('0');
			length += print_unsigned_int(c, 16, true);
		}
		else
			length += _putchar(c);
	}
	return (length);
}

/**
 * print_string - prints a string from a variadic argument
 * @fmt: format string
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int print_string(char *fmt, va_list args)
{
	char *s = va_arg(args, char *);
	int length = 0, i;

	switch (fmt[0])
	{
	case 's':
		length = print(s, lenstr(s));
		break;
	case 'S':
		length += hexed(s);
		break;
	case 'R':
		length += rot13(s);
		break;
	case 'r':
		i = lenstr(s);
		while (i-- > 0)
			length += _putchar(s[i]);
		break;
	default:
		break;
	}
	return (length);

}

#include "main.h"

/**
 * getdigit - get character representation of a digit
 * @n: digit
 * @uppercase: true or false (for hex digitss above 10)
 * Return: a character representation of the number supplied
 */
char getdigit(int n, bool uppercase)
{
	char *lower = "0123456789abcdefghi";
	char *upper = "0123456789ABCDEFGHI";

	if (uppercase)
		return (upper[n]);
	else
		return (lower[n]);
}

/**
 * print_signed_int - prints a signed integer in any base
 * @n: integer to print
 * @base: base to print (e.g 16)
 * @uppercase: print in uppercase
 * Return: length of digits printed
 */
int print_signed_int(int n, unsigned int base, bool uppercase)
{
	int length = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		length++;
	}
	if (n < (int)base)
	{
		return (length + _putchar(getdigit(n, uppercase)));

	}
	length += print_signed_int(n / base, base, uppercase);
	length += _putchar(getdigit(n % base, uppercase));
	return (length);
}

/**
 * print_unsigned_int - prints an unsigned integer in any base
 * @n: integer to print
 * @base: base to print (e.g 16)
 * @uppercase: print in uppercase
 * Return: length of digits printed
 */
int print_unsigned_int(unsigned int n, unsigned int base, bool uppercase)
{
	int length = 0;

	if (n < base)
	{
		return (length + _putchar(getdigit(n, uppercase)));

	}
	length += print_unsigned_int(n / base, base, uppercase);
	length += _putchar(getdigit(n % base, uppercase));
	return (length);
}

/**
 * print_signed_long - prints a signed long integer in any base
 * @n: integer to print
 * @base: base to print (e.g 16)
 * @uppercase: print in uppercase
 * Return: length of digits printed
 */
int print_signed_long(long int n, unsigned int base, bool uppercase)
{
	int length = 0;

	if (n < base)
	{
		return (length + _putchar(getdigit(n, uppercase)));

	}
	length += print_signed_long(n / base, base, uppercase);
	length += _putchar(getdigit(n % base, uppercase));
	return (length);
}

/**
 * print_unsigned_long - prints an unsigned long integer in any base
 * @n: integer to print
 * @base: base to print (e.g 16)
 * @uppercase: print in uppercase
 * Return: length of digits printed
 */
int print_unsigned_long(unsigned long int n, unsigned int base, bool uppercase)
{
	int length = 0;

	if (n < base)
	{
		return (length + _putchar(getdigit(n, uppercase)));

	}
	length += print_unsigned_long(n / base, base, uppercase);
	length += _putchar(getdigit(n % base, uppercase));
	return (length);
}


#include "headers/numbers.h"
#include "headers/macros.h"
#include "headers/strings.h"
#include <assert.h>

char getdigit(int n, bool uppercase)
{
	char *lower = "0123456789abcdefghi";
	char *upper = "0123456789ABCDEFGHI";
	assert(n < 18);
	if (uppercase)
		return (upper[n]);
	else
		return (lower[n]);
}


int print_signed(int n, unsigned int base, bool uppercase)
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
	length += print_signed(n / base, base, uppercase);
	length += _putchar(getdigit(n % base, uppercase));
	return (length);
}

int print_unsigned(unsigned int n, unsigned int base, bool uppercase)
{
	int length = 0;

	if (n < base)
	{
		return (length + _putchar(getdigit(n, uppercase)));

	}
	length += print_unsigned(n / base, base, uppercase);
	length += _putchar(getdigit(n % base, uppercase));
	return (length);
}

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


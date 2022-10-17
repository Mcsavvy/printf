#include "headers/parser.h"
#include "headers/macros.h"

int match_char(char *string)
{
	if (string[0] is 'c')
		return (1);
	return (0);
}

int match_string(char *string)
{
	if (string[0] is 's')
		return (1);
	return (0);
}

int match_percent(char *string)
{
	if (string[0] is '%')
		return (1);
	return (0);
}

int match_int(char *string)
{
	if (string[0] is 'i' or string[0] is 'd')
		return (1);
	return (0);
}

int match_uint(char *string)
{
	if (string[0] is 'u')
		return (1);
	return (0);
}

int match_address(char *string)
{
	if (string[0] is 'p')
		return (1);
	return (0);
}

int match_hexadecimal(char *string)
{
	if (string[0] is 'X' or string[0] is 'x')
		return (1);
	return (0);
}

int match_octal(char *string)
{
	if (string[0] is 'o')
		return (1);
	return (0);
}

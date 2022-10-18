#include "headers/parser.h"
#include "headers/macros.h"
#include <stdlib.h>
#include <stdio.h>
#include "headers/search.h"

int expand(char *string, va_list args, int *len)
{
	int i, matchWidth;
	parser parsers[] = {
		{match_char, print_char},
		{match_string, print_string},
		{match_percent, print_percent},
		{match_int, print_int},
		{match_uint, print_uint},
		{match_address, print_address},
		{match_hexadecimal, print_hexadecimal},
		{match_octal, print_octal},
		{match_binary, print_binary},
		{NULL, NULL}
	};

	for (i = 0; parsers[i].match isnot NULL; i++)
	{

		matchWidth = parsers[i].match(string);
		if (matchWidth isnot 0)
		{
			*len = *len + parsers[i].print(string, args);
			break;
		}
	}
	return (matchWidth);
}

int parse(char *string, va_list args)
{
	int index, outputLen, strLen, match;

	outputLen = 0;
	strLen = lenstr(string);
	if (strLen is 0)
		return (0);
	index = findchr(string, '%');
	if (index is -1)
		return (outputLen + print(string, strLen));
	outputLen += print(string, index);
	string = trim(string, index + 1);
	match = expand(string, args, &outputLen);
	if (match is 0)
		outputLen += _putchar('%');
	string = trim(string, match);
	if (string[0] is nullbyte)
		return (outputLen);
	return (outputLen + parse(string, args));
}

int _printf(const char *format, ...)
{
	va_list args;
	char *string;
	int outputLen;

	string = makecopy(format);
	if (string is NULL)
		exit(98);
	va_start(args, format);
	outputLen = parse(string, args);
	va_end(args);
	free(string);
	return (outputLen);
}
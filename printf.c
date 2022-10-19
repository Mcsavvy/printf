#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * expand - expand a format specifier into an actual value
 * @string: format string
 * @args: variadic arguments
 * @len: length of characters printed
 * Return: width of specifier
 */
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

	for (i = 0; parsers[i].match != NULL; i++)
	{

		matchWidth = parsers[i].match(string);
		if (matchWidth != 0)
		{
			*len = *len + parsers[i].print(string, args);
			break;
		}
	}
	return (matchWidth);
}

/**
 * parse - parse a string along with format specifiers
 * @string: string to parse
 * @args: variadic arguments
 * Return: number of characters printed
 */
int parse(char *string, va_list args)
{
	int index, outputLen, strLen, match;

	outputLen = 0;
	strLen = lenstr(string);
	if (strLen == 0)
	{
		_putchar('\0');
		return (0);
	}
	index = findchr(string, '%');
	if (index == -1)
	{
		outputLen += print(string, strLen);
		_putchar('\0');
		return (outputLen);
	}
	outputLen += print(string, index);
	string += index + 1;
	match = expand(string, args, &outputLen);
	if (match == 0)
		outputLen += _putchar('%');
	string += match;
	if (string[0] == nullbyte)
	{
		_putchar('\0');
		return (outputLen);
	}
	return (outputLen + parse(string, args));
}

/**
 * _printf - prints formatted string
 * @format: format string
 * Return: length of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *fmt;
	int outputLen, i;

	fmt = (char *)malloc(lenstr(format) + 1);

	if (fmt == NULL)
		return (0);
	for (i = 0; i < lenstr(format); i++)
		fmt[i] = format[i];
	fmt[i] = nullbyte;
	va_start(args, format);
	outputLen = parse(fmt, args);
	va_end(args);
	free(fmt);
	return (outputLen);
}

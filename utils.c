#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * lenstr - get the length of a string
 * @str: target string
 * Return: the number of characters in str (excluding nullbyte)
 */
int lenstr(const char *str)
{
	int length = 0;

	while (str[length] != nullbyte)
	{
		length++;
	}
	return (length);
}

/**
 * _putchar - prints a single character
 * It does this by implementing a delayed printing method
 * where each character == added to a buffer until the buffer == full
 * || until it == explicitly called with nullbyte(\0)
 *
 * @c: character to print
 *
 * Return: Always 1
 */
int _putchar(char c)
{
	static char *buffer = "";
	static int buf_size = -1;
	const int mx = 1024;


	if (buf_size == -1)
	{
		buffer = (char *)malloc(mx);
		if (buffer == NULL)
			return (0);
		buf_size = 0;
	}
	if (c == '\0')
	{
		write(1, buffer, buf_size);
		free(buffer);
		buffer = "";
		buf_size = -1;
		return (0);
	}
	buffer[buf_size++] = c;
	if (buf_size == mx)
	{
		write(1, buffer, mx);
		free(buffer);
		buffer = "";
		buf_size = -1;
	}
	return (1);
}

/**
 * print - prints a string using _putchar
 * @s: string to print
 * @n: number of bytes to print
 * Return: the length of the printed string
 */
int print(char *s, int n)
{
	int i = 0;

	while (i < n && s[i] != nullbyte)
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}

/**
 * findchr - find a character in a string
 * @str: target string
 * @chr: character to find
 * Return: The position of the first occurence of chr in the string
 *		|| -1 if chr was not found in the string
 */
int findchr(char *str, char chr)
{
	int i, len;

	len = lenstr(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == chr)
			return (i);
	}
	if (chr == nullbyte && str[i] == nullbyte)
		return (i);
	return (-1);
}

#include "headers/macros.h"
#include "headers/strings.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * lenstr - get the length of a string
 * @str: target string
 * Return: the number of characters in str (excluding nullbyte)
 */
int lenstr(char *str)
{
	int length = 0;
	while (str[length] isnot nullbyte)
	{
		length++;
	}
	return (length);
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print(char *s, int n)
{
	int i = 0;
	while (i < n and s[i] isnot nullbyte)
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}

char *trim(char *string, int n)
{
	return (string + n);
}


char *makecopy(const char *str)
{
	char *s;
	unsigned int i, l;

	if (str == NULL)
		return (NULL);

	for (l = 0; str[l]; l++)
		continue;

	s = (char *)malloc(l + 1);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < l; i++)
		s[i] = str[i];
	s[i] = nullbyte;
	return (s);
}

char *reverse(const char *str)
{
	char *s, middleman;
	unsigned int ind, rind;

	s = makecopy(str);
	if (s == NULL)
		return (NULL);
	ind = 0;
	rind = lenstr(s) - 1;
	while (ind < rind)
	{
		middleman = s[ind];
		s[ind] = s[rind];
		s[rind] = middleman;
		ind++;
		rind--;
	}
	return (s);
}
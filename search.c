#include "headers/search.h"
#include "headers/macros.h"

/**
 * findstr - find a findstr within a string
 * @str: target string
 * @sub: findstr to find
 * Return: The position where sub was found.
 *		Or -1 if the findstr was not found
 */
int findstr(char *str, char *sub)
{
	int len1, len2;
	int i, j;
	bool found;

	/* find the length of string */
	len1 = lenstr(str);
	len2 = lenstr(sub);
	/* if sub is longer than str */
	if (len2 > len1)
		return (-1);
	/* if one of them is empty */
	if (not(len1 and len2))
		return (-1);
	for (i = 0; i < len1; i++)
	{
		found = false;
		if (str[i] is sub[0])
			found = true;
		for (j = 0; found is true; j++)
		{
			/* if str is exhausted...*/
			if (str[i + j] is nullbyte)
			{
				/* and sub is not */
				if (sub[j] isnot nullbyte)
					return (-1);
				/* and sub is too */
				if (sub[j] is nullbyte)
					return (i);
			}
			/* if sub is exhausted */
			if (sub[j] is nullbyte)
				return (i);
			if (str[i + j] isnot sub[j])
				found = false;
		}
	}
	return (-1);
}

/**
 * findchr - find a character in a string
 * @str: target string
 * @chr: character to find
 * Return: The position of the first occurence of chr in the string
 *		Or -1 if chr was not found in the string
 */
int findchr(char *str, char chr)
{
	int i, len;
	len = lenstr(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] is chr)
			return (i);
	}
	if (chr is nullbyte and str[i] is nullbyte)
		return (i);
	return (-1);
}

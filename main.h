#ifndef PARSER_H
#define PARSER_H
#define true 1
#define false 0
#define nullbyte '\0'
#define not(x) !(x)
#define bool char

#include <stddef.h>
#include <stdarg.h>

typedef int (*printer)(char *, va_list);
typedef int (*matcher)(char *);

/**
 * struct parser - an object representing a parser
 * functionality
 *
 * @match: a function used to check if the parser matches
 * a format specifier
 * @print: a function used to print out the value
 * associated with a format specifier
 */
typedef struct parser
{
	matcher match;
	printer print;
} parser;


int _printf(const char *, ...);

/* utilities */
int findchr(char *str, char chr);
int lenstr(const char *str);
int _putchar(char c);
int print(char *, int);

/* printers */
int print_signed_int(int n, unsigned int, bool);
int print_unsigned_int(unsigned int n, unsigned int, bool);
int print_unsigned_long(unsigned long int, unsigned int, bool);
int print_signed_long(signed long int, unsigned int, bool);

int print_percent(char *, va_list);
int print_string(char *, va_list);
int print_char(char *, va_list);
int print_int(char *, va_list);
int print_uint(char *, va_list);
int print_address(char *, va_list);
int print_hexadecimal(char *, va_list);
int print_octal(char *, va_list);
int print_binary(char *, va_list);


/* Matchers */
int match_percent(char *);
int match_char(char *);
int match_string(char *);
int match_int(char *);
int match_uint(char *);
int match_address(char *);
int match_hexadecimal(char *);
int match_octal(char *);
int match_binary(char *);



#endif

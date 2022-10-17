#ifndef PARSER_H
#define PARSER_H
#include <stdarg.h>

typedef int (*printer)(char *, va_list);
typedef int (*matcher)(char *);

typedef struct parser
{
	matcher match;
	printer print;
} parser;


int _printf(const char *, ...);
int parse(char *, va_list);

/* printers */
int print_percent(char *, va_list);
int print_string(char *, va_list);
int print_char(char *, va_list);
int print_int(char *, va_list);
int print_uint(char *, va_list);
int print_address(char *, va_list);
int print_hexadecimal(char *, va_list);
int print_octal(char *, va_list);

/* Matchers */
int match_percent(char *);
int match_char(char *);
int match_string(char *);
int match_int(char *);
int match_uint(char *);
int match_address(char *);
int match_hexadecimal(char *);
int match_octal(char *);

#endif
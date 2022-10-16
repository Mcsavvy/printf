#include <stdarg.h>

/* this just means a function pointer */
typedef int (*expander)(va_list);

int print_char();
int print_string();
int print_digit();

STRING = "#CISFUN %c %s %d";


printf("%c%s%d", 'c', "hello world", 10070089);

/**
 * this structure would be used to decide
 * which function would be used to print
 */
struct formatter {
	/**
	 * a format specifier
	 * e.g c, s, p, d
	 */
	char specifier;
	/**
	 * a function which would
	 * expand the specifier to a string
	 */
	expander fn;
};

struct formatter character = {'c', print_char};
character.specifier
character.fn

/**
 * a simple function that prints a string
 * an returns the length of what it prints
 */
int printer(char *string);

/**
 * this function is in charge of searching through
 * a string for a format specifier and returns the index
 * at which the `%` was found
 */
int search(char *string);

/**
 * this function trims the part of the string
 * that has already been processed
 */
int trim(char *string, int num_of_chars_to_trim_out);


int _printf(const char *format, ...)
{
	// code goes here
}

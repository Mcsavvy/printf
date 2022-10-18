#include "headers/parser.h"
#include <stdio.h>
#include <limits.h>

void test_standard(void)
{
		int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f00;
	len = _printf("Length:[%d, %i]\n", len, len);
	len2 = printf("Length:[%d, %i]\n", len2, len2);
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("Negative:[%d]\n", -762534);
	len2 = printf("Negative:[%d]\n", -762534);
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("Unsigned:[%u]\n", ui);
	len2 = printf("Unsigned:[%u]\n", ui);
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("Unsigned octal:[%o]\n", ui);
	len2 = printf("Unsigned octal:[%o]\n", ui);
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	len2 = printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("Address:[%p]\n", addr);
	len2 = printf("Address:[%p]\n", addr);
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Unknown:[%r]\n");
	len2 = printf("Unknown:[%r]\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
}

void test_custom(void)
{
	int len;
	len = _printf("%b\n", 98);
	_printf("Length: [%d, %i]\n", len, len);
	len = _printf("%S\n", "Best\n\tSchool");
	_printf("Length: [%d, %i]\n", len, len);
	len = _printf("%R\n", "Hello World, I'm address 0x0456fa7");
	_printf("Length: [%d, %i]\n", len, len);
	len = _printf("Hello %r\n", "Hello");
	_printf("Length: [%d, %i]\n", len, len);
}

int main(void)
{
	test_standard();
	printf("-------------------------------\n");
	test_custom();
	/* _printf("%d") */
	return (0);
}
/* "abcdefghijklmnopqrstuvwxyz" */
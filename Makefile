gccFlags := -Wall -Werror -Wextra -pedantic -std=gnu89 -g

strings.o: strings.c headers/strings.h
	gcc $(gccFlags) -c strings.c
search.o: search.c headers/search.h strings.o
	gcc $(gccFlags) -c search.c
numbers.o: numbers.c headers/numbers.h strings.o
	gcc $(gccFlags) -c numbers.c
printers.o: printers.c headers/parser.h strings.o
	gcc $(gccFlags) -c printers.c
matchers.o: matchers.c headers/parser.h
	gcc $(gccFlags) -c matchers.c
printf.o: printf.c headers/parser.h search.o
	gcc $(gccFlags) -c printf.c
main.o: main.c printf.o
	gcc $(gccFlags) -c main.c
main: strings.o search.o numbers.o printers.o matchers.o printf.o main.o
	gcc $(gccFlags) strings.o search.o numbers.o printers.o matchers.o printf.o main.o -o main

# MANPAGE
manpage.1: manpage.1.md
	pandoc manpage.1.md --standalone -t man -o manpage.1

# TESTS
test_search:
	gcc $(gccFlags) search.c strings.c test/search.c -o build/test_search
	./test/search

test_parse:
	gcc $(flags) $(parserDeps) -o build/parse
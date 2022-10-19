gccFlags := -Wall -Wno-format -Werror -Wextra -pedantic -std=gnu89 -g

bin.o: main.h bin.c
	gcc $(gccFlags) -c bin.c
oct.o: main.h oct.c
	gcc $(gccFlags) -c oct.c
hex.o: main.h hex.c
	gcc $(gccFlags) -c hex.c
int.o: main.h int.c
	gcc $(gccFlags) -c int.c
long.o: main.h long.c
	gcc $(gccFlags) -c long.c
char.o: main.h char.c
	gcc $(gccFlags) -c char.c
string.o: main.h string.c
	gcc $(gccFlags) -c string.c
search.o: search.c headers/search.h strings.o
	gcc $(gccFlags) -c search.c
numbers.o: main.h numbers.c
	gcc $(gccFlags) -c numbers.c
utils.o: main.h utils.c
	gcc $(gccFlags) -c utils.c
tests/main.o: main.h tests/main.c
	gcc $(gccFlags) -c tests/main.c -o tests/main.o
printf.o: main.h printf.c
	gcc $(gccFlags) -c printf.c
main: tests/main.o bin.o char.o hex.o int.o long.o oct.o string.o utils.o numbers.o printf.o
	gcc $(gccFlags) bin.o char.o hex.o int.o long.o oct.o string.o utils.o numbers.o tests/main.o printf.o -o tests/main

# MANPAGE
manpage.1: manpage.1.md
	pandoc manpage.1.md --standalone -t man -o manpage.1

# TESTS
test_search:
	gcc $(gccFlags) search.c strings.c test/search.c -o build/test_search
	./test/search

test_parse:
	gcc $(flags) $(parserDeps) -o build/parse
utils.o : utils.c utils.h
	gcc -c utils.c
manpage.1 : markdown.1.md
       pandoc markdown.1.md --standalone -t man manpage.1	

izvrsni : parser.tab.o lex.yy.o izraz.o naredba.o
	g++ -Wall -o $@ $^
parser.tab.o: parser.tab.cpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.h : parser.ypp
	bison -d -v $<
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -Wall -c -o $@ $<
lex.yy.c: lexer.l
	flex $^
izraz.o: izraz.cpp
	g++ -Wall -c -o $@ $<
naredba.o: naredba.cpp
	g++ -Wall -c -o $@ $<
.PHONY: clean

clean:
	-rm *.o *.c *~ izvrsni parser.tab.* parser.output

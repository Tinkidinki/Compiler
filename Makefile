.PHONY: parser clean

all: parser clean

parser: scanner.l parser.ypp
		bison -t -d -v parser.ypp
		flex scanner.l
		g++ -std=c++11 -o parser parser.tab.cpp lex.yy.c -Wall

clean: 
		rm parser.tab.cpp parser.tab.hpp lex.yy.c

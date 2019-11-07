.PHONY: parser clean

parser: scanner.l parser.ypp 
		bison -d parser.ypp
		flex scanner.l
		g++ -o parser parser.tab.cpp lex.yy.c 

clean: parser.tab.ypp parser.tab.hpp lex.yy.c -ll

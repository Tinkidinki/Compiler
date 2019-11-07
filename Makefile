.PHONY: parser clean

all: parser clean

parser: scanner.l parser.ypp
		bison -d parser.ypp
		flex scanner.l
		g++ -o parser parser.tab.cpp lex.yy.c small_test_file.cpp -Wall

# clean: 
# 		rm parser.tab.cpp parser.tab.hpp lex.yy.c

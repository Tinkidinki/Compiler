.PHONY: parser clean

parser: AST_node.h node_types_functionality.h all_nodes.h node_types_numbers.h scanner.l parser.ypp
		bison -d parser.ypp
		flex scanner.l
		g++ -std=c++11 -Wno-deprecated-register -o  parser parser.tab.cpp lex.yy.c -ll `llvm-config --cppflags --ldflags --libs core --system-libs`


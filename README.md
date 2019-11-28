# Tinki* Programming Language

Tinki* is very similar to the Decaf programming language. See the example codes in `test_programs` to get a hang of the syntax. 
The examples cover all the major features.

The following repository contains:
- `scanner.l`: Lexer for the language.
- `parser.ypp`: Parser, and main starting point of code's running.
- `ast_nodes.cpp` and `ast_node_types.cpp`: for AST Generation. The node classes form a heirarchy based on the number of children they have for pretty printing. 
- `interpreter.cpp`: Interpreter written for all code features.
- `code_generation.cpp`: Compiler written for a few code features.
- `test_programs`: The program `code_generation_test.tinki` is to be compiled. Rest to be interpreted. This is because of the different implementation of print statements in Compiler and interpreter, and lack of features in the compiler. 

This repository also contains the necessary `llvm` header files, and a few practice codes.

## To compile:
```make```

## To try out the parser, AST Generator and interpreter:
```./parser < test_programs/file.tinki```

## To try out code generation:
```./parser < test_programs/code_generation_test.tinki 2>tinki.ll```
### Look at the generated LLVM IR!
```vim tinki.ll```
### Assemble the IR to LLVM byte code.
```llvm-as tinki.ll```
### Run the byte code:
```lli tinki.bc```





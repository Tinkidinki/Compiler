%{
#define YYERROR_VERBOSE
#include <stdio.h>
%}

%token INT_LITERAL CHAR_LITERAL BOOL_LITERAL  STRING_LITERAL BAD_CHAR

%%

Goal:	expr 

expr: literal {printf("saw an expression\n");}

literal: INT_LITERAL {printf("saw an int\n");} | CHAR_LITERAL {printf("saw a char\n");} | BOOL_LITERAL {printf("saw a bool\n");} | STRING_LITERAL {printf("saw a string\n");}

%%

yyerror(char *s)
{
        fprintf(stderr, "error: %s\n", s);
}


main(int argc, char **argv)
{
        yyparse();
        printf("Parsing Over\n");
}




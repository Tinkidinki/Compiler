%{
#define YYERROR_VERBOSE
#include <stdio.h>
%}

%token  BAD_CHAR
        INT_LITERAL CHAR_LITERAL BOOL_LITERAL  STRING_LITERAL 
        ARITH_OP REL_OP EQ_OP COND_OP

%%

Goal:	expr 

expr:           literal 
        |       expr bin_op expr

literal:        INT_LITERAL {printf("saw an int\n");} 
        |       CHAR_LITERAL {printf("saw a char\n");} 
        |       BOOL_LITERAL {printf("saw a bool\n");} 
        |       STRING_LITERAL {printf("saw a string\n");}

bin_op:         ARITH_OP {printf("saw an arithmetic operator\n");} 
        |       REL_OP  {printf("saw a relational operator\n");} 
        |       EQ_OP  {printf("saw an equal operator\n");} 
        |       COND_OP  {printf("saw a conditional operator\n");} 

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




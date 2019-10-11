%{
#define YYERROR_VERBOSE
#include <stdio.h>
%}

%token  BAD_CHAR
        INT_LITERAL CHAR_LITERAL BOOL_LITERAL  STRING_LITERAL 
        ARITH_OP REL_OP EQ_OP COND_OP
        MINUS NOT 
        LEFT_ROUND RIGHT_ROUND LEFT_SQUARE RIGHT_SQUARE LEFT_CURLY RIGHT_CURLY
        ID

%%

Goal:	expr 

expr:           literal 
        |       expr bin_op expr
        |       MINUS expr
        |       NOT expr
        |       LEFT_ROUND expr RIGHT_ROUND
        |       location
        |       method_call

literal:        INT_LITERAL {printf("BISON: saw an int\n");} 
        |       CHAR_LITERAL {printf("BISON: saw a char\n");} 
        |       BOOL_LITERAL {printf("BISON: saw a bool\n");} 
        |       STRING_LITERAL {printf("BISON: saw a string\n");}

bin_op:         ARITH_OP {printf("BISON: saw an arithmetic operator\n");} 
        |       REL_OP  {printf("BISON: saw a relational operator\n");} 
        |       EQ_OP  {printf("BISON: saw an equal operator\n");} 
        |       COND_OP  {printf("BISON: saw a conditional operator\n");} 

location:       ID {printf("BISON: Sawn an ID\n");}
        |       ID LEFT_SQUARE expr RIGHT_SQUARE
        |       ID LEFT_SQUARE expr RIGHT_SQUARE LEFT_SQUARE expr RIGHT_SQUARE

// method_call:    CALLOUT LEFT_ROUND string_literal 




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




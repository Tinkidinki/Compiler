%{
#define YYERROR_VERBOSE
#include <stdio.h>
%}

%token  BAD_CHAR
        COMMA SEMICOLON EQUALS QUESTION_MARK COLON
        INT_LITERAL CHAR_LITERAL BOOL_LITERAL  STRING_LITERAL 
        
        MINUS NOT 
        LEFT_ROUND RIGHT_ROUND LEFT_SQUARE RIGHT_SQUARE LEFT_CURLY RIGHT_CURLY
        ID
        CALLOUT IF ELSE FOR WHILE RETURN BREAK CONTINUE TYPE CLASS PROGRAM

%left   ARITH_OP REL_OP EQ_OP COND_OP

%%

Goal:	program

program:        CLASS PROGRAM LEFT_CURLY var_decls method_decls RIGHT_CURLY

method_decl:    composite_type ID LEFT_ROUND parameters RIGHT_ROUND block

method_decls:   {}
        |       method_decl
        |       method_decls method_decl

parameters:     {}
        |       composite_type ID
        |       parameters COMMA composite_type ID
        
composite_type: TYPE 
        |       TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE
        |       TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE


block:          LEFT_CURLY var_decls statements RIGHT_CURLY

var_decls:      {}
        |       var_decl
        |       var_decls var_decl

var_decl:       TYPE location SEMICOLON
        |       composite_type ID SEMICOLON

statements:     statement 
        |       statements statement

statement:      statement bin_op statement
        |       location EQUALS expr SEMICOLON
        |       method_call SEMICOLON
        |       IF LEFT_ROUND expr RIGHT_ROUND statement
        |       IF LEFT_ROUND expr RIGHT_ROUND statement ELSE statement
        |       expr  QUESTION_MARK statement COLON statement
        |       WHILE LEFT_ROUND expr RIGHT_ROUND statement 
        |       FOR LEFT_ROUND ID EQUALS expr SEMICOLON expr SEMICOLON ID EQUALS expr RIGHT_ROUND statement
        |       RETURN expr SEMICOLON
        |       BREAK SEMICOLON
        |       CONTINUE SEMICOLON
      


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

location:       ID {printf("BISON: Saw an ID\n");}
        |       ID LEFT_SQUARE expr RIGHT_SQUARE
        |       ID LEFT_SQUARE expr RIGHT_SQUARE LEFT_SQUARE expr RIGHT_SQUARE

method_call:    CALLOUT LEFT_ROUND STRING_LITERAL COMMA callout_args RIGHT_ROUND
        |       CALLOUT LEFT_ROUND STRING_LITERAL RIGHT_ROUND

callout_args:   expr |  STRING_LITERAL | callout_args COMMA callout_args 




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




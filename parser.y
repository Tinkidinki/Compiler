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

Goal:	expr

// program:        CLASS PROGRAM LEFT_CURLY method_decls RIGHT_CURLY {printf("program -> CLASS PROGRAM LEFT_CURLY method_decls RIGHT_CURLY ");}

// method_decl:    composite_type ID LEFT_ROUND parameters RIGHT_ROUND block  {printf("method_decl -> composite_type ID LEFT_ROUND parameters RIGHT_ROUND block");}

// method_decls:   {}  {printf("method_decls ->  {} ");}
//         |       method_decl  {printf("method_decls -> method_decl");}
//         |       method_decls method_decl {printf("method_decls -> method_decls method_decl ");}

// parameters:     {} {printf("parameters -> {} ");}
//         |       composite_type ID {printf("parameters -> composite_type ID ");}
//         |       parameters COMMA composite_type ID {printf("parameters -> parameters COMMA composite_type ID ");}
        
// composite_type: TYPE {printf("composite_type -> TYPE");}
//         |       TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE {printf("composite_type -> TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE");}
//         |       TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE {printf("composite_type -> TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE");}


// block:          LEFT_CURLY var_decls statements RIGHT_CURLY {printf("block -> LEFT_CURLY var_decls statements RIGHT_CURLY");}

// var_decls:      {} {printf("var_decls -> {}");}
//         |       var_decl {printf("var_decls -> var_decl");}
//         |       var_decls var_decl {printf("var_decls-> var_decls var_decl");}

// var_decl:       TYPE location SEMICOLON {printf("var_decl -> TYPE location SEMICOLON");}
//         |       composite_type ID SEMICOLON {printf("var_decl -> composite_type ID SEMICOLON");}

// statements:     statement  {printf("statements -> statement");}
//         |       statements statement  {printf("statements -> statements statement");}

// statement:      statement bin_op statement  {printf("statement -> statement bin_op statement");}
//         |       location EQUALS expr SEMICOLON  {printf("statement -> location EQUALS expr SEMICOLON");}
//         |       method_call SEMICOLON  {printf("statement -> method_call SEMICOLON");}
//         |       IF LEFT_ROUND expr RIGHT_ROUND statement  {printf("statement -> IF LEFT_ROUND expr RIGHT_ROUND statement");}
//         |       IF LEFT_ROUND expr RIGHT_ROUND statement ELSE statement  {printf("statement -> IF LEFT_ROUND expr RIGHT_ROUND statement ELSE statement ");}
//         |       expr  QUESTION_MARK statement COLON statement  {printf("statement -> expr  QUESTION_MARK statement COLON statement ");}
//         |       WHILE LEFT_ROUND expr RIGHT_ROUND statement {printf("statement -> WHILE LEFT_ROUND expr RIGHT_ROUND statement ");}
//         |       FOR LEFT_ROUND ID EQUALS expr SEMICOLON expr SEMICOLON ID EQUALS expr RIGHT_ROUND statement {printf("statement -> FOR LEFT_ROUND ID EQUALS expr SEMICOLON expr SEMICOLON ID EQUALS expr RIGHT_ROUND statement ");}
//         |       RETURN expr SEMICOLON {printf("statement -> RETURN expr SEMICOLON ");}
//         |       BREAK SEMICOLON {printf("statement -> BREAK SEMICOLON ");}
//         |       CONTINUE SEMICOLON {printf("statement -> CONTINUE SEMICOLON");}
      


expr:           literal {printf("expr -> literal");}
        |       expr bin_op expr {printf("expr -> expr bin_op expr ");}
        // |       MINUS expr {printf("expr -> MINUS expr");}
        // |       NOT expr {printf("expr -> NOT expr ");}
        // |       LEFT_ROUND expr RIGHT_ROUND {printf("expr -> LEFT_ROUND expr RIGHT_ROUND ");}
        // |       location {printf("expr -> location ");}
        // |       method_call {printf("expr -> method_call");}

literal:        INT_LITERAL {printf("literal -> INT_LITERAL ");}
        |       CHAR_LITERAL {printf("literal -> CHAR_LITERAL");}
        |       BOOL_LITERAL {printf("literal -> BOOL_LITERAL");}
        |       STRING_LITERAL  {printf("literal -> STRING_LITERAL");}

bin_op:         ARITH_OP  {printf("bin_op -> ARITH_OP ");}
        |       REL_OP  {printf("bin_op -> REL_OP");}
        |       EQ_OP  {printf("bin_op -> EQ_OP ");}
        |       COND_OP   {printf("bin_op -> COND_OP ");}

// location:       ID {printf("location -> ID ");}
//         |       ID LEFT_SQUARE expr RIGHT_SQUARE {printf("location -> ID LEFT_SQUARE expr RIGHT_SQUARE ");}
//         |       ID LEFT_SQUARE expr RIGHT_SQUARE LEFT_SQUARE expr RIGHT_SQUARE {printf("location -> ID LEFT_SQUARE expr RIGHT_SQUARE LEFT_SQUARE expr RIGHT_SQUARE ");}

// method_call:    CALLOUT LEFT_ROUND STRING_LITERAL COMMA callout_args RIGHT_ROUND {printf("method_call -> CALLOUT LEFT_ROUND STRING_LITERAL COMMA callout_args RIGHT_ROUND ");}
//         |       CALLOUT LEFT_ROUND STRING_LITERAL RIGHT_ROUND {printf("method_call -> CALLOUT LEFT_ROUND STRING_LITERAL RIGHT_ROUND");}

// callout_args:   expr {printf("callout_args -> expr ");}
//         |       STRING_LITERAL {printf("callout_args -> STRING_LITERAL ");}
//         |       callout_args COMMA callout_args {printf("callout_args -> callout_args COMMA callout_args ");}




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




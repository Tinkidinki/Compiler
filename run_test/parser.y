%{
	// #include <bits/stdc++.h>
        // using namespace std;
        
	// extern  int yylex();
        // extern  int yyparse ();
        // // extern FILE* yyin;
	// void yyerror(char *s);

        #include <stdio.h>



// #include "AST_node.h"
// #include "node_types_functionality.h"
// #include "node_types_numbers.h"
// #include "all_nodes.h"
// #include "small_test_file.h"

// IntLiteral* start = NULL;

%}

/*-----------------------------TOKENS----------------------------- */
%token  BAD_CHAR
        COMMA SEMICOLON EQUALS QUESTION_MARK COLON
        INT_LITERAL CHAR_LITERAL BOOL_LITERAL  STRING_LITERAL 
        
        MINUS NOT 
        LEFT_ROUND RIGHT_ROUND LEFT_SQUARE RIGHT_SQUARE LEFT_CURLY RIGHT_CURLY
        ID
        CALLOUT IF ELSE FOR WHILE RETURN BREAK CONTINUE TYPE CLASS PROGRAM

%left   MINUS NOT 
%left   ARITH_OP REL_OP EQ_OP COND_OP
/*----------------------------------------------------------------*/


%%

Goal:	program

program:        CLASS PROGRAM LEFT_CURLY var_decls method_decls RIGHT_CURLY {printf("program -> CLASS PROGRAM LEFT_CURLY var_decls method_decls RIGHT_CURLY \n");}
       |        CLASS PROGRAM LEFT_CURLY method_decls RIGHT_CURLY {printf("program -> CLASS PROGRAM LEFT_CURLY method_decls RIGHT_CURLY \n");}

method_decl:    composite_type ID LEFT_ROUND parameters RIGHT_ROUND block  {printf("method_decl -> composite_type ID LEFT_ROUND parameters RIGHT_ROUND block\n");}
       |        composite_type ID LEFT_ROUND RIGHT_ROUND block  {printf("method_decl -> composite_type ID LEFT_ROUND RIGHT_ROUND block\n");}

method_decls:   method_decl  {printf("method_decls -> method_decl\n");}
        |       method_decls method_decl {printf("method_decls -> method_decls method_decl \n");}

parameters:     composite_type ID {printf("parameters -> composite_type ID \n");}
        |       parameters COMMA composite_type ID {printf("parameters -> parameters COMMA composite_type ID \n");}
        
composite_type: TYPE {printf("composite_type -> TYPE\n");}
        |       TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE {printf("composite_type -> TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE\n");}
        |       TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE {printf("composite_type -> TYPE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE LEFT_SQUARE INT_LITERAL RIGHT_SQUARE \n");}


block:          LEFT_CURLY var_decls statements RIGHT_CURLY {printf("block -> LEFT_CURLY var_decls statements RIGHT_CURLY\n");}
        |       LEFT_CURLY statements RIGHT_CURLY {printf("block -> LEFT_CURLY statements RIGHT_CURLY\n");}

var_decls:      var_decl {printf("var_decls -> var_decl\n");}
        |       var_decls var_decl {printf("var_decls-> var_decls var_decl\n");}

var_decl:       composite_type ID SEMICOLON {printf("var_decl -> composite_type ID SEMICOLON\n");}
//              TYPE location SEMICOLON {printf("var_decl -> TYPE location SEMICOLON\n");}
         

statements:     statement  {printf("statements -> statement\n");}
        |       statements statement  {printf("statements -> statements statement\n");}

statement:      location EQUALS expr SEMICOLON  {printf("statement -> location EQUALS expr SEMICOLON \n");}
        |       method_call SEMICOLON  {printf("statement -> method_call SEMICOLON \n");}
        |       IF LEFT_ROUND expr RIGHT_ROUND block  {printf("statement -> IF LEFT_ROUND expr RIGHT_ROUND statement \n");}
        |       IF LEFT_ROUND expr RIGHT_ROUND block ELSE block  {printf("statement -> IF LEFT_ROUND expr RIGHT_ROUND statement ELSE statement \n");}
        |       expr  QUESTION_MARK statement COLON statement  {printf("statement -> expr  QUESTION_MARK statement COLON statement \n");}
        |       WHILE LEFT_ROUND expr RIGHT_ROUND block {printf("statement -> WHILE LEFT_ROUND expr RIGHT_ROUND statement \n");}
        |       FOR LEFT_ROUND ID EQUALS expr SEMICOLON expr SEMICOLON ID EQUALS expr RIGHT_ROUND block{printf("statement -> FOR LEFT_ROUND ID EQUALS expr SEMICOLON expr SEMICOLON ID EQUALS expr RIGHT_ROUND statement \n");}
        |       RETURN expr SEMICOLON {printf("statement -> RETURN expr SEMICOLON \n");}
        |       BREAK SEMICOLON {printf("statement -> BREAK SEMICOLON \n");}
        |       CONTINUE SEMICOLON {printf("statement -> CONTINUE SEMICOLON \n");}
      


expr:           literal {} // $$ = $1; printf("expr -> literal \n");
        |       expr bin_op literal {printf("expr -> expr bin_op expr \n");}
        |       MINUS expr {printf("expr -> MINUS expr \n");}
        |       NOT expr {printf("expr -> NOT expr \n");}
        |       LEFT_ROUND expr RIGHT_ROUND {printf("expr -> LEFT_ROUND expr RIGHT_ROUND \n");}
        |       location {printf("expr -> location \n");}
        |       method_call {printf("expr -> method_call \n");}

literal:        INT_LITERAL {} // $$ = new IntLiteral($1); printf("literal -> INT_LITERAL \n");
        |       CHAR_LITERAL {printf("literal -> CHAR_LITERAL \n");}
        |       BOOL_LITERAL {printf("literal -> BOOL_LITERAL \n");}
        |       STRING_LITERAL  {printf("literal -> STRING_LITERAL \n");}

bin_op:         ARITH_OP  {printf("bin_op -> ARITH_OP \n");}
        |       REL_OP  {printf("bin_op -> REL_OP \n");}
        |       EQ_OP  {printf("bin_op -> EQ_OP \n");}
        |       COND_OP   {printf("bin_op -> COND_OP \n");}

location:       ID {printf("location -> ID \n");}
        |       ID LEFT_SQUARE expr RIGHT_SQUARE {printf("location -> ID LEFT_SQUARE expr RIGHT_SQUARE \n");}
        |       ID LEFT_SQUARE expr RIGHT_SQUARE LEFT_SQUARE expr RIGHT_SQUARE {printf("location -> ID LEFT_SQUARE expr RIGHT_SQUARE LEFT_SQUARE expr RIGHT_SQUARE \n");}

method_call:    CALLOUT LEFT_ROUND STRING_LITERAL COMMA callout_args RIGHT_ROUND {printf("method_call -> CALLOUT LEFT_ROUND STRING_LITERAL COMMA callout_args RIGHT_ROUND \n");}
        |       CALLOUT LEFT_ROUND STRING_LITERAL RIGHT_ROUND {printf("method_call -> CALLOUT LEFT_ROUND STRING_LITERAL RIGHT_ROUND \n");}

callout_args:   expr {printf("callout_args -> callout_arg \n");}
        |       callout_args COMMA expr {printf("callout_args -> callout_args COMMA callout_arg \n");}

%%

void yyerror(char *s)
{
        fprintf(stderr, "error: %s\n", s);
}


main(int argc, char **argv)
{
        yyparse();
        printf("Parsing Over\n");
}

// %%
// int main(){
//         PrettyPrint printer;
//         start.DoOperation(printer);
// }
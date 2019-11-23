%{
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

union ASTnode{
    int int_val;
    bool bool_val;
    char char_val;
    char* str_val;
    char* symbol;
    class Node* node;
};
typedef union ASTnode YYSTYPE;

#include "parser.tab.hpp"     
  
%}      

%option noyywrap

%%     

[ \t] 			                    { /* eat white spaces */  }

true|false                          { yylval.bool_val = strcmp(yytext,"true") ? false : true; return BOOL_LITERAL; }
\'.\'                               { yylval.char_val = yytext[1]; return CHAR_LITERAL; }
[0-9]+	                            { yylval.int_val = atoi(yytext); return INT_LITERAL; }
\"[^\"]*+\"                         { yylval.str_val = strdup(yytext); return STRING_LITERAL; }


,                                   {return COMMA;}
;                                   {return SEMICOLON;}
\?                                  {return QUESTION_MARK;}    
\:                                  {return COLON;}                   
\-                                  {yylval.symbol = strdup(yytext); return MINUS;}
!                                   {yylval.symbol = strdup(yytext); return NOT;}
\(                                  {return LEFT_ROUND;}
\)                                  {return RIGHT_ROUND;}
\[                                  {return LEFT_SQUARE;}
\]                                  {return RIGHT_SQUARE;}
\{                                  {return LEFT_CURLY;}
\}                                  {return RIGHT_CURLY;}

=                                   {return EQUALS;}
(==|!=)                             {yylval.symbol = strdup(yytext); return EQ_OP;}
(<=|>=|<|>)                         {yylval.symbol = strdup(yytext); return REL_OP;}
[\+\-\*/%]                          {yylval.symbol = strdup(yytext); return ARITH_OP;}
\|\||&&                             {yylval.symbol = strdup(yytext); return COND_OP;}

class                               {return CLASS;}
Program                             {return PROGRAM;}
int|uint|bool|char|string|void      {yylval.symbol = strdup(yytext); return TYPE;}
callout                             {return CALLOUT;}
if                                  {return IF;}
else                                {return ELSE;}
for                                 {return FOR;}
while                               {return WHILE;}
return                              {return RETURN;}    
break                               {return BREAK;}
continue                            {return CONTINUE;}    
[a-zA-Z][a-zA-Z0-9]*                {yylval.symbol = strdup(yytext); return ID;}



.			                        { printf("FLEX: Unrecognized character '%c'\n", yytext[0]); return BAD_CHAR;}


%%


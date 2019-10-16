%{
#include "parser.tab.h"     
int lineno = 0;     
%}      

%%     

[ \t] 			                    { /* eat white spaces */  }

true|false                          { return BOOL_LITERAL; }
\'.\'|EOF                           { return CHAR_LITERAL; }
[0-9]+	                            { return INT_LITERAL; }
\"[^\"]*+\"                         { return STRING_LITERAL; }


,                                   {return COMMA;}
;                                   {return SEMICOLON;}
\?                                  {return QUESTION_MARK;}    
\:                                  {return COLON;}                   
\-                                  {printf("flex: MINUS\n"); return MINUS;}
!                                   {printf("flex: NOT\n"); return NOT;}
\(                                  {return LEFT_ROUND;}
\)                                  {return RIGHT_ROUND;}
\[                                  {return LEFT_SQUARE;}
\]                                  {return RIGHT_SQUARE;}
\{                                  {return LEFT_CURLY;}
\}                                  {return RIGHT_CURLY;}

=                                   {return EQUALS;}
(==|!=)                             {return EQ_OP;}
(<=|>=|<|>)                         {return REL_OP;}
[\+\-\*/%]                          {return ARITH_OP;}
\|\||&&                             {return COND_OP;}

class                               {return CLASS;}
Program                             {return PROGRAM;}
int|uint|bool|char|string|void      {return TYPE;}
callout                             {return CALLOUT;}
if                                  {return IF;}
else                                {return ELSE;}
for                                 {return FOR;}
while                               {return WHILE;}
return                              {return RETURN;}    
break                               {return BREAK;}
continue                            {return CONTINUE;}    
[a-zA-Z][a-zA-Z0-9]*                {return ID;}



.			                        { printf("FLEX: Unrecognized character '%c'\n", yytext[0]); return BAD_CHAR;}


%%


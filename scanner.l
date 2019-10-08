%{
#include "parser.tab.h"
int lineno = 0;
%}

%% 
[ \t] 			{ /* eat white spaces */  }
true|false      { printf("BOOL: %s\n", yytext); return BOOL_LITERAL; }
\'.\'|EOF       { printf("CHAR: %s\n", yytext); return CHAR_LITERAL; }
[0-9]+	        { printf("INT: %s\n", yytext); return INT_LITERAL; }
\".*\"          { printf("STRING: %s\n", yytext); return STRING_LITERAL; }
.			    { printf("Unrecognized character '%c'\n", yytext[0]); return BAD_CHAR;}
%%


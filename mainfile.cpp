#include <bits/stdc++.h>
using namespace std;
#include "parser.tab.h"


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
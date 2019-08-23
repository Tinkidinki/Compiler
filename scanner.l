%{
    #include <iostream>
    using namespace std;
    extern int yylex();
%}
%%
[ \t\n]         {printf("\n %s"); return TYPE;}
[A][a-z]+wal    { cout << "Found one " << yytext << endl; }
.               ;

[c][l][a][s][s]   {return CLASS;}



%%

int main(){
    // open a file handler to a particular file
    FILE *myfile = fopen("names.csv", "r");

    // make sure it's valid

    if (!myfile){
        cout << "I can't open file!" <<endl;
        return -1;
    }

    yyin = myfile;

    while(yylex());
}
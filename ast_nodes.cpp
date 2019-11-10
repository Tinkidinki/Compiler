#include <bits/stdc++.h>
using namespace std;

#include "ast_node_types.cpp"

class IntLiteral: public Leaf{
    public:
        int value;
        string name = "INT_LIT";

        IntLiteral(int val){
            value = val;
        }

        string getname(){return name;}
        string getvalue(){return to_string(value);}
};

class CharLiteral: public Leaf{
    public:
        char value;
        string name = "CHAR_LIT";

        CharLiteral(char val){
            value = val;
        }

        string getname(){return name;}
        string getvalue(){return string(1,value);}
};

class UnaryExpression: public Unary{
    public:
        string name;
        
        UnaryExpression(string val, Node* expr){
            name = val;
            operand = expr;
        }
        string getname(){return name;}
}


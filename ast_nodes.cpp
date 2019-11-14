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

class BoolLiteral: public Leaf{
    public:
        bool value;
        string name = "BOOL_LIT";

        BoolLiteral(bool val){
            value = val;
        }

        string getname(){return name;}
        string getvalue(){return string(1,value);}
};

class StringLiteral: public Leaf{
    public:
        string value;
        string name = "STRING_LIT";

        StringLiteral(string val){
            value = val;
        }

        string getname(){return name;}
        string getvalue(){return value;}
};

class Identifier: public Leaf{
    public:
        string value;
        string name = "ID";

        Identifier(string val){
            value = val;
        }

        string getname(){return name;}
        string getvalue(){return value;}
};


class UnaryExpression: public Unary{
    public:
        string name;
        
        UnaryExpression(char* val, Node* expr){
            string str(val);
            name = val;
            operand = expr;
        }
        string getname(){return name;}
};


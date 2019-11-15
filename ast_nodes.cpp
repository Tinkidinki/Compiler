#include <bits/stdc++.h>
using namespace std;

#include "ast_node_types.cpp"

class IntLiteral: public Leaf{
    public:
        int value;
        

        IntLiteral(int val){
            name = "INT_LIT";
            value = val;
        }
        string getvalue(){return to_string(value);}
};

class CharLiteral: public Leaf{
    public:
        char value;

        CharLiteral(char val){
            name = "CHAR_LIT";
            value = val;
        }

        string getvalue(){return string(1,value);}
};

class BoolLiteral: public Leaf{
    public:
        bool value;
        
        BoolLiteral(bool val){
            name = "BOOL_LIT";
            value = val;
        }

        string getvalue(){return string(1,value);}
};

class StringLiteral: public Leaf{
    public:
        string value;

        StringLiteral(string val){
            name = "STRING_LIT";
            value = val;
        }

        string getvalue(){return value;}
};

class Identifier: public Leaf{
    public:
        string value;

        Identifier(string val){
            name = "ID";
            value = val;
        }

        string getvalue(){return value;}
};


class UnaryExpression: public Unary{
    public:
     
        UnaryExpression(char* val, Node* expr){
            string str(val);
            name = val;
            operand = expr;
        }
      
};

class AssignmentStatement: public Binary{
    public:
        
        AssignmentStatement(Node* loc, Node* expr){
            name = "ASSIGN";
            left = loc;
            right = expr;
        }
};


class ArithmeticOperator: public Leaf{
    string value;
    public:
        ArithmeticOperator(char* op){
            name = "OP_ARITH";
            value = op;
        }
        string getvalue(){return value;}
        
};

class RelationalOperator: public Leaf{
    string value;
    public:
        RelationalOperator(char* op){
            name = "OP_REL";
            value = op;
        }
    string getvalue(){return value;}
        
};

class EqualOperator: public Leaf{
    string value;
    public:
        EqualOperator(char* op){
            name = "OP_EQ";
            value = op;
        }
    string getvalue(){return value;}
        
};

class ConditionalOperator: public Leaf{
    string value;
    public:
        ConditionalOperator(char* op){
            name = "OP_COND";
            value = op;
        }
    string getvalue(){return value;}
        
};

class BinaryExpression: public Ternary{
    public:
        BinaryExpression(Node* expr, Node* op, Node* literal){
            name = "EXP_BIN";
            child1 = expr;
            child2 = op;
            child3 = literal;
        }
};

class EnclosedExpression: public Unary{
    public:
        EnclosedExpression(Node* exp){
            name = "EXP_ENC";
            operand = exp;
        }
};

class MethodCall: public Unary{
    public:
        MethodCall(char* meth_name,  Node* call_args){
            name = meth_name;
            operand = call_args;
        }
};

class CalloutArgs: public List{
    public:
        CallOutArgs
}
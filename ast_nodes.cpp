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

        string getvalue(){return value? "true" :"false";}
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

class ArithmeticExpression: public Ternary{
    public:
        ArithmeticExpression(Node* expr, char* op, Node* literal){
            name = "EXP_BIN";
            child1 = expr;
            child2 = new ArithmeticOperator(op);
            child3 = literal;
        }
};

class EqualExpression: public Ternary{
    public:
        EqualExpression(Node* expr, char* op, Node* literal){
            name = "EXP_BIN";
            child1 = expr;
            child2 = new EqualOperator(op);
            child3 = literal;
        }
};

class ConditionalExpression: public Ternary{
    public:
        ConditionalExpression(Node* expr, char* op, Node* literal){
            name = "EXP_BIN";
            child1 = expr;
            child2 = new ConditionalOperator(op);
            child3 = literal;
        }
};

class RelationalExpression: public Ternary{
    public:
        RelationalExpression(Node* expr, char* op, Node* literal){
            name = "EXP_BIN";
            child1 = expr;
            child2 = new RelationalOperator(op);
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
        CalloutArgs(){
            name = "ARGS";
            // cout << "constructor got called\n";
        }
};

class Statements: public List{
    public:
        Statements(){
            name = "STATEMENTS";
        }
};

class DecBlock: public Binary{
    public:
        DecBlock(Node* var_list, Node* stat_list){
            name = "BLOCK";
            left = var_list;
            right = stat_list;
        }
};

class StatBlock: public Unary{
    public:
        StatBlock(Node* stat_list){
            name = "BLOCK";
            operand = stat_list;
        }
};

class VarDecls: public List{
    public:
        VarDecls(){
            name = "VAR DECLS";
        }
};

class VarDecl: public Binary{
    public:
        VarDecl(Node* comp_type, char* id){
            name = "VAR_DECL";
            left = comp_type;
            right = new Identifier(id);
        }
};

class Type: public Leaf{
    string value;
    public:
        Type(char* type){
            name = "TYPE";
            value = type;
        }
    string getvalue(){return value;}
        
};
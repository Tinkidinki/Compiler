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
        llvm::Value* Codegen();
};

class CharLiteral: public Leaf{
    public:
        char value;

        CharLiteral(char val){
            name = "CHAR_LIT";
            value = val;
        }

        string getvalue(){return string(1,value);}
        llvm::Value* Codegen();
};

class BoolLiteral: public Leaf{
    public:
        bool value;
        
        BoolLiteral(bool val){
            name = "BOOL_LIT";
            value = val;
        }

        string getvalue(){return value? "true" :"false";}
        llvm::Value* Codegen();
};

class StringLiteral: public Leaf{
    public:
        string value;

        StringLiteral(string val){
            name = "STRING_LIT";

            val = val.substr(1, val.length() - 2);
            // val = replace_newline(val);
            value = val;
        }

        string getvalue(){return value;}

        llvm::Value* Codegen();
};

class Identifier: public Leaf{
    public:
        string value;

        Identifier(string val){
            name = "ID";
            value = val;
        }

        string getvalue(){return value;}
        llvm::Value* Codegen();
};


class UnaryExpression: public Unary{
    public:
     
        UnaryExpression(char* val, Node* expr){
            string str(val);
            name = val;
            operand = expr;
        }

        llvm::Value* Codegen();
      
};

class AssignmentStatement: public Binary{
    public:
        
        AssignmentStatement(Node* loc, Node* expr){
            name = "ASSIGN";
            left = loc;
            right = expr;
        }

        llvm::Value* Codegen();
        
};


class ArithmeticOperator: public Leaf{
    string value;
    public:
        ArithmeticOperator(char* op){
            name = "OP_ARITH";
            value = op;
        }
        string getvalue(){return value;}
        llvm::Value* Codegen();
        
};

class RelationalOperator: public Leaf{
    string value;
    public:
        RelationalOperator(char* op){
            name = "OP_REL";
            value = op;
        }
        string getvalue(){return value;}
        llvm::Value* Codegen();
        
};

class EqualOperator: public Leaf{
    string value;
    public:
        EqualOperator(char* op){
            name = "OP_EQ";
            value = op;
        }
        string getvalue(){return value;}
        llvm::Value* Codegen();
        
};

class ConditionalOperator: public Leaf{
    string value;
    public:
        ConditionalOperator(char* op){
            name = "OP_COND";
            value = op;
        }
        string getvalue(){return value;}
        llvm::Value* Codegen();
        
};

class ArithmeticExpression: public Ternary{
    public:
        ArithmeticExpression(Node* expr, char* op, Node* literal){
            name = "EXP_BIN";
            child1 = expr;
            child2 = new ArithmeticOperator(op);
            child3 = literal;
        }
        llvm::Value* Codegen();
};

class EqualExpression: public Ternary{
    public:
        EqualExpression(Node* expr, char* op, Node* literal){
            name = "EXP_BIN";
            child1 = expr;
            child2 = new EqualOperator(op);
            child3 = literal;
        }
        llvm::Value* Codegen();
};

class ConditionalExpression: public Ternary{
    public:
        ConditionalExpression(Node* expr, char* op, Node* literal){
            name = "EXP_BIN";
            child1 = expr;
            child2 = new ConditionalOperator(op);
            child3 = literal;
        }
        llvm::Value* Codegen();
};

class RelationalExpression: public Ternary{
    public:
        RelationalExpression(Node* expr, char* op, Node* literal){
            name = "EXP_BIN";
            child1 = expr;
            child2 = new RelationalOperator(op);
            child3 = literal;
        }
        llvm::Value* Codegen();
};

class EnclosedExpression: public Unary{
    public:
        EnclosedExpression(Node* exp){
            name = "EXP_ENC";
            operand = exp;
        }
        llvm::Value* Codegen();
};

class MethodCall: public Unary{
    public:
        MethodCall(char* meth_name,  Node* call_args){
            name = meth_name;
            operand = call_args;
        }
        llvm::Value* Codegen();
};

class CalloutArgs: public List{
    public:
        CalloutArgs(){
            name = "ARGS";
            // cout << "constructor got called\n";
        }
        llvm::Value* Codegen();
};

class Statements: public List{
    public:
        Statements(){
            name = "STATEMENTS";
        }
        llvm::Value* Codegen();
};

class DecBlock: public Binary{
    public:
        DecBlock(Node* var_list, Node* stat_list){
            name = "BLOCK";
            left = var_list;
            right = stat_list;
        }
        llvm::Value* Codegen();
};

class StatBlock: public Unary{
    public:
        StatBlock(Node* stat_list){
            name = "BLOCK";
            operand = stat_list;
        }
        llvm::Value* Codegen();
};

class VarDecls: public List{
    public:
        VarDecls(){
            name = "VAR DECLS";
        }
        llvm::Value* Codegen();
};

class VarDecl: public Binary{
    public:
        VarDecl(Node* comp_type, char* id){
            name = "VAR_DECL";
            left = comp_type;
            right = new Identifier(id);
        }
        llvm::Value* Codegen();
};

class Type: public Leaf{
    string value;
    public:
        Type(char* type){
            name = "TYPE";
            value = type;
        }
        string getvalue(){return value;}
        llvm::Value* Codegen();
        
};

class IfThenStatement: public Binary{
    public:
        IfThenStatement(Node* exp, Node* block){
            name = "IF_THEN";
            left = exp;
            right = block;
        }
        llvm::Value* Codegen();
        
};

class IfThenElseStatement: public Ternary{
    public:
        IfThenElseStatement(Node* exp, Node* thenblock, Node* elseblock){
            name = "IF_THEN_ELSE";
            child1 = exp;
            child2 = thenblock;
            child3 = elseblock;
        }
        llvm::Value* Codegen();
};

class TernaryIfStatement: public Ternary{
    public:
        TernaryIfStatement(Node* exp, Node* thenblock, Node* elseblock){
            name = "TERNARY_IF ";
            child1 = exp;
            child2 = thenblock;
            child3 = elseblock;
        }
        llvm::Value* Codegen();
};

class WhileStatement: public Binary{
    public:
        WhileStatement(Node* exp, Node* block){
            name = "WHILE";
            left = exp;
            right = block;
        }
        llvm::Value* Codegen();
};

class ForStatement: public List{
    public:
        ForStatement(char* id1_char, Node* exp1, Node* exp, char* id2_char, Node* exp2, Node* block){
            name = "FOR";
            Node* id1 = new Identifier(id1_char);
            Node* id2 = new Identifier(id2_char);
            list.push_back(id1);
            list.push_back(exp1);
            list.push_back(exp);
            list.push_back(id2);
            list.push_back(exp2);
            list.push_back(block);
        }
        llvm::Value* Codegen();
};

class ReturnStatement: public Unary{
    public:
        ReturnStatement(Node* exp){
            name = "RETURN";
            operand = exp;
        }
        llvm::Value* Codegen();
};

class BreakStatement: public Leaf{
    string value = "oops";
    public:
        BreakStatement(){
            name = "BREAK";
        }
        string getvalue(){return value;}
        llvm::Value* Codegen();
};

class ContinueStatement: public Leaf{
    string value = "oops";
    public:
        ContinueStatement(){
            name = "CONTINUE";
        }
        string getvalue(){return value;}
        llvm::Value* Codegen();
};

class Parameters: public List{
    public:
        Parameters(){
            name = "PARAMS";
        }
        void add(Node* type, char* id_char){
            list.push_back(type);
            Node* id = new Identifier(id_char);
            list.push_back(id);
        }
        llvm::Value* Codegen();
};

class MethodDecls: public List{
    public:
        MethodDecls(){
            name = "METHOD_DECLS";
        }
        llvm::Value* Codegen();
};

class MethodDeclParam: public List{
    public:
        MethodDeclParam(Node* type, char* id_char, Node* pars, Node* block){
            list.push_back(type);
            Node* id = new Identifier(id_char);
            list.push_back(id);
            list.push_back(pars);
            list.push_back(block);
        }
        llvm::Value* Codegen();
};

class ProgramVarMethod: public Binary{
    public:
        ProgramVarMethod(Node* var, Node* meth){
            name = "PROGRAM";
            left = var;
            right = meth;
        };
        llvm::Value* Codegen();
};


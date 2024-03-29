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
        string interpret();
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
        string interpret();
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
        string interpret();
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
        string interpret();
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
        string interpret();
};

class Identifier_Array: public Binary{
    public:
        Identifier_Array(char* id, Node* exp){
            name = "ID_ARRAY";
            left = new Identifier(id);
            right = exp;
        }
        llvm::Value* Codegen();
        string interpret();

};

class Identifier_Array2D: public Ternary{
    public:
        Identifier_Array2D(char* id, Node* exp, Node* exp2){
            name = "ID_ARRAY2";
            child1 = new Identifier(id);
            child2 = exp;
            child3 = exp2;
        }
        llvm::Value* Codegen();
        string interpret();

};

class Location: public Leaf{
    public:
        string value;

        Location(string val){
            name = val;
            // value = val.substr(1);
            value = val;
        }

        string getvalue(){return value;}
        llvm::Value* Codegen();
        string interpret();
};

class Location_Array: public Binary{
    public:
        Location_Array(char* loc, Node* expr){
            name = "LOC_ARRAY";
            left = new Location(loc);
            right = expr;
        }
        llvm::Value* Codegen();
        string interpret();
};

class Location_Array2D: public Ternary{
    public:
        Location_Array2D(char* loc, Node* expr, Node* expr2){
            name = "LOC_ARRAY2D";
            child1 = new Location(loc);
            child2 = expr;
            child3 = expr2;
        }
        llvm::Value* Codegen();
        string interpret();
};

class UnaryExpression: public Unary{
    public:
     
        UnaryExpression(char* val, Node* expr){
            string str(val);
            name = val;
            operand = expr;
        }

        llvm::Value* Codegen();
        string interpret();
      
};


// Note that for now, LHS are considered ID and RHS are 
// considered location. Will make better when the need to 
// deal with arrays arises. 

class AssignmentStatement: public Binary{
    public:
        
        AssignmentStatement(Node* id, Node* expr){
            name = "ASSIGN";
            left = id;
            right = expr;
        }

        llvm::Value* Codegen();
        string interpret();        
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
        string interpret();
        
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
        string interpret();
        
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
        string interpret();
        
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
        string interpret();
        
};

class ArithmeticExpression: public Ternary{
    public:
        ArithmeticExpression(Node* expr1, char* op, Node* expr2){
            name = "EXP_BIN";
            child1 = expr1;
            child2 = new ArithmeticOperator(op);
            child3 = expr2;
        }
        llvm::Value* Codegen();
        string interpret();
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
        string interpret();
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
        string interpret();
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
        string interpret();
};

class EnclosedExpression: public Unary{
    public:
        EnclosedExpression(Node* exp){
            name = "EXP_ENC";
            operand = exp;
        }
        llvm::Value* Codegen();
        string interpret();
};

class MethodCall: public Unary{
    public:
        MethodCall(char* meth_name,  Node* call_args){
            name = meth_name;
            operand = call_args;
        }
        llvm::Value* Codegen();
        string interpret();
};

class CalloutArgs: public List{
    public:
        CalloutArgs(){
            name = "ARGS";
            // cout << "constructor got called\n";
        }
        llvm::Value* Codegen();
        string interpret();
};

class Statements: public List{
    public:
        Statements(){
            name = "STATEMENTS";
        }
        llvm::Value* Codegen();
        string interpret();
};

class DecBlock: public Binary{
    public:
        DecBlock(Node* var_list, Node* stat_list){
            name = "DECBLOCK";
            left = var_list;
            right = stat_list;
        }
        llvm::Value* Codegen();
        string interpret();
};

class StatBlock: public Unary{
    public:
        StatBlock(Node* stat_list){
            name = "STATBLOCK";
            operand = stat_list;
        }
        llvm::Value* Codegen();
        string interpret();
};

class VarDecls: public List{
    public:
        VarDecls(){
            name = "VAR DECLS";
        }
        llvm::Value* Codegen();
        string interpret();
};

class VarDecl: public Binary{
    public:
        VarDecl(Node* comp_type, char* id){
            name = "VAR_DECL";
            left = comp_type;
            right = new Identifier(id);
        }
        llvm::Value* Codegen();
        string interpret();
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
        string interpret();
        
};

class IfThenStatement: public Binary{
    public:
        IfThenStatement(Node* exp, Node* block){
            name = "IF_THEN";
            left = exp;
            right = block;
        }
        llvm::Value* Codegen();
        string interpret();
        
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
        string interpret();
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
        string interpret();
};

class WhileStatement: public Binary{
    public:
        WhileStatement(Node* exp, Node* block){
            name = "WHILE";
            left = exp;
            right = block;
        }
        llvm::Value* Codegen();
        string interpret();
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
        string interpret();
};

class ReturnStatement: public Unary{
    public:
        ReturnStatement(Node* exp){
            name = "RETURN";
            operand = exp;
        }
        llvm::Value* Codegen();
        string interpret();
};

class BreakStatement: public Leaf{
    string value = "oops";
    public:
        BreakStatement(){
            name = "BREAK";
        }
        string getvalue(){return value;}
        llvm::Value* Codegen();
        string interpret();
};

class ContinueStatement: public Leaf{
    string value = "oops";
    public:
        ContinueStatement(){
            name = "CONTINUE";
        }
        string getvalue(){return value;}
        llvm::Value* Codegen();
        string interpret();
};

class Parameters: public List{
    public:
        Parameters(){
            name = "PARAMS";
        }
        void add(Node* type, char* id_char){
            Node* id = new Identifier(id_char);
            list.push_back(id);
            list.push_back(type);
        }
        
        llvm::Value* Codegen();
        string interpret();
};

class MethodDecls: public List{
    public:
        MethodDecls(){
            name = "METHOD_DECLS";
        }
        llvm::Value* Codegen();
        string interpret();
};

class MethodDeclParam: public List{
    public:
        MethodDeclParam(Node* type, char* id_char, Node* pars, Node* block){
            name = id_char;
            list.push_back(type);
            list.push_back(pars);
            list.push_back(block);
        }
        llvm::Value* Codegen();
        string interpret();
};

class ProgramVarMethod: public Binary{
    public:
        ProgramVarMethod(Node* var, Node* meth){
            name = "PROG_WITH_VAR";
            left = var;
            right = meth;
        };
        llvm::Value* Codegen();
        string interpret();
};

class ProgramMethod: public Unary{
    public:
        ProgramMethod(Node* meth){
            name = "PROG_WITHOUT_VAR";
            operand = meth;
        }
        llvm::Value* Codegen();
        string interpret();
};


class MethodDeclEmpty: public List{
    public:
        MethodDeclEmpty(Node* type, char* id_char, Node* block){
            Node* p = new Parameters();
            name = id_char;
            list.push_back(type);
            list.push_back(p);
            list.push_back(block);
        }

        llvm::Value* Codegen();
        string interpret();
};

class MethodCallEmpty: public Leaf{
    public:
        MethodCallEmpty(char* meth_name){
            name = meth_name;
        }
        llvm::Value* Codegen();
        string interpret();

        string getvalue(){return "";}
};


class ArrayType1D: public Binary{
    public:
        ArrayType1D(char* id, int int_lit){
            name = "1DArrayType";
            left = new Identifier(id);
            right = new IntLiteral(int_lit);
        }
        llvm::Value* Codegen();
        string interpret();
};

class ArrayType2D: public Ternary{
    public:
        ArrayType2D(char* id, int int_lit, int int_lit2){
            name = "1DArrayType";
            child1 = new Identifier(id);
            child2 = new IntLiteral(int_lit);
            child3 = new IntLiteral(int_lit2);
        }
        llvm::Value* Codegen();
        string interpret();
};


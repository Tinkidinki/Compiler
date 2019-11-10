# define YYSTYPE_IS_DECLARED 1
#include <bits/stdc++.h>
using namespace std;

class Operation;
class Leaf;
class Unary;
class Binary;

union ASTnode{
    int value;
    class Literal* literal;
};
typedef union ASTnode YYSTYPE;

class Operation{
    public:
        virtual void LeafOp(Leaf* l){ cout << "test";}
        // virtual void unaryOp(Unary* u) = 0;
        // virtual void binaryOp(Binary* b) = 0;

};

class Node{
    public:
        virtual void DoOperation(Operation* o) = 0;
};

class Unary: public virtual Node{
    public:
        union ASTnode* child;
};
typedef class Unary Unary;

class Binary: public virtual Node{
    public:
        union ASTnode* left;
        union ASTnode* right;
};
typedef class Binary Binary;

class Leaf: public virtual Node{
    public:
        virtual string get_name() = 0;
        virtual string get_value() = 0;

        void DoOperation(Operation* o){
            o->LeafOp(this);
        }
};
typedef class Leaf Leaf;

class Literal: public virtual Node{
};

typedef class Literal Literal;

class IntLiteral : public Literal, public Leaf {
    public:
        // int value;
        string name = "INT_LITERAL";

        IntLiteral(int val){
            value = val;
            cout << "The value is  " <<  value << endl; 
        }

        void DoOperation(Operation* o){
            o->LeafOp(this);
            cout << "doOperation function was called!" << endl;
        }
        
        string get_name() { return name; }
        string get_value() {return to_string(value); }
        

};
typedef class IntLiteral IntLiteral;


class CharLiteral: public Leaf{

};

class StringLiteral: public Leaf{

};

class BoolLiteral: public Leaf{

};



//-------------------------------------------------------------------
// Adding the printing functionality here for now, 
// Please move to a different file



class PrettyPrint : public Operation{
    public:
        void LeafOp(Leaf* l){
            cout << "(" <<  l->get_name() << " , " << l->get_value() << ")" << endl;
        }
};

// int main(){
//     IntLiteral l(5);
//     PrettyPrint printer;
//     l.DoOperation(&printer);
//     return 0;
// }
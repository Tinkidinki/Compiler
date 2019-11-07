#include <bits/stdc++.h>
using namespace std;

class Operation;
class Leaf;
class Unary;
class Binary;

class Operation{
    public:
        virtual void LeafOp(Leaf* l){ cout << "test";}
        // virtual void unaryOp(Unary* u) = 0;
        // virtual void binaryOp(Binary* b) = 0;

};

union ASTnode{
    class IntLiteral* intliteral;
};
typedef union ASTnode YYSTYPE;

class Unary{
    public:
        union ASTnode* child;
};
typedef class Unary Unary;

class Binary{
    public:
        union ASTnode* left;
        union ASTnode* right;
};
typedef class Binary Binary;

class Leaf{
    public:
        virtual string get_name() = 0;
        virtual string get_value() = 0;

        void DoOperation(Operation* o){
            o->LeafOp(this);
        }
};
typedef class Leaf Leaf;

class IntLiteral : public Leaf {
    public:

        string name = "INT_LITERAL";
        int value;

        IntLiteral(int val){
            value = val;
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
            cout << "(" <<  l->get_name() << " , " << l->get_value() << ")";
        }
};

// int main(){
//     IntLiteral l(5);
//     PrettyPrint printer;
//     l.DoOperation(&printer);
//     return 0;
// }
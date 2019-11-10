# define YYSTYPE_IS_DECLARED 1
#include <bits/stdc++.h>
using namespace std;

class Leaf;

class Operation{
    public:
        void LeafOp(Leaf* leaf);
};

class Node{
    public:
        virtual void doOp(Operation* op) = 0;
};

class Leaf: public virtual Node{
    public:
        void doOp(Operation* op){
            op->LeafOp(this);
        }
        virtual string getname() = 0;
        virtual string getvalue() = 0;
};

class Literal: public virtual Node{
};

class IntLiteral: public Literal, public Leaf{
    public: 
        int value = 5;
        string name = "INT_LITERAL";

        IntLiteral(int val){
            value = val;
        }

        string getname(){return name;}
        string getvalue(){return to_string(value);}
};

void Operation::LeafOp(Leaf* l){
    cout << "(" <<  l->getname() << " , " << l->getvalue() << ")" << endl;
}


// union ASTnode{
//     int value;
//     class Literal* literal;
// };
// typedef union ASTnode YYSTYPE;

// int main(){
//     Operation op;
//     Literal* lit = new IntLiteral(5);
//     lit->doOp(&op);
// }
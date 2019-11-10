#include <bits/stdc++.h>
using namespace std;

class Leaf;
class Unary;
class Binary;
class Ternary;
class List;

class Operation;


typedef class Node{
    public: 
        virtual void doOp(Operation* op) = 0;
        virtual string getname() = 0;
        virtual string getvalue() = 0;
} Node;

class Operation{
    public:
        virtual string LeafOp(Leaf* l) = 0;
        virtual void UnaryOp(Unary* u) = 0;
        // virtual void BinaryOp(Binary* b) = 0;
        // virtual void TernaryOp(Ternary* t) = 0;
        // virtual void ListOp(List* l) = 0;
};

class PrettyPrint: public Operation{
    public: 
        string LeafOp(Leaf* l);
        void UnaryOp(Unary* u) = 0;
        // void BinaryOp(Binary* b) = 0;
        // void TernaryOp(Ternary* t) = 0;
        // void ListOp(List* l) = 0;
};

class Leaf: public Node{
    public:
        void doOp(Operation* op){
            op->LeafOp(this);
        }
};

string PrettyPrint::LeafOp(Leaf* l){
    return "(" +  l->getname() + " , " + l->getvalue() + ")" ;
} 

class Unary: public Node{
    public:
        void doOp(Operation* op){
            op->UnaryOp(this);
        }
        Node* operand;

        virtual string getname() = 0;
};

void PrettyPrint::UnaryOp(Unary* u){
    cout << "(" <<  u->getname() << " , " << (u->operand)->getname() <<  ")" << endl;
} 
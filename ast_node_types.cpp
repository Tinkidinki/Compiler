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
        string name;
        virtual void doOp(Operation* op) = 0;
        string getname(){return name;}
} Node;

class Operation{
    public:
        virtual void LeafOp(Leaf* l) = 0;
        virtual void UnaryOp(Unary* u) = 0;
        virtual void BinaryOp(Binary* b) = 0;
        virtual void TernaryOp(Ternary* t) = 0;
        // virtual void ListOp(List* l) = 0;
};

class PrettyPrint: public Operation{
    public: 
        void LeafOp(Leaf* l);
        void UnaryOp(Unary* u);
        void BinaryOp(Binary* b);
        void TernaryOp(Ternary* t);
        // void ListOp(List* l) = 0;
};

class Leaf: public Node{
    public:
        void doOp(Operation* op){
            op->LeafOp(this);
        }
        virtual string getvalue() = 0;
    
};

void PrettyPrint::LeafOp(Leaf* l){
    cout << "(" +  l->getname() + " , " + l->getvalue() + ")" ;
} 

class Unary: public Node{
    public:
        void doOp(Operation* op){
            op->UnaryOp(this);
        }
        Node* operand;
};

void PrettyPrint::UnaryOp(Unary* u){
    cout << "(" <<  u->getname() << " , \n"; 
    (u->operand)->doOp(this);
    cout <<  ")\n";
} 

class Binary: public Node{
    public:
        void doOp(Operation* op){
            op->BinaryOp(this);
        }
        Node* left;
        Node* right;
};

void PrettyPrint::BinaryOp(Binary* b){
    cout << "(" <<  b->getname() << " , \n "; 
    (b->left)->doOp(this);
    cout << ",";
    (b->right)->doOp(this);
    cout <<  ")\n";
} 

class Ternary: public Node{
    public:
        void doOp(Operation* op){
            op->TernaryOp(this);
        }
        Node* child1;
        Node* child2;
        Node* child3;
};

void PrettyPrint::TernaryOp(Ternary* t){
    cout << "(" <<  t->getname() << " , \n"; 
    (t->child1)->doOp(this);
    cout << ",";
    (t->child2)->doOp(this);
    cout << ",";
    (t->child3)->doOp(this);
    cout <<  ")\n";
} 

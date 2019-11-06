#include <bits/stdc++.h>
using namespace std;

#include "AST_node.h"

class Unary{
    public:
        ASTnode* child;
};
typedef class Unary Unary;

class Binary{
    public:
        ASTnode* left;
        ASTnode* right;
};
typedef class Binary Binary;

class Leaf{
    public:
        virtual string name = "";
};
typedef class Leaf Leaf;

// Adding the printing functionality here for now, 
// Please move to a different file
class Operation{
    public:
        virtual void LeafOp(Leaf* l) = 0;
        virtual void unaryOp(Unary* u) = 0;
        virtual void binaryOp(Binary* b) = 0;

};

class PrettyPrint : public Operation{
    public:
        void LeafOp(Leaf* l){
            cout << "(" << l->name << " , " << l->value << ")"
        }
}
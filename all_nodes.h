#include <bits/stdc++.h>
using namespace std;

#include "AST_node.h"
#include "node_types_numbers.h"
#include "node_types_functionality.h"


class IntLiteral: public Leaf{
    public:

        string name = "INT_LITERAL";
        int value;

        IntLiteral(int val){
            value = val;
        }
        
        string name() { return name; }
        int value() {return value; }

};
typedef class IntLiteral IntLiteral;

class CharLiteral: public Leaf{

};

class StringLiteral: public Leaf{

};

class BoolLiteral: public Leaf{

};
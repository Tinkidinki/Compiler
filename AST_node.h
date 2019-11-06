#include <bits/stdc++.h>
using namespace std;

#include "node_types_functionality.h"

union ASTnode{
    Expr* exp;
};

typedef union ASTnode ASTnode;
#include <bits/stdc++.h>
using namespace std;

#include "node_types_functionality.h"

union ASTnode{
    IntLiteral* intliteral;
};

typedef union ASTnode YYSTYPE;


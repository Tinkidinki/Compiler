#include "all_nodes.h"

union Node {
    int number;
    char* value;

    Expr* expr;
    Literal* literal;

    Node() = default;
    ~Node() = default;
}

typedef union Node YYSTYPE;
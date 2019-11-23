#include <bits/stdc++.h>
using namespace std;

#include "code_generation.cpp"

typedef struct var{
    string type;
    string value;
} var;

map <string, var> var_list;

void printVarList(){
    for(auto i: var_list){
        cout << i.first << endl;
        cout << i.second.type << endl;
        cout << i.second.value << endl;
        cout << "----------------------" << endl;
    }
}

string StringLiteral::interpret(){
    return value;
}
string MethodCall::interpret(){
    if (name == "\"printf\""){
        Node* op = operand->getList()[0];
        cout << op->interpret() << endl;
          
    }
    string v = "x";
    return v;
}
string CalloutArgs::interpret(){
    string v = "dummy";
    return v;
}
string IntLiteral::interpret(){
    return to_string(value);
}
string CharLiteral::interpret(){
    string v = "dummy";
    return v;
}
string BoolLiteral::interpret(){
    string v = "dummy";
    return v;
}
string Identifier::interpret(){
    return value;
}
string UnaryExpression::interpret(){
    string v = "dummy";
    return v;
}
string AssignmentStatement::interpret(){
    string loc = left->interpret();
    string val = right->interpret();
    var_list[loc].value = val;
    string v = "dummy";
    return v;
}
string ArithmeticOperator::interpret(){
    return value;
}
string RelationalOperator::interpret(){
    string v = "dummy";
    return v;
}
string EqualOperator::interpret(){
    string v = "dummy";
    return v;
}
string ConditionalOperator::interpret(){
    string v = "dummy";
    return v;
}
string ArithmeticExpression::interpret(){
    string op = child2->interpret();
    string operand1, operand2;

    operand1 = child1->interpret();
    operand2 = child3->interpret();
    
    if (op == "+")
        return to_string(stoi(operand1) + stoi(operand2));
    else if (op == "-")
        return to_string(stoi(operand1) - stoi(operand2));
    else if (op == "*")
        return to_string(stoi(operand1) * stoi(operand2));
    else if (op == "/")
        return to_string(stoi(operand1) / stoi(operand2));
    return "lala";
    
    
}

string Location::interpret(){
    return var_list[value].value;
}
string EqualExpression::interpret(){
    string v = "dummy";
    return v;
}
string ConditionalExpression::interpret(){
    string v = "dummy";
    return v;
}
string RelationalExpression::interpret(){
    string v = "dummy";
    return v;
}
string EnclosedExpression::interpret(){
    string v = "dummy";
    return v;
}

string Statements::interpret(){
    string v = "dummy";
    return v;
}
string DecBlock::interpret(){
    for (auto i: left->getList()){
        i->interpret();
    }
    for (auto i: right->getList()){
        i->interpret();
    }
    return "";
}
string StatBlock::interpret(){
    string v = "dummy";
    return v;
}
string VarDecls::interpret(){
    string v = "dummy";
    return v;
}
string VarDecl::interpret(){
    var temp;
    temp.type = left->interpret();
    temp.value = "";
    var_list.insert({right->interpret(), temp});
    string v = "dummy";
    return v;
}
string Type::interpret(){
    return value;
}
string IfThenStatement::interpret(){
    string v = "dummy";
    return v;
}
string IfThenElseStatement::interpret(){
    string v = "dummy";
    return v;
}
string TernaryIfStatement::interpret(){
    string v = "dummy";
    return v;
}
string WhileStatement::interpret(){
    string v = "dummy";
    return v;
}
string ForStatement::interpret(){
    string v = "dummy";
    return v;
}
string ReturnStatement::interpret(){
    string v = "dummy";
    return v;
}
string BreakStatement::interpret(){
    string v = "dummy";
    return v;
}
string ContinueStatement::interpret(){
    string v = "dummy";
    return v;
}
string Parameters::interpret(){
    string v = "dummy";
    return v;
}
string MethodDecls::interpret(){
    string v = "dummy";
    return v;
}
string MethodDeclParam::interpret(){
    string v = "dummy";
    return v;
}
string ProgramVarMethod::interpret(){
    string v = "dummy";
    return v;
}
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
    // cout << "the bool value "<< value << endl;
    return value?"true":"false";
}
string Identifier::interpret(){
    return value;
}
string UnaryExpression::interpret(){
    string exp = operand->interpret();
    if (name == "-")
        return to_string(-stoi(exp));
    else if (name == "!")
        return exp=="true"?"false":"true";
}
string AssignmentStatement::interpret(){
    string loc = left->interpret();
    string val = right->interpret();
    var_list[loc].value = val;
    return "";
}
string ArithmeticOperator::interpret(){
    return value;
}
string RelationalOperator::interpret(){
    return value;
}
string EqualOperator::interpret(){
    return value;
}
string ConditionalOperator::interpret(){
    return value;
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
    
    
}

string Location::interpret(){
    return var_list[value].value;
}

string EqualExpression::interpret(){
    string op = child2->interpret();
    string operand1, operand2;

    operand1 = child1->interpret();
    operand2 = child3->interpret();

    if (op == "==")
        return operand1 == operand2 ? "true":"false";
    else if (op == "!=")
        return operand1 != operand2 ? "true":"false";
}
string ConditionalExpression::interpret(){
    string op = child2->interpret();
    string operand1, operand2;

    operand1 = child1->interpret();
    operand2 = child3->interpret();

    if (op == "&&")
        return operand1 == "true" && operand2 == "true" ? "true":"false";
    else if (op == "||")
        return operand1 == "false" || operand2 == "false" ? "false":"true";
}
string RelationalExpression::interpret(){
    string op = child2->interpret();
    string operand1, operand2;

    operand1 = child1->interpret();
    operand2 = child3->interpret();

    if (op == "<")
        return stoi(operand1) < stoi(operand2)?"true":"false";
    else if (op == ">")
        return stoi(operand1) > stoi(operand2)?"true":"false";
    else if (op == "<=")
        return stoi(operand1) <= stoi(operand2)?"true":"false";
    else if (op == ">=")
        return stoi(operand1) >= stoi(operand2)?"true":"false";
    
}
string EnclosedExpression::interpret(){
    return operand->interpret();
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
    for (auto i: operand->getList()){
        string ret = i->interpret();
        if (ret == "BREAK") return "BREAK";
        if (ret == "CONTINUE") return "CONTINUE";
    }
    return "";
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
    if (left->interpret() == "true"){
        string ret = right->interpret();
        return ret;
    }
}
string IfThenElseStatement::interpret(){
    if (child1->interpret() == "true"){
        string ret = child2->interpret();
        return ret;
    }
    else{
        string ret = child3->interpret();
        return ret;
    }
}
string TernaryIfStatement::interpret(){
    string v = "dummy";
    return v;
}
string WhileStatement::interpret(){
    while(left->interpret() == "true"){
        string ret = right->interpret();
        if (ret == "BREAK") break;
        if (ret == "CONTINUE") continue;
    }
    return "";
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
    return "BREAK";
}
string ContinueStatement::interpret(){
    return "CONTINUE";
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
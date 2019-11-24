#include <bits/stdc++.h>
using namespace std;

#include "code_generation.cpp"

typedef struct var{
    string type;
    string value;
} var;

map <string, var> var_list;
map <string, var> curr_var_list;

typedef struct func{
    map <string, var> var_list;
    Node* block;
    string ret_type;
} func;

map <string, func> func_list;

void printVarList(){
    for(auto i: var_list){
        cout << i.first << endl;
        cout << i.second.type << endl;
        cout << i.second.value << endl;
        cout << "----------------------" << endl;
    } 
}

void printFuncList(){
    for (auto i: func_list){
        cout << i.first << endl;
        // for (auto j: i.second.var_list){
        //     printVarList(j);
        // }
        cout << i.second.ret_type << endl;
        cout << "------------------------------------" << endl;
    }
}

string ProgramVarMethod::interpret(){
/* First interpret all the variable declarations */
    for (auto i: left->getList())
        i->interpret();


/* Obtain all the method declarations */
    for (auto i: right->getList()){
    
    // Only main gets interpreted, rest get stored.
        if (i->name == "main")
            i->getList()[2]->interpret();

        else{
            vector <Node*> list = i->getList(); // get list containing method components
            string func_name = i->name;
            string ret_type = list[0]->interpret();
            map <string, var> var_list;
            
            vector <Node*> params = list[1]->getList();
            
            bool name_check = true;
            string temp_name;
            string temp_value;
            string temp_type;

            // Params are stored as name, type, name, type and so on, 
            // So need to alternate between them to make var_list
            for (auto i: params){
                if (name_check){
                    temp_name = i->interpret();
                    temp_value = "";
                    name_check = false;
                }
                else{
                    temp_type = i->interpret();
                    var temp_var;
                    temp_var.type = temp_type;
                    temp_var.value = temp_value;
                    var_list.insert({temp_name, temp_var});
                    name_check = true;
                }
            }
            
            
            Node* block = list[2];

            func temp;
            temp.ret_type = ret_type;
            temp.var_list = var_list;
            temp.block = block;
            func_list.insert({func_name, temp});
            printFuncList();
        }
    }
    

    return "";
}

string StringLiteral::interpret(){
    return value;
}

string MethodCall::interpret(){
    if (name == "\"printf\""){
        Node* op = operand->getList()[0];
        cout << op->interpret() << endl;
          
    }
    else { 
        name = name.substr(1, name.size()-2);
        curr_var_list = func_list[name].var_list;
        return func_list[name].block->interpret();
    }
    return "";
}

string MethodCallEmpty::interpret(){
    name = name.substr(1, name.size()-2);
    curr_var_list = func_list[name].var_list;
    return func_list[name].block->interpret();
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
    if (curr_var_list.count(value) > 0){
        return curr_var_list[value].value;
    }
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
    return "";
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
    return "";
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
    string id1 = list[0]->interpret();
    string expr1 = list[1]->interpret();
    var_list[id1].value = expr1;
    while(list[2]->interpret() == "true"){
        string ret = list[5]->interpret();
        if (ret == "BREAK") break;
        string id2 = list[3]->interpret();
        string expr2 = list[4]->interpret();
        var_list[id2].value = expr2;
        if (ret == "CONTINUE") continue;
    }
    return "";
}
string ReturnStatement::interpret(){
    return operand->interpret();
}
string BreakStatement::interpret(){
    return "BREAK";
}
string ContinueStatement::interpret(){
    return "CONTINUE";
}
string Parameters::interpret(){
    return "";
}
string MethodDecls::interpret(){
    string v = "dummy";
    return v;
}
string MethodDeclParam::interpret(){
    string v = "dummy";
    return v;
}
string ProgramMethod::interpret(){
    string v = "dummy";
    return v;
}
string MethodDeclEmpty::interpret(){
    string v = "dummy";
    return v;
}
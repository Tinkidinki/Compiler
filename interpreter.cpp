#include <bits/stdc++.h>
using namespace std;

#include "ast_nodes.cpp"

typedef struct var{
    string type;
    string value;
} var;

deque <map<string, var>> scope_stack;
vector <string> curr_var_list;
stack <int> s;
vector <int> v;
typedef struct func{
    vector <string> var_list;
    Node* block;
    string ret_type;
} func;

map <string, func> func_list;

void printScopeStack(){
    cout << "SCOPE_STACK" << endl;
    for (auto var_list: scope_stack){
        for(auto i: var_list){
            cout << i.first << endl;
            cout << i.second.type << endl;
            cout << i.second.value << endl;
        }
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

/* start a new scope */
map <string, var> global_scope;
scope_stack.push_front(global_scope);

/* First interpret all the variable declarations */
    for (auto i: left->getList())
        i->interpret();


/* Obtain all the method declarations */
    for (auto i: right->getList()){
    
    // Only main gets interpreted, rest get stored.
        if (i->name == "main"){
            map <string, var> main_scope;
            scope_stack.push_front(main_scope);
            i->getList()[2]->interpret();
            scope_stack.pop_front();

        }

        else{
            vector <Node*> list = i->getList(); // get list containing method components
            string func_name = i->name;
            string ret_type = list[0]->interpret();
            
            
            vector <Node*> params = list[1]->getList();
            
            // bool name_check = true;
            // string temp_name;
            // string temp_value;
            // string temp_type;

            vector <string> var_list;
            for (auto param: params){
                var_list.push_back(param->interpret());
            }

            // Params are stored as name, type, name, type and so on, 
            // So need to alternate between them to make var_list
            // for (auto i: params){
            //     if (name_check){
            //         temp_name = i->interpret();
            //         temp_value = "";
            //         name_check = false;
            //     }
            //     else{
            //         temp_type = i->interpret();
            //         var temp_var;
            //         temp_var.type = temp_type;
            //         temp_var.value = temp_value;
            //         var_list.insert({temp_name, temp_var});
            //         name_check = true;
            //     }
            // }
            
            
            Node* block = list[2];

            func temp;
            temp.ret_type = ret_type;
            temp.var_list = var_list;
            temp.block = block;
            func_list.insert({func_name, temp});
        }
    }
    

    return "";
}

string StringLiteral::interpret(){
    return value;
}

string MethodCall::interpret(){
    // Writing out the print function here
    if (name == "\"printf\""){
        Node* op = operand->getList()[0];
        cout << op->interpret() << endl;
          
    }
    else { 
        // Removing quotes from name
        string stripped_name = name.substr(1, name.size()-2);

        // Holds the functions var_list
        curr_var_list = func_list[stripped_name].var_list;
        
        map <string, var> temp_map;
        string tempname;
        var tempvar;

        // Getting the arguments
        vector <Node*> arg_list = operand->getList();
        auto argument = arg_list.begin();


        // Putting parameters in a map
        auto vlist_pointer = curr_var_list.begin();
        while(vlist_pointer != curr_var_list.end()){
            tempname = *vlist_pointer;
            advance(vlist_pointer, 1);

            tempvar.type = *vlist_pointer;
            tempvar.value = (*argument)->interpret();
            temp_map.insert({tempname, tempvar});
            advance(argument, 1);
            advance(vlist_pointer, 1);
        }

        scope_stack.push_front(temp_map);
        string ret = func_list[stripped_name].block->interpret();
        scope_stack.pop_front();
        return ret;
    }
    return "";
}

string MethodCallEmpty::interpret(){
    string stripped_name = name.substr(1, name.size()-2);
    map <string, var> temp_map;
    scope_stack.push_front(temp_map);
    string ret = func_list[stripped_name].block->interpret();
    scope_stack.pop_front();
    return ret;
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
    return "";
}
string AssignmentStatement::interpret(){
    string loc = left->interpret();
    string val = right->interpret();
    (*scope_stack.begin())[loc].value = val;
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
    
    return "";
}

string Location::interpret(){
    for (auto map_iter = scope_stack.begin(); map_iter != scope_stack.end(); map_iter++){
        if (map_iter->count(value)) {
            return (*map_iter)[value].value;
        }
    }
    return "";
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
    
    return "";
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
    
    return "";
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

    return "";
    
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
        if (ret!=""){
            // If no return value, statements give, null, else, BREAK, CONTINUE or RETURN.
            return ret;
        }

    //     printScopeStack();
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
    scope_stack.begin()->insert({right->interpret(), temp});
    return "";
}
string Type::interpret(){
    return value;
}
string IfThenStatement::interpret(){
    if (left->interpret() == "true"){
        string ret = right->interpret();
        return ret;
    }

    return "";
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
    (*scope_stack.begin())[id1].value = expr1;
    
    while(list[2]->interpret() == "true"){
        string ret = list[5]->interpret();
        if (ret == "BREAK") break;
        string id2 = list[3]->interpret();
        string expr2 = list[4]->interpret();
        (*scope_stack.begin())[id2].value = expr2;
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
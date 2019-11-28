#include <bits/stdc++.h>
#include "interpreter.cpp"
using namespace std;



//-------------------------------------------------------
static llvm::LLVMContext Context;
static llvm::Module* ModuleOb = new llvm::Module("Tinki Compiler", Context);
static llvm::IRBuilder<> Builder(Context);
static map <string, llvm::AllocaInst*> NamedValues;
static map <string, llvm::Argument*> NamedArgs;
static map <string, llvm::FunctionType*> Functypes;
//-------------------------------------------------------


void printNamedValues(){
    cout << "NAMED VALUES" << endl;
    for (auto i: NamedValues){
        cout << i.first << endl;
    }
    cout << "--------------------------";
}

void printNamedArgs(){
    cout << "NAMED ARGS" << endl;
    for (auto i: NamedArgs){
        cout << i.first << endl;
    }
    cout << "--------------------------";
}
map<string, llvm::Type*> TypeMap;
//TypeMap[type]

// To create any function
llvm::Function *createFunc(llvm::IRBuilder<> &Builder, string Name, string type, vector <llvm::Type*> Parameter_types) {
    llvm::FunctionType *funcType = llvm::FunctionType::get(TypeMap[type], Parameter_types,false);
    llvm::Function *fooFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, Name, ModuleOb);
    return fooFunc;
}

// Set Parameters for function
void setFuncParams(llvm::Function *fooFunc, vector<string> FunArgs) {
    unsigned Idx = 0;
    llvm::Function::arg_iterator AI, AE;
    for (AI = fooFunc->arg_begin(), AE = fooFunc->arg_end(); AI != AE;
    ++AI, ++Idx){
        AI->setName(FunArgs[Idx]);
        NamedArgs[FunArgs[Idx]] = AI;
    }
}


// To add the print function's declaration
llvm::FunctionCallee printfunc = ModuleOb->getOrInsertFunction("printf",
                                                   llvm::FunctionType::get(llvm::IntegerType::getInt32Ty(Context), llvm::PointerType::get(llvm::Type::getInt8Ty(Context), 0), true /* this is var arg func type*/) 
                                                   );

// To create any basic block
llvm::BasicBlock *createBB(llvm::Function *fooFunc, std::string Name) {
    return llvm::BasicBlock::Create(Context, Name, fooFunc);
}

// To generate a global variable
// llvm::GlobalVariable *createGlob(llvm::IRBuilder<> &Builder, std::string Name, string type) {
//     if (type=="int"){
//         llvm::ConstantInt* const_int_val = llvm::ConstantInt::get(ModuleOb->getContext(), llvm::APInt(32,0));
//         ModuleOb->getOrInsertGlobal(Name, Builder.getInt32Ty());
//         llvm::GlobalVariable *gVar = ModuleOb->getNamedGlobal(Name);
//         gVar->setLinkage(llvm::GlobalValue::CommonLinkage);
//         gVar->setInitializer(const_int_val);
//         gVar->setAlignment(4);
//         return gVar;
//     }
//     llvm::GlobalVariable *dummy;
//     return dummy;
    
// }

// Codegen for all the nodes!

llvm::Value* ProgramVarMethod::Codegen(){
    TypeMap.insert({"int", Builder.getInt32Ty()});
    TypeMap.insert({"bool", Builder.getInt1Ty()});
    TypeMap.insert({"char", Builder.getInt8Ty()});
    TypeMap.insert({"string",Builder.getInt8PtrTy()});
    TypeMap.insert({"void", Builder.getVoidTy()});

    for (auto vardec : left->getList())
        vardec->Codegen();
    for (auto methoddec: right->getList())
        methoddec->Codegen();
}

llvm::Value* ProgramMethod::Codegen(){
    TypeMap.insert({"int", Builder.getInt32Ty()});
    TypeMap.insert({"bool", Builder.getInt1Ty()});
    TypeMap.insert({"char", Builder.getInt8Ty()});
    TypeMap.insert({"string",Builder.getInt8PtrTy()});
    TypeMap.insert({"void", Builder.getVoidTy()});
    
    for (auto methoddec: operand->getList())
        methoddec->Codegen();
}

llvm::Value* MethodDeclEmpty::Codegen(){
    string func_type = list[0]->interpret();
    vector <llvm::Type*> Parameter_types;
    vector <string> Parameter_names;
    llvm::Function* Func = createFunc(Builder, name, func_type, Parameter_types);
    llvm::BasicBlock *entry = createBB(Func, "entry");
    Builder.SetInsertPoint(entry);
    list[2]->Codegen();
}

llvm::Value* MethodDeclParam::Codegen(){
    string func_type = list[0]->interpret();
    vector <Node*> params = list[1]->getList();
    vector <llvm::Type*> Parameter_types;
    vector <string> Parameter_names;

    auto par_pointer = params.begin();
    while(par_pointer != params.end()){
        Parameter_names.push_back((*par_pointer)->interpret());
        advance(par_pointer, 1);
        Parameter_types.push_back(TypeMap[(*par_pointer)->interpret()]);
        advance(par_pointer, 1);
    }

    

    llvm::Function* Func = createFunc(Builder, name, func_type, Parameter_types);
    llvm::FunctionType *funcType = llvm::FunctionType::get(TypeMap[func_type], Parameter_types,false);
    Functypes[name] = funcType;
    setFuncParams(Func, Parameter_names);
    llvm::BasicBlock *entry = createBB(Func, "entry");
    Builder.SetInsertPoint(entry);

    llvm::AllocaInst* alloc;
    auto type_pointer = Parameter_types.begin();
    list[2]->Codegen();
}

llvm::Value *StringLiteral::Codegen() {
    return Builder.CreateGlobalStringPtr(value);
}

llvm::Value* CalloutArgs::Codegen() {
    llvm::Value* v;
    return v;
}

llvm::Value *MethodCall::Codegen(){
    vector <llvm::Value*> arguments;
    vector <Node*> arg_nodes = operand->getList();

    for (auto node : arg_nodes){
        if (node->getname().front()=='$'){
            arguments.push_back(Builder.CreateLoad(node->Codegen()));
        }
        else arguments.push_back(node->Codegen());
    }

    if (name == "\"printf\""){
        Builder.CreateCall(printfunc, arguments, "printfcall");
    }
    
    else {

        string methcall_name = name.substr(1,name.size()-2);
        llvm::FunctionCallee func = ModuleOb->getOrInsertFunction(methcall_name, Functypes[methcall_name]);
        return Builder.CreateCall(func, arguments, "funccall");
    }
}

llvm::Value* IntLiteral::Codegen(){
    llvm::Value *v = llvm::ConstantInt::get(Context, llvm::APInt(32, static_cast<uint64_t>(value)));
    return v;
}
llvm::Value* CharLiteral::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* BoolLiteral::Codegen(){
    bool bool_val;
    if (value) bool_val = 1;
    else bool_val = 0;
    return llvm::ConstantInt::get(Context, llvm::APInt(1, bool_val));
}
llvm::Value* Identifier::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* UnaryExpression::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* AssignmentStatement::Codegen(){
    llvm::AllocaInst* var_name = NamedValues[left->interpret()];
    llvm::Value* expr = right->Codegen();
    Builder.CreateStore(expr, var_name);
}
llvm::Value* ArithmeticOperator::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* RelationalOperator::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* EqualOperator::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ConditionalOperator::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ArithmeticExpression::Codegen(){

    string op = child2->interpret();
    llvm::Value* left = child1->Codegen();
    llvm::Value* right = child3->Codegen();
    if (child1->getname().front()=='$')
        left = Builder.CreateLoad(left);
    
    if (child3->getname().front() == '$')
        right = Builder.CreateLoad(right); 

    llvm::Value* v;

    if (op == "+") {v = Builder.CreateAdd(left, right, "addition"); }
    else if (op == "-") v = Builder.CreateSub(left, right, "subtraction");
    else if (op == "*") v = Builder.CreateMul(left, right, "multiplication");
    else if (op == "/") v = Builder.CreateSDiv(left, right, "division");
    
    return v;
}

llvm::Value* EqualExpression::Codegen(){
    string op = child2->interpret();
    llvm::Value* left = child1->Codegen();
    llvm::Value* right = child3->Codegen();

    if (child1->getname().front()=='$')
        left = Builder.CreateLoad(left);
    
    if (child3->getname().front() == '$')
        right = Builder.CreateLoad(right); 

    llvm::Value* v;
    if (op == "=="){
        v = Builder.CreateICmpEQ(left, right, "equalcompare");
    }
    else if (op == "!=") 
        v = Builder.CreateICmpNE(left, right, "notequalcompare");

    return v;

}

llvm::Value* ConditionalExpression::Codegen(){
    string op = child2->interpret();
    llvm::Value* left = child1->Codegen();
    llvm::Value* right = child3->Codegen();

    if (child1->getname().front()=='$')
        left = Builder.CreateLoad(left);
    
    if (child3->getname().front() == '$')
        right = Builder.CreateLoad(right); 

    if (op == "||") {
        return Builder.Insert(llvm::BinaryOperator::Create(llvm::Instruction::Or, left, right, "doubleor"));
    } 
    else if (op == "&&") {
        return Builder.Insert(llvm::BinaryOperator::Create(llvm::Instruction::And, left, right, "doubleand"));
    }     

    llvm::Value* v;
    return v;
    
}
llvm::Value* RelationalExpression::Codegen(){
    string op = child2->interpret();
    llvm::Value* left = child1->Codegen();
    llvm::Value* right = child3->Codegen();

    if (child1->getname().front()=='$')
        left = Builder.CreateLoad(left);
    
    if (child3->getname().front() == '$')
        right = Builder.CreateLoad(right); 

    llvm::Value* v;
    if (op == "<") {
        v = Builder.CreateICmpSLT(left, right, "ltcompare");
    } else if (op == ">") {
        v = Builder.CreateICmpSGT(left, right, "gtcompare");
    } else if (op == "<=") {
        v = Builder.CreateICmpSLE(left, right, "lecompare");
    } else if (op == ">=") {
        v = Builder.CreateICmpSGE(left, right, "gecompare");
    }

    return v;
}

llvm::Value* EnclosedExpression::Codegen(){
    llvm::Value* v;
    return v;
}

llvm::Value* Statements::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* DecBlock::Codegen(){
    llvm::Value* ret;
    for (auto i: left->getList()){
        ret = i->Codegen();
    }
    for (auto i: right->getList()){
        ret = i->Codegen();
    }
    return ret;
}
llvm::Value* StatBlock::Codegen(){
    llvm::Value* ret;
    for (auto i: operand->getList()){
        ret = i->Codegen();
    }
    return ret;
}
llvm::Value* VarDecls::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* VarDecl::Codegen(){
    string var_name = right->interpret();
    string var_type = left->interpret();
    // llvm::GlobalVariable *gVar = createGlob(Builder, var_name, var_type);
    llvm::AllocaInst* alloc = Builder.CreateAlloca(TypeMap[var_type], 0, var_name);
    NamedValues[var_name] = alloc;
}
llvm::Value* Type::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* IfThenStatement::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* IfThenElseStatement::Codegen(){
    llvm::Function *TheFunction = Builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *ifBlock = llvm::BasicBlock::Create(Context, "if", TheFunction);
    llvm::BasicBlock *elseBlock = llvm::BasicBlock::Create(Context, "else");
    llvm::BasicBlock *merge = llvm::BasicBlock::Create(Context, "merge");

    llvm::Value* condition = child1->Codegen();
    Builder.CreateCondBr(condition, ifBlock, elseBlock);

    Builder.SetInsertPoint(ifBlock);
    llvm::Value* ifval = child2->Codegen();
    Builder.CreateBr(merge);

   

    ifBlock = Builder.GetInsertBlock();

    TheFunction->getBasicBlockList().push_back(elseBlock);
    Builder.SetInsertPoint(elseBlock);
    llvm::Value* elseval = child3->Codegen();

    Builder.CreateBr(merge);

    TheFunction->getBasicBlockList().push_back(merge);
    Builder.SetInsertPoint(merge);


    // Builder.SetInsertPoint(merge);
    // llvm::PHINode *Phi = Builder.CreatePHI(TypeMap["int"], 2, "iftmp");

    // Phi->addIncoming(ifval, ifBlock);
    // Phi->addIncoming(elseval, elseBlock);
    
    // return Phi;
    llvm::Value *V = llvm::ConstantInt::get(Context, llvm::APInt(32, 0));
    return V;    

}
llvm::Value* TernaryIfStatement::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* WhileStatement::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ForStatement::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ReturnStatement::Codegen(){
    
    Builder.CreateRet(operand->Codegen());
  
    llvm::Value* v; return v;
}
llvm::Value* BreakStatement::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ContinueStatement::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* Parameters::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* MethodDecls::Codegen(){
    llvm::Value* v;
    return v;
}


llvm::Value* Location::Codegen(){
    string lname = getvalue();
    lname = lname.substr(1);
    if (NamedArgs.count(lname) > 0){name = name.substr(1); return NamedArgs[lname]; }
    else return NamedValues[lname];
}

llvm::Value* MethodCallEmpty::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ArrayType1D::Codegen(){
    llvm::Value* v;
    return v;
}

llvm::Value* Location_Array::Codegen(){
    llvm::Value* v;
    return v;
}

llvm::Value* Identifier_Array::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ArrayType2D::Codegen(){
    llvm::Value* v;
    return v;
}

llvm::Value* Location_Array2D::Codegen(){
    llvm::Value* v;
    return v;
}

llvm::Value* Identifier_Array2D::Codegen(){
    llvm::Value* v;
    return v;
}
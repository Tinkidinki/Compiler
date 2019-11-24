#include <bits/stdc++.h>
using namespace std;

#include "ast_nodes.cpp"

// Just written down for now, understand later: 
//-------------------------------------------------------
static llvm::LLVMContext Context;
static llvm::Module* TheModule = new llvm::Module("Tinki Compiler", Context);
static llvm::IRBuilder<> Builder(Context);
static map <string, llvm::AllocaInst*> NamedValues;
// static stack <llvm::loopInfo *> *loops = new stack<llvm::loopInfo*>();
//-------------------------------------------------------

llvm::FunctionType *funcType = llvm::FunctionType::get(Builder.getVoidTy(), false);
llvm::Function *mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", TheModule);
llvm::BasicBlock *entry = llvm::BasicBlock::Create(Context, "entry", mainFunc);


llvm::Value *StringLiteral::Codegen() {
    cout << "String codegen called" << endl;
    string s = "hello";
    cout << "Say hello" << endl;
    // llvm::Value *v1 = llvm::ConstantInt::get(Context, llvm::APInt(32, static_cast<uint64_t>(5)));
    // llvm::Value *v2 = llvm::ConstantInt::get(Context, llvm::APInt(32, static_cast<uint64_t>(6)));
    // llvm::Value* v = Builder.CreateMul(v1, v2, "multiplication");

    llvm::Value* v = Builder.CreateGlobalStringPtr(s);
    cout << "v created" << endl;
    return v;
}

llvm::Value* CalloutArgs::Codegen() {
    llvm::Value* v;
    return v;
}

llvm::Value *MethodCall::Codegen(){
    vector<llvm::Value*> Args;
    vector<llvm::Type*> ArgTypes;
    cout << "Declaration done" << endl;

    // Since operand was defined as node, list might not be available

    for (auto i: operand->getList()){
        cout << i->getname() << " " << endl;
    }
    cout << "printing done" << endl;
    for (auto i: operand->getList()){
        llvm::Value* tmp = i->Codegen();
        cout << "returned from string" << endl;
        Args.push_back(tmp);
        ArgTypes.push_back(tmp->getType());
    }
    cout << "getting the args done" << endl;
    cout << "Func name is "<< name << endl;
    llvm::ArrayRef<llvm::Type* > ArgsRef(ArgTypes);
    llvm::ArrayRef<llvm::Value*> funcargs(Args);

    cout << "declaring array refs done" << endl;

    llvm::FunctionType* Ftype = llvm::FunctionType::get(llvm::Type::getInt32PtrTy(Context), ArgsRef, false);
    llvm::FunctionCallee func = TheModule->getOrInsertFunction(name, Ftype);

    cout << "function declared" << endl;
    llvm::Value* v = Builder.CreateCall(func, funcargs);
    return v;

    cout << "function called" << endl;

}

llvm::Value* IntLiteral::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* CharLiteral::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* BoolLiteral::Codegen(){
    llvm::Value* v;
    return v;
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
    llvm::Value* v;
    return v;
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
    llvm::Value* v;
    return v;
}
llvm::Value* EqualExpression::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ConditionalExpression::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* RelationalExpression::Codegen(){
    llvm::Value* v;
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
    llvm::Value* v;
    return v;
}
llvm::Value* StatBlock::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* VarDecls::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* VarDecl::Codegen(){
    llvm::Value* v;
    return v;
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
    llvm::Value* v;
    return v;
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
    llvm::Value* v;
    return v;
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
llvm::Value* MethodDeclParam::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ProgramVarMethod::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* Location::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ProgramMethod::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* MethodDeclEmpty::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* MethodCallEmpty::Codegen(){
    llvm::Value* v;
    return v;
}

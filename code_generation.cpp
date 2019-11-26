#include <bits/stdc++.h>
#include "interpreter.cpp"
using namespace std;



//-------------------------------------------------------
static llvm::LLVMContext Context;
static llvm::Module* ModuleOb = new llvm::Module("Tinki Compiler", Context);
static llvm::IRBuilder<> Builder(Context);
// static map <string, llvm::AllocaInst*> NamedValues;
// static stack <llvm::loopInfo *> *loops = new stack<llvm::loopInfo*>();
//-------------------------------------------------------


// To create any function
llvm::Function *createFunc(llvm::IRBuilder<> &Builder, string Name) {
    llvm::FunctionType *funcType = llvm::FunctionType::get(Builder.getInt32Ty(),false);
    llvm::Function *fooFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, Name, ModuleOb);
    return fooFunc;
}

// To add the print function's declaration
llvm::FunctionCallee printfunc = ModuleOb->getOrInsertFunction("printf",
                                                   llvm::FunctionType::get(llvm::IntegerType::getInt32Ty(Context), llvm::PointerType::get(llvm::Type::getInt8Ty(Context), 0), true /* this is var arg func type*/) 
                                                   );

// To create any basic block
llvm::BasicBlock *createBB(llvm::Function *fooFunc, std::string Name) {
    return llvm::BasicBlock::Create(Context, Name, fooFunc);
}

// Codegen for all the nodes!

llvm::Value* ProgramVarMethod::Codegen(){
    llvm::Value* v;
    return v;
}

llvm::Value* MethodDeclEmpty::Codegen(){
    llvm::Function* Func = createFunc(Builder, "main");
    llvm::BasicBlock *entry = createBB(Func, "entry");
    Builder.SetInsertPoint(entry);
    list[2]->Codegen();
    Builder.CreateRet(Builder.getInt32(0));
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
        arguments.push_back(node->Codegen());
    }

    cout << "REACHED AFTER LIST MADE" << endl;
    if (name == "\"printf\""){
        Builder.CreateCall(printfunc, arguments, "printfcall");
    }
    
    cout << "After print call" << endl;
    llvm::Value* v;
    return v;
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

    string op = child2->interpret();
    llvm::Value* operand1 = child1->Codegen();
    llvm::Value* operand2 = child3->Codegen();

    llvm::Value* v;

    if (op == "+") v = Builder.CreateAdd(left, right, "addition");
    else if (op == "-") v = Builder.CreateSub(left, right, "subtraction");
    else if (op == "*") v = Builder.CreateMul(left, right, "multiplication");
    else if (op == "/") v = Builder.CreateSDiv(left, right, "division");
    return v;
}
llvm::Value* EqualExpression::Codegen(){
    op = child2->interpret();

    llvm::Value* v;
    if (op == "==") {
        v = Builder.CreateICmpEQ(left, right, "equalcompare");
    } else if (op == "!=") {
        v = Builder.CreateICmpNE(left, right, "notequalcompare");
    
    return v;

}
llvm::Value* ConditionalExpression::Codegen(){
    
    if (op == "||") {
        return Builder.Insert(BinaryOperator::Create(Instruction::Or, left, right, "doubleor"));
    } 
    else if (op == "&&") {
        return Builder.Insert(BinaryOperator::Create(Instruction::And, left, right, "doubleand"));
    }     
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
    for (auto i: operand->getList()){
        llvm::Value* ret = i->Codegen();
        return ret;
    }
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

llvm::Value* Location::Codegen(){
    llvm::Value* v;
    return v;
}
llvm::Value* ProgramMethod::Codegen(){
    llvm::Value* v;
    return v;
}

llvm::Value* MethodCallEmpty::Codegen(){
    llvm::Value* v;
    return v;
}

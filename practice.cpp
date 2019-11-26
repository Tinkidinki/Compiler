#include <bits/stdc++.h>
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"
using namespace llvm;
using namespace std;


static LLVMContext Context;
static Module* ModuleOb = new Module("My Compiler", Context);

Function *createFunc(IRBuilder<> &Builder, std::string Name) {
    FunctionType *funcType = llvm::FunctionType::get(Builder.getInt32Ty(),false);
    Function *fooFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, Name, ModuleOb);
    return fooFunc;
}

BasicBlock *createBB(Function *fooFunc, std::string Name) {
    return BasicBlock::Create(Context, Name, fooFunc);
}

int main(int argc, char* argv[]){

    FunctionCallee printfunc = ModuleOb->getOrInsertFunction("printf",
                                                   FunctionType::get(IntegerType::getInt32Ty(Context), PointerType::get(Type::getInt8Ty(Context), 0), true /* this is var arg func type*/) 
                                                   );
    static IRBuilder<> Builder(Context);
    Function* mainFunc = createFunc(Builder, "main");

    BasicBlock *entry = createBB(mainFunc, "entry");
    Builder.SetInsertPoint(entry);
    vector<Value *> ArgsV;
    Value* num = ConstantInt::get(Context, APInt(32, static_cast<uint64_t>(25)));
    Value* str = Builder.CreateGlobalStringPtr("%d");
    ArgsV.push_back(str);
    ArgsV.push_back(num);
    Builder.CreateCall(printfunc, ArgsV, "printfCall");
    Builder.CreateRet(Builder.getInt32(0));

    verifyFunction(*mainFunc);
    ModuleOb->dump();
    return 0;
}
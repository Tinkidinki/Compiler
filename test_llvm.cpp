#include "llvm/Support/DataTypes.h"
#include "llvm/LLVMContext.h"
#include "llvm/Module.h"
#include "llvm/Constants.h"
#include "llvm/Function.h"
#include "llvm/BasicBlock.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/Support/IRBuilder.h"

#include <vector>
#include <cstdio>
#include <string>

int main()
{
  llvm::LLVMContext & context = llvm::getGlobalContext();
  llvm::Module *module = new llvm::Module("asdf", context);
  llvm::IRBuilder<> builder(context);

  // Added extra
  llvm::FunctionType *funcType = llvm::FunctionType::get(builder.getVoidTy(), false);
  llvm::Function *mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", module);
  llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entry", mainFunc);
  builder.SetInsertPoint(entry);

  llvm::Value *helloWorld = builder.CreateGlobalStringPtr("hello world!\n");
}
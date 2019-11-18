#include <bits/stdc++.h>
using namespace std;

#include "ast_nodes.cpp"

// Just written down for now, understand later: 
//-------------------------------------------------------
static LLVMContext TheContext;
static Module* TheModule = new Module("Tinki Compiler", Context);
static IRBuilder<> Builder(Context);
static map <string, AllocaInst*> NamedValues;
static stack <loopInfo *> *loops = new stack<loopInfo*>();
//-------------------------------------------------------

Value *StringLiteral::Codegen() {
    return Builder.CreateGlobalStringPtr(value);
}


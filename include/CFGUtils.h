#ifndef CFGUTILS_H
#define CFGUTILS_H

#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "vector"

namespace CFGUtils {

void InstNamer(llvm::Function &F);
bool SkipFunction(llvm::Function &F);
std::vector<llvm::Instruction *> GetPred(llvm::Instruction *);

}
#endif

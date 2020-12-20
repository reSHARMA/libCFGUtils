#include "CFGUtils.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "string"
#include "vector"

namespace CFGUtils {

/// InstNamer - sets name to the SSA temporaries
void InstNamer(llvm::Function& F) {
    for (auto& Arg : F.args()) {
        if (!Arg.hasName()) Arg.setName("arg");
    }
    for (llvm::BasicBlock& BB : F) {
        if (!BB.hasName()) BB.setName("bb");
        for (llvm::Instruction& I : BB) {
            if (!I.hasName() && !I.getType()->isVoidTy()) I.setName("i");
        }
    }
}

bool SkipFunction(llvm::Function& F) {
    std::vector<std::string> omitFunction = {"_ZN", "_Zn", "llvm"};
    for (auto s : omitFunction)
        if (F.getName().startswith(s)) return true;
    return false;
}

std::vector<llvm::Instruction*> GetPred(llvm::Instruction* Inst) {
    std::vector<llvm::Instruction*> Result;
    llvm::BasicBlock* Parent = Inst->getParent();
    if (&Parent->front() == Inst) {
        for (llvm::BasicBlock* BB : predecessors(Parent)) {
            Result.push_back(&BB->back());
        }
    } else {
        Result.push_back(Inst->getPrevNonDebugInstruction());
    }
    return Result;
}

} 

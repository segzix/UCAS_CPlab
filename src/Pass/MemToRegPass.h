#ifndef COMPILER_MEMTOREGPASS_H
#define COMPILER_MEMTOREGPASS_H

#include <stack>
#include "Pass.h"
#include "IR/iMemory.h"
#include "utils/DominatorTree.h"

class DominatorTree;

class MemToRegPass : public FunctionPass {
public:
    explicit MemToRegPass(std::string name = "");

    void runOnFunction(IRFunction &F) override;

private:
    static bool isAllocaPromotable(IRAllocaInst *AI);

    static void mem2reg(std::vector<IRAllocaInst *> Allocs, DominatorTree *root, std::vector<IRBasicBlock *> &BBList);

    static void renamePass(DominatorTree *pTree, IRAllocaInst *pInst, std::vector<IRInstruction *> *pVector,
                           std::stack<IRValue *> *pStack);
};


#endif //COMPILER_MEMTOREGPASS_H

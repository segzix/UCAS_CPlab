#ifndef COMPILER_ALGEBRAICPASS_H
#define COMPILER_ALGEBRAICPASS_H

#include "Pass.h"

class AlgebraicPass : public BasicBlockPass {
public:
    explicit AlgebraicPass(std::string name = "");

    void runOnBasicBlock(IRBasicBlock &BB) override;
};


#endif //COMPILER_CUTDEADBLOCKPASS_H

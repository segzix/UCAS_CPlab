#ifndef COMPILER_IRFUNCTION_H
#define COMPILER_IRFUNCTION_H

#include "IRArgument.h"
#include "IRDerivedTypes.h"
#include "IRGlobalValue.h"
#include "IRBasicBlock.h"

class IRFunctionType;

class IRFunction : public IRGlobalValue {
private:
    std::vector<IRArgument *> ArgumentList;
    std::vector<IRBasicBlock *> BasicBlocks;
    IRModule *Parent;

    void setParent(IRModule *parent);

public:
    IRFunction(IRFunctionType *Ty, LinkageTypes Linkage,
               const std::string &N = "", IRModule *M = nullptr);
    ~IRFunction() = default;

    const IRType *getReturnType() const;            // Return the type of the ret val
    IRFunctionType *getFunctionType() const;        // Return the FunctionType for me

    std::vector<IRArgument *> &getArgumentList() { return ArgumentList; }
    std::vector<IRBasicBlock *> &getBasicBlockList() { return BasicBlocks; }

    void addArgument(IRArgument * arg);
    void addBasicBlock(IRBasicBlock * block);

    IRBasicBlock *getEntryBlock() { return BasicBlocks.front(); }

    void print(std::ostream &OS) const override;

    static inline bool classof(const IRFunction *) { return true; }
    static inline bool classof(const IRValue *V) {
        return V->getValueType() == IRValue::FunctionVal;
    }
};


#endif//COMPILER_IRFUNCTION_H

#ifndef COMPILER_IRVALUE_H
#define COMPILER_IRVALUE_H

#include <string>
#include <vector>

#include "IRUse.h"

class IRType;
class IRConstant;
class IRArgument;
class IRInstruction;
class IRBasicBlock;
class IRGlobalValue;
class IRFunction;
class IRGlobalVariable;

class IRValue {
public:
    enum ValueTy {
        TypeVal,          // This is an instance of Type
        ConstantVal,      // This is an instance of Constant
        ArgumentVal,      // This is an instance of Argument
        InstructionVal,   // This is an instance of Instruction
        BasicBlockVal,    // This is an instance of BasicBlock
        FunctionVal,      // This is an instance of Function
        GlobalVariableVal,// This is an instance of GlobalVariable
    };

private:
    std::vector<IRUse> Uses;
    std::string name;
    IRType *ty;
    ValueTy vTy;

public:
    void operator=(const IRValue &) = delete;
    IRValue(const IRValue &) = delete;
    IRValue(IRType *Ty, ValueTy vty, std::string name = "");
    virtual ~IRValue() = default;

    virtual void print(std::ostream &O) const = 0;

    inline IRType *getType() const { return ty; }

    inline bool hasName() const { return name != ""; }
    inline const std::string &getName() const { return name; }

    inline ValueTy getValueType() const { return vTy; }

    //    void replaceAllUsesWith(IRValue *V);
};

#endif//COMPILER_IRVALUE_H

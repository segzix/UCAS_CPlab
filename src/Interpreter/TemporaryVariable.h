//
// Created by yuanjunkang on 24-5-5.
//

#ifndef COMPILER_TEMPORARYVARIABLE_H
#define COMPILER_TEMPORARYVARIABLE_H

#include <cstdio>
#include <cstring>
#include <iostream>
#include <any>
#include <string>
#include <utility>
#include "IR/IRValue.h"

class TemporaryVariable {

private:
    std::any value;

public:
    enum tempVarType{
        Func,
        Int,
        Float,
        Double,
        Bool,
        Void,
        Pointer
    };

private:
    tempVarType type;

public:

    TemporaryVariable(std::any value, tempVarType type);

    const std::any &getValue() const;

    tempVarType getType() const;

    void setValue(const std::any &value);

    void setType(tempVarType type);

    static std::string getTypeString(tempVarType ty);
    void print();

    TemporaryVariable operator + (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) + std::any_cast<int>(other.value), Int};
        }
        else if(type == Float && other.type == Float){
            return {std::any_cast<float>(value) + std::any_cast<float>(other.value), Float};
        }
        else if(type == Double && other.type == Double){
            return {std::any_cast<double>(value) + std::any_cast<double>(other.value), Double};
        }
        else if(type == Pointer && other.type == Int){
            return {std::any_cast<uint64_t>(value) + std::any_cast<int>(other.value), Pointer};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "+" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator - (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) - std::any_cast<int>(other.value), Int};
        }
        else if(type == Float && other.type == Float){
            return {std::any_cast<float>(value) - std::any_cast<float>(other.value), Float};
        }
        else if(type == Double && other.type == Double){
            return {std::any_cast<double>(value) - std::any_cast<double>(other.value), Double};
        }
        else if(type == Pointer && other.type == Int){
            return {std::any_cast<uint64_t>(value) - std::any_cast<int>(other.value), Pointer};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "-" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator * (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) * std::any_cast<int>(other.value), Int};
        }
        else if(type == Float && other.type == Float){
            return {std::any_cast<float>(value) * std::any_cast<float>(other.value), Float};
        }
        else if(type == Double && other.type == Double){
            return {std::any_cast<double>(value) * std::any_cast<double>(other.value), Double};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "*" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator / (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) / std::any_cast<int>(other.value), Int};
        }
        else if(type == Float && other.type == Float){
            return {std::any_cast<float>(value) / std::any_cast<float>(other.value), Float};
        }
        else if(type == Double && other.type == Double){
            return {std::any_cast<double>(value) / std::any_cast<double>(other.value), Double};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "/" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator % (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) / std::any_cast<int>(other.value), Int};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "%" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator < (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) < std::any_cast<int>(other.value), Bool};
        }
        else if(type == Float && other.type == Float){
            return {std::any_cast<float>(value) < std::any_cast<float>(other.value), Bool};
        }
        else if(type == Double && other.type == Double){
            return {std::any_cast<double>(value) < std::any_cast<double>(other.value), Bool};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "<" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator <= (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) <= std::any_cast<int>(other.value), Bool};
        }
        else if(type == Float && other.type == Float){
            return {std::any_cast<float>(value) <= std::any_cast<float>(other.value), Bool};
        }
        else if(type == Double && other.type == Double){
            return {std::any_cast<double>(value) <= std::any_cast<double>(other.value), Bool};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "<=" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator > (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) > std::any_cast<int>(other.value), Bool};
        }
        else if(type == Float && other.type == Float){
            return {std::any_cast<float>(value) > std::any_cast<float>(other.value), Bool};
        }
        else if(type == Double && other.type == Double){
            return {std::any_cast<double>(value) > std::any_cast<double>(other.value), Bool};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << ">" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator >= (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) >= std::any_cast<int>(other.value), Bool};
        }
        else if(type == Float && other.type == Float){
            return {std::any_cast<float>(value) >= std::any_cast<float>(other.value), Bool};
        }
        else if(type == Double && other.type == Double){
            return {std::any_cast<double>(value) >= std::any_cast<double>(other.value), Bool};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << ">=" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator == (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) == std::any_cast<int>(other.value), Bool};
        }
        else if(type == Float && other.type == Float){
            return {std::any_cast<float>(value) == std::any_cast<float>(other.value), Bool};
        }
        else if(type == Double && other.type == Double){
            return {std::any_cast<double>(value) == std::any_cast<double>(other.value), Bool};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "==" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator != (const TemporaryVariable& other) {
        if(type == Int && other.type == Int){
            return {std::any_cast<int>(value) != std::any_cast<int>(other.value), Bool};
        }
        else if(type == Float && other.type == Float){
            return {std::any_cast<float>(value) != std::any_cast<float>(other.value), Bool};
        }
        else if(type == Double && other.type == Double){
            return {std::any_cast<double>(value) != std::any_cast<double>(other.value), Bool};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "!=" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator && (const TemporaryVariable& other) {
        if(type == Bool && other.type == Bool){
            return {std::any_cast<bool>(value) && std::any_cast<bool>(other.value), Bool};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "&&" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator || (const TemporaryVariable& other) {
        if(type == Bool && other.type == Bool){
            return {std::any_cast<bool>(value) || std::any_cast<bool>(other.value), Bool};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "||" << getTypeString(other.type) << std::endl;
        }
    }

    TemporaryVariable operator ^ (const TemporaryVariable& other) {
        if(type == Bool && other.type == Bool){
            return {std::any_cast<bool>(value) ^ std::any_cast<bool>(other.value), Bool};
        }
        else{
            printf("Undefined Temporary Variable Operation: ");
            std::cout << getTypeString(type) << "^" << getTypeString(other.type) << std::endl;
        }
    }
};


#endif //COMPILER_TEMPORARYVARIABLE_H

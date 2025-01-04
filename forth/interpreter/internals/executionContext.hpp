#pragma once

#include "stack/stack.hpp"
#include "../basics/expression.hpp"

#include <iostream>
#include <map>
#include <string>
#include <stddef.h>

namespace frt {

class ExecutionContext {
public:
    ExecutionContext() : output_(std::cout) {}
    ExecutionContext(std::ostream& output) : output_(output) {}
    ~ExecutionContext() = default;

    void pushVal(const StackValue& val_) { stack_.push(val_); }
    bool popVal() noexcept { return stack_.pop(); }

    bool swapVal() noexcept { return stack_.swap(); }
    bool rotVal() noexcept { return stack_.rot(); }
    
    StackValue getTopVal() const noexcept { return stack_.top(); }
    StackValue getSecondFromTop() const noexcept { return stack_.getSecondFromTop(); }
    size_t getStackDepth() const noexcept { return stack_.depth(); }
    bool isStackEmpty() const noexcept { return stack_.isEmpty(); }

    void printStackVal(StackValue val) { output_ << val; }
    void printValAsChar(StackValue val) { output_ << char(val); }
    void cr() { output_ << std::endl; }

    void printStack() { stack_.printStack(output_); }

    void defineWord(std::string& name, Expression *e) { 
        words_.insert(std::pair<std::string, Expression*>({name, e}));
    }

    Expression* getDefintionByName(std::string& name) { return words_[name]; }
    bool isWordDefined(std::string& name) { return words_.count(name) != 0; } 

    void defineVar(std::string& name, StackValue val) {
        vars_.insert(std::pair<std::string, StackValue>({name, val}));
    }

    StackValue getVarValue(std::string& name) { return vars_[name]; }
    bool isVarDefined(std::string& name) { return vars_.count(name) != 0; }
    void deleteVar(std::string& name) { vars_.erase(name); }

    bool setVarVal(std::string& name, StackValue val) { 
        if (!isVarDefined(name)) { return false; }
        vars_[name] = val; 
        return true;
    }

private:
    Stack stack_;
    std::ostream& output_;

    std::map<std::string, Expression*> words_;
    std::map<std::string, StackValue> vars_;
}; // class ExectuionContext;
} // namespace frt

#pragma once

#include "stack/stack.hpp"

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

    void printStackVal(StackValue val) { output_ << val << " "; }
    void println(std::string str) { output_ << str << '\n'; }
    void printChar(char c) { output_ << c << " "; }
    void printValAsChar(StackValue val) { output_ << char(val); }
    void cr() { output_ << std::endl; }

    bool isVarDefined(std::string& name) { 
        return vars_.count(name) != 0;
    }

    bool setVarVal(std::string& name, StackValue val) {
        if (!isVarDefined(name)) {
            return false;
        }
        vars_[name] = val;
        return true;
    }
    
    StackValue getVarVal(std::string& name) { 
        return vars_.find(name)->second;
    }

    void addVar(std::string name, StackValue val) {
        vars_.insert(
            std::pair<std::string, StackValue>({name, val})
        );
    }

    void deleteVar(std::string name) {
        vars_.erase(name);
    }

    void printStack() { stack_.printStack(output_); }

private:
    Stack stack_;
    std::ostream& output_;
    std::map<std::string, StackValue> vars_;
}; // class ExectuionContext;
} // namespace frt

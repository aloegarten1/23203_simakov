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

    void printStackVal(StackValue val) { output_ << val; }
    void printValAsChar(StackValue val) { output_ << char(val); }
    void cr() { output_ << std::endl; }

    void printStack() { stack_.printStack(output_); }

private:
    Stack stack_;
    std::ostream& output_;
    std::map<std::string, StackValue> vars_;

}; // class ExectuionContext;
} // namespace frt

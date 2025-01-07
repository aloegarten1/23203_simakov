#pragma once

#include "token.hpp"
#include <iostream>

namespace frt {

class ValueToken : public Token {
public:
    ValueToken() : val_(0) {}
    ValueToken(StackValue val) : val_(val) {}

    virtual ~ValueToken() = default;
    
    virtual bool exec(ExecutionContext& context) {
        context.pushVal(val_);
        return true;
    }
protected:
    StackValue val_;
}; // class ValueToken


class StringOutToken : public Token {
public:

    StringOutToken(std::string val) : val_(val) {}

    virtual ~StringOutToken() = default;
    
    virtual bool exec(ExecutionContext& context) {
        context.print(val_);
        return true;
    }
protected:
    std::string val_;
}; // class ValueToken



} // namespace frt
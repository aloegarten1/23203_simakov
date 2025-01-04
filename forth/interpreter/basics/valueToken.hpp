#pragma once

#include "token.hpp"

namespace frt {

class ValueToken : public Token{
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
} // namespace frt
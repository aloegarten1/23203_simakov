#pragma once

#include "token.hpp"

#include <string>

namespace frt {
class Var : public Token {
public:
    explicit Var(std::string name) : name_(name) {}

    virtual ~Var() = default;

    virtual bool exec(ExecutionContext& context) {
        if (context.isVarDefined(name_)) {
            return false;
        }

        context.pushVal(context.getVarVal(name_));
        return true;
    }
private:
    std::string name_;
}; // class Value
} // namespace frt


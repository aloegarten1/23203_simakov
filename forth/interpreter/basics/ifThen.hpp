#pragma once

#include "expression.hpp"

namespace frt {
class IfThen : public Token {
public:
    IfThen(std::shared_ptr<Expression> e) : expr_(e) {}
    virtual ~IfThen() = default;

    virtual bool exec(ExecutionContext& context) {
        if (context.getStackDepth() < 1) { return false; }
        StackValue condition = context.getTopVal();
        context.popVal();
        if (condition) {
            if(!expr_->exec(context)) { return false; }
        }

        return true;
    }
private:
    std::shared_ptr<Expression> expr_;
}; // class IfThen
} // namespace frt

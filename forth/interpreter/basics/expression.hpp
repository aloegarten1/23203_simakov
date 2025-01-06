#pragma once

#include "token.hpp"
#include <memory>
#include <vector>
#include <stddef.h>

namespace frt {

class Expression : public Token{
public:
    Expression(std::vector<std::shared_ptr<Token>>& e) : expr_(e) {}
    Expression(Expression& e) : expr_(e.expr_) {}

    virtual ~Expression() = default;
    
    virtual bool exec(ExecutionContext& context) {
        for (std::size_t i = 0; i < expr_.size(); ++i) {
            expr_[i]->exec(context);
        }
        return true;
    }
private:
    // std::vector<Token *> expr_;
    std::vector<std::shared_ptr<Token>> expr_;
}; // class Expression
} // namespace frt

#pragma once

#include "token.hpp"
#include <vector>
#include <stddef.h>

namespace frt {

class Expression : public Token{
public:
    Expression(std::vector<Token *>& e) : expr_(e) {}
    Expression(Expression& e) : expr_(e.expr_) {}

    virtual ~Expression() {
        for (auto t : expr_) { 
            if (t) {
                delete t;
            } 
        }
    }
    
    virtual bool exec(ExecutionContext& context) {
        for (std::size_t i = 0; i < expr_.size(); ++i) {
            expr_[i]->exec(context);
        }
        return true;
    }
private:
    std::vector<Token *> expr_;
}; // class ValueToken
} // namespace frt

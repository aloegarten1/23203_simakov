#pragma once

#include "token.hpp"

#include <memory>

namespace frt {

class Expression : public Token {
public:
    Expression(std::vector<Token*>& expr);

    /**
     * Shallow copy. Tokens NOT will be reinitialized
     */
    Expression(const Expression& e) : expr_(e.expr_) {}

    virtual ~Expression() {
        for (auto t : expr_) { delete t; }
    }

    bool exec(ExecutionContext& context) override;
private:
    std::vector<Token *> expr_;
}; // class Expression
} // namespace frt

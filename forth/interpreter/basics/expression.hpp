#pragma once

#include "token.hpp"

#include <memory>

namespace frt {

class Expression : public Token {
public:
    Expression() = default;
    ~Expression() override = default;

    void addToken(std::unique_ptr<Token>& token) {
        expr_.push_back(std::move(token));
    }

    bool exec(ExecutionContext& context) override {
        for (std::size_t i = 0; i < expr_.size(); ++i) {
            if(!(expr_[i])->exec(context)) { 
                return false;
            }
        }
        return true;
    }
private:
    std::vector<std::unique_ptr<Token>> expr_;
}; // class Expression
} // namespace frt

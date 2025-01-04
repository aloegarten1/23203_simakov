#include "expression.hpp"

frt::Expression::Expression(std::vector<Token *> &expr) {
    expr_ = expr;
}

bool
frt::Expression::exec(ExecutionContext& context) {
    for (auto t : expr_) {
        if(!t->exec(context)) { return false; }
    }

    return true;
}

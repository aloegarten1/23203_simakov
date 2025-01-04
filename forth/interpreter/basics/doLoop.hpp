#pragma once

#include "token.hpp"

namespace frt {

class DoLoop : public Token {
public:
    DoLoop(Expression& e) : expr_(e) {}
    virtual ~DoLoop() = default;

    virtual bool exec(ExecutionContext& context) {
        StackValue i, lim, prevI;

        if (context.getStackDepth() < 2) { return false; }
        i = context.getTopVal();
        context.popVal();
        lim = context.getTopVal();
        context.popVal();

        std::string iName = std::string("i");
        if (!context.isVarDefined(iName)) {
            context.defineVar(iName, i);
        }

        else {
            prevI = context.getVarValue(iName);
            context.setVarVal(iName, i);
        }

        for ( ; i < lim ; ++i) {
            if (!expr_.exec(context)) { return false; }
            context.setVarVal(iName, i + 1);
        }

        if (prevI >= 0) { context.setVarVal(iName, prevI); }
        else { context.deleteVar(iName); }

        return true;
    }
private:
    Expression& expr_;
}; // class DoLoop
} // namespace frt

#pragma once

#include "expression.hpp"
#include <iostream>

namespace frt {

class DoLoop : public Token {
public:
    DoLoop(Expression * e) : expr_(e) {}
    virtual ~DoLoop() {
        delete expr_;
    }

    virtual bool exec(ExecutionContext& context) {
        StackValue i, lim, prevI = -1;

        if (context.getStackDepth() < 2) { return false; }
        i = context.getTopVal();
        context.popVal();
        lim = context.getTopVal();
        context.popVal();

        std::string iName = std::string("i");
        if (!context.isVarDefined(iName)) {
            context.addVar(iName, i);
            std::cout << "DEFINED I" << std::endl;
        }
        else {
            prevI = context.getVarVal(iName);
            context.setVarVal(iName, i);
        }
        
        std::cout << "ALARM " << i << std::endl;
        for (StackValue i_ = i ; i_ < lim ; ++i_) {
            if (!expr_->exec(context)) { return false; }
            context.setVarVal(iName, i_ + 1);
        }

        if (prevI >= 0) { context.setVarVal(iName, prevI); }
        else { context.deleteVar(iName); }

        return true;
    }
private:
    Expression * expr_;
}; // class DoLoop
} // namespace frt

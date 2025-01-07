#pragma once

#include "expression.hpp"
#include <iostream>

namespace frt
{

    class DoLoop : public Token
    {
    public:
        DoLoop(std::shared_ptr<Expression> e) : Token("do loop"), expr_(e) {}
        virtual ~DoLoop() = default;

        virtual bool exec(ExecutionContext &context)
        {
            StackValue i, lim, prevI = -1;

            if (context.getStackDepth() < 2)
            {
                throw ForthError("do loop error: not enought values in stack");
            }
            i = context.getTopVal();
            context.popVal();
            lim = context.getTopVal();
            context.popVal();

            std::string iName = std::string("i");
            if (!context.isVarDefined(iName))
            {
                context.addVar(iName, i);

#if defined(DEBUG)
                context.println("DEFINED I");
#endif
            }
            else
            {
                prevI = context.getVarVal(iName);
                context.setVarVal(iName, i);
            }

#if defined(DEBUG)
            context.println("ALARM ");
            context.printStackVal(i);
#endif
            for (StackValue i_ = i; i_ < lim; ++i_)
            {
                if (!expr_->exec(context))
                {
                    return false;
                }
                context.setVarVal(iName, i_ + 1);
            }

            if (prevI >= 0)
            {
                context.setVarVal(iName, prevI);
            }
            else
            {
                context.deleteVar(iName);
            }

            return true;
        }

    private:
        std::shared_ptr<Expression> expr_;
    }; // class DoLoop

    class DoLoopIterator : public Token
    {
    public:
        DoLoopIterator() : Token("loop iterator") {};
        virtual ~DoLoopIterator() = default;
        virtual bool exec(ExecutionContext &context)
        {

            std::string iName = std::string("i");

            auto val = context.getVarVal(iName);
            context.pushVal(val);
            return true;
        };
    }; // class DoLoopIterator

} // namespace frt
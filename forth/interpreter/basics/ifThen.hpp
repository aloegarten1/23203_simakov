#pragma once

#include "expression.hpp"

namespace frt
{

    class IfElse : public Token
    {
    public:
        IfElse() : Token("else") {}
        virtual ~IfElse() = default;

        virtual bool exec(ExecutionContext &context)
        {
            return true;
        }

  
    }; // class IfElse


    class IfThen : public Token
    {
    public:
        IfThen(std::shared_ptr<Expression> expr) : Token("if") { split(expr); }
        virtual ~IfThen() = default;

        virtual bool exec(ExecutionContext &context)
        {
            if (context.getStackDepth() < 1)
            {
                throw ForthError("check condition error: empty stack");
            }

            StackValue condition = context.getTopVal();
            context.popVal();
            if (condition)
            {
                if (!exprThen_->exec(context))
                {
                    return false;
                }
            }
            else
            {
                if (!exprElse_->exec(context))
                {
                    return false;
                }
            }

            return true;
        }

    private:
        std::shared_ptr<Expression> exprThen_;
        std::shared_ptr<Expression> exprElse_;

        void split(std::shared_ptr<Expression> expr)
        {
            auto e = expr.get();

            std::vector<std::shared_ptr<Token>> thenTokens;
            std::vector<std::shared_ptr<Token>> elseTokens;
            bool ee = false;

            for (auto token : e->Tokens())
            {
        //        token->debug();
                if (typeid(*token.get()) == typeid(IfElse))
                {
                    ee = true;
                    continue;
                }

                if (!ee)
                {
                    thenTokens.push_back(token);
                }
                else
                {
                    elseTokens.push_back(token);
                }
            }

            exprThen_ = std::make_shared<frt::Expression>(thenTokens);
            exprElse_ = std::make_shared<frt::Expression>(elseTokens);
        }
    }; // class IfThen


} // namespace frt

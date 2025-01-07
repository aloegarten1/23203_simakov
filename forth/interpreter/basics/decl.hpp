#pragma once

#include "token.hpp"

#include <string>
#include <memory>
#include <vector>
#include <stddef.h>

namespace frt
{
    class Declaration : public Token
    {
    public:
        explicit Declaration(std::string name, std::shared_ptr<Expression> e) : Token("user command definition"), commandName(name), commandExpr(e) {}

        virtual ~Declaration() = default;

        virtual bool exec(ExecutionContext &context)
        {
            context.defineWord(commandName, commandExpr);
            return true;
        }

        std::string commandName;
        std::shared_ptr<Expression> commandExpr;
    }; // class Value
} // namespace frt

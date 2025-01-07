#pragma once

#include "../internals/executionContext.hpp"
#include "errors.hpp"

#include <stddef.h>

namespace frt
{

    class Token
    {
    public:
        Token(std::string name) : name_(name) {};
        virtual ~Token() = default;

        /**
         * Executes token.
         * @returns true, if token was completely executed.
         * Else - false.
         *
         * @param context: ExecutionContext that contains stack
         * to operate with.
         */
        virtual bool exec(ExecutionContext &context) = 0;
        virtual void debug() { std::cout << name_ << '\n'; }

    protected:
        std::string name_;

    }; // class Token

} // namespace frt

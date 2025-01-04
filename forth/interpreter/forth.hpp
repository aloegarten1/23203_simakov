#pragma once


#include "basics/valueToken.hpp"
#include "basics/tokens.hpp"
#include "basics/commands/command_factory.hpp"
#include "internals/executionContext.hpp"

#include <memory>

namespace frt {

class Forth {
public:
    Forth() = default;
    Forth(std::ostream& output) : context_(output) {}

    bool execToken(Token * token);
    void printStack() {
        context_.printStack();
    }

private:
    ExecutionContext context_;
}; // class Forth

} // namespace frt
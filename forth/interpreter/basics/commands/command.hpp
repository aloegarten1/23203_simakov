#pragma once

#include "../token.hpp"

#include <stddef.h>
#include <iostream>

namespace frt {
class Command : public Token
{
public:
    Command(std::string name) : Token(name), _depth(0) {};
    virtual ~Command() = default;

    virtual bool exec(ExecutionContext& context) = 0;
    
protected:
    std::size_t _depth;
}; // class Command
} // namespace frt

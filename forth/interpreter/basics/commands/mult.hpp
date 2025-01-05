#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Mult : public Command {
public:
    Mult() : _depth(2) { }
    ~Mult() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Mult
} // namespace frt

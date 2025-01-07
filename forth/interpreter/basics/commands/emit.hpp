#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Emit : public Command {
public:
    Emit() : Command("emit"), _depth(1) { }
    ~Emit() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Emit
} // namespace frt
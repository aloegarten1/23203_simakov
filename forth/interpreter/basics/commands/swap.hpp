#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Swap : public Command {
public:
    Swap() : Command("swap"), _depth(2) { }
    ~Swap() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Swap
} // namespace frt

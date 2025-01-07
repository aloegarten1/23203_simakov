#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Dup : public Command {
public:
    Dup() : Command("dup"), _depth(1) { }
    ~Dup() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Dup
} // namespace frt

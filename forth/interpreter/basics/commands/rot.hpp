#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Rot : public Command {
public:
    Rot() : Command("rot"), _depth(3) { }
    ~Rot() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Rot
} // namespace frt

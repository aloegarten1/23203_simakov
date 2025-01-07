#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Over : public Command {
public:
    Over() : Command("over"), _depth(2) { }
    ~Over() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Rot
} // namespace frt

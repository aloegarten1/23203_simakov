#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Eq : public Command {
public:
    Eq() : _depth(2) { }
    ~Eq() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Eq
} // namespace frt

#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Subtract : public Command {
public:
    Subtract() : _depth(2) { }
    ~Subtract() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Subtract
} // namespace frt

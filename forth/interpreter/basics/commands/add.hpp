#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Add : public Command {
public:
    Add() : _depth(2) { }
    ~Add() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Swap
} // namespace frt

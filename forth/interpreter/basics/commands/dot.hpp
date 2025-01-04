#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Dot : public Command {
public:
    Dot() : _depth(1) { }
    ~Dot() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Dup
} // namespace frt

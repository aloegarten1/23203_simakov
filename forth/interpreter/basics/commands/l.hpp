#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class L : public Command {
public:
    L() : _depth(2) { }
    ~L() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class L
} // namespace frt

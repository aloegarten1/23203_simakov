#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class G : public Command {
public:
    G() : _depth(2) { }
    ~G() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class G
} // namespace frt

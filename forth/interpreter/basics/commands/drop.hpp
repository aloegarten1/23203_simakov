#pragma once

#include "command.hpp"

namespace frt {
class Drop : public Command {
public:
    Drop() : _depth(1) {}
    ~Drop() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Drop
} // namespace frt

#pragma once

#include "command.hpp"

#include <iostream>

namespace frt {
class Div : public Command {
public:
    Div() : _depth(2) { }
    ~Div() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Div
} // namespace frt



namespace frt {
class Mod : public Command {
public:
    Mod() : _depth(2) { }
    ~Mod() override = default;
    bool exec(ExecutionContext& context) override;
protected:
    std::size_t _depth;
}; // class Div
} // namespace frt

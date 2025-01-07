#pragma once

#include "command.hpp"

#include <iostream>

namespace frt
{
    class Cr : public Command
    {
    public:
        Cr() : Command("cr") {};
        ~Cr() override = default;
        bool exec(ExecutionContext &context) override;

    }; // class Cr
} // namespace frt

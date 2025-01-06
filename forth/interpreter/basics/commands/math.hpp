#pragma once

#include "command.hpp"

#include <iostream>

namespace frt
{

    class Math : public Command
    {
    public:
        Math() : _depth(2) {}
        ~Math() override = default;
        bool exec(ExecutionContext &context) override;

    protected:
        virtual StackValue calc(StackValue left, StackValue right) = 0;
        std::size_t _depth;
    };  

    class Add : public Math
    {
    public:
        using Math::Math;

    protected:
        StackValue calc(StackValue left, StackValue right) override;
    };

    class Subtract : public Math
    {
    public:
        using Math::Math;

    protected:
        StackValue calc(StackValue left, StackValue right) override;
    };  

    class Mult : public Math
    {
    public:
        using Math::Math;

    protected:
        StackValue calc(StackValue left, StackValue right) override;
    };

    class Div : public Math
    {
    public:
        using Math::Math;

    protected:
        StackValue calc(StackValue left, StackValue right) override;
    };

    class Mod : public Math
    {
    public:
        using Math::Math;

    protected:
        StackValue calc(StackValue left, StackValue right) override;
    };

} // namespace frt

#pragma once

#include "command.hpp"

#include <iostream>

namespace frt
{

    class Math : public Command
    {
    public:
        Math(std::string name) : Command(name), _depth(2) {}
        ~Math() override = default;
        bool exec(ExecutionContext &context) override;

    protected:
        virtual StackValue calc(StackValue left, StackValue right) = 0;
        std::size_t _depth;
    };  

    class Add : public Math
    {
    public:
        Add() : Math("+") {}

    protected:
        StackValue calc(StackValue left, StackValue right) override;
    };

    class Subtract : public Math
    {
    public:
        Subtract() : Math("-") {};

    protected:
        StackValue calc(StackValue left, StackValue right) override;
    };  

    class Mult : public Math
    {
    public:
        Mult() : Math("*") {}

    protected:
        StackValue calc(StackValue left, StackValue right) override;
    };

    class Div : public Math
    {
    public:
        Div() : Math("/") {}

    protected:
        StackValue calc(StackValue left, StackValue right) override;
    };

    class Mod : public Math
    {
    public:
        Mod() : Math("mod") {}

    protected:
        StackValue calc(StackValue left, StackValue right) override;
    };

} // namespace frt

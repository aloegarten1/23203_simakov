#pragma once

#include "command.hpp"

#include <iostream>

namespace frt
{

    class Logic : public Command
    {
    public:
        Logic(std::string name) : Command(name), _depth(2) {};
        ~Logic() override = default;
        bool exec(ExecutionContext &context) override;

    protected:
        virtual bool compare(StackValue left, StackValue right) = 0;
        std::size_t _depth;
    };

    class Eq : public Logic
    {
    public:
        Eq() : Logic("equal") {};

    protected:
        bool compare(StackValue left, StackValue right) override;
    };

    class G : public Logic
    {
    public:
          G() : Logic("greater than") {};


    protected:
        bool compare(StackValue left, StackValue right) override;
    };

    class L : public Logic
    {
    public:
        L() : Logic("less then") {};


    protected:
        bool compare(StackValue left, StackValue right) override;
    };

} // namespace frt

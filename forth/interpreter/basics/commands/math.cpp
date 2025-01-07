#include "math.hpp"
#include "../errors.hpp"

using namespace frt;

bool Math::exec(ExecutionContext &context)
{
    if (context.getStackDepth() < _depth)
    {
        throw ForthError("not enougth values in stack for " + name_);
    }

    StackValue left, right, result;
    right = context.getTopVal();
    context.popVal();
    left = context.getTopVal();
    context.popVal();
    result = this->calc(left, right);
    context.pushVal(result);
    return true;
}

StackValue Add::calc(StackValue left, StackValue right) { return left + right; }

StackValue Subtract::calc(StackValue left, StackValue right) { return left - right; }

StackValue Mult::calc(StackValue left, StackValue right) { return left * right; }

StackValue Div::calc(StackValue left, StackValue right)
{
    if (right == 0)
    {
        throw ForthError("Division by zero");
    }

    return left / right;
}

StackValue Mod::calc(StackValue left, StackValue right)
{
    if (right == 0)
    {
        throw ForthError("Division by zero");
    }

    return left % right;
}
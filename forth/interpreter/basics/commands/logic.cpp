#include "logic.hpp"

using namespace frt;

bool Logic::exec(ExecutionContext &context)
{
    if (context.getStackDepth() < _depth)
    {
        return false;
    }
    StackValue left, right, result;
    right = context.getTopVal();
    context.popVal();
    left = context.getTopVal();
    context.popVal();

    bool cmp = this->compare(left, right);

    result = cmp ? -1 : 0;

    context.pushVal(result);
    return true;
}

bool L::compare(StackValue left, StackValue right) { return left < right; };

bool G::compare(StackValue left, StackValue right) { return left > right; };

bool Eq::compare(StackValue left, StackValue right) { return left == right; };

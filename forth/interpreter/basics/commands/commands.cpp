#include "dot.hpp"
#include "drop.hpp"
#include "dup.hpp"
#include "swap.hpp"
#include "rot.hpp"
#include "over.hpp"

using namespace frt;

bool
Drop::exec(ExecutionContext& context) {
    return context.popVal();
}

bool
Dup::exec(ExecutionContext& context) {
    if (_depth > context.getStackDepth()) { return false; }
    StackValue val = context.getTopVal();
    context.pushVal(val);
    return true;
}

bool
Swap::exec(ExecutionContext& context) {
    return context.swapVal();
}

bool
Rot::exec(ExecutionContext& context) {
    return context.rotVal();
}

bool
Over::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) {
        return false;
    }
    StackValue val = context.getSecondFromTop();
    context.pushVal(val);

    return true;
}

bool
Dot::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    context.printStackVal(context.getTopVal());
    context.popVal();

    return true;
}

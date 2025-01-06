#include "add.hpp"
#include "div.hpp"
#include "dot.hpp"
#include "drop.hpp"
#include "dup.hpp"
#include "emit.hpp"
#include "eq.hpp"
#include "g.hpp"
#include "l.hpp"
#include "mult.hpp"
#include "subtract.hpp"
#include "cr.hpp"
#include "swap.hpp"
#include "rot.hpp"
#include "over.hpp"
#include "../errors.hpp"

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
Add::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    StackValue a, b;

    a = context.getTopVal();
    context.popVal();
    b = context.getTopVal();
    context.popVal();

    context.pushVal(a + b);

    return true;
}

bool
Subtract::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    StackValue right, left;

    right = context.getTopVal();
    context.popVal();
    left = context.getTopVal();
    context.popVal();

    context.pushVal(left - right);

    return true;
}

bool
Mult::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    StackValue a, b;

    a = context.getTopVal();
    context.popVal();
    b = context.getTopVal();
    context.popVal();

    context.pushVal(a * b);

    return true;
}
 

bool
Div::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    StackValue right, left;

    right = context.getTopVal();
    context.popVal();
    left = context.getTopVal();
    context.popVal();

    if (right == 0){
        throw ForthError("Division by zero");
    }

    context.pushVal(left / right);

    return true;
}

bool
Mod::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    StackValue right, left;

    right = context.getTopVal();
    context.popVal();
    left = context.getTopVal();
    context.popVal();

    if (right == 0){
        throw ForthError("Division by zero");
    }

    context.pushVal(left % right);

    return true;
}

bool
G::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    StackValue a, b;

    b = context.getTopVal();
    context.popVal();
    a = context.getTopVal();
    context.popVal();

    context.pushVal(-1 * (a > b));

    return true;
}

bool
L::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    StackValue a, b;

    b = context.getTopVal();
    context.popVal();
    a = context.getTopVal();
    context.popVal();

    context.pushVal(-1 * (a < b));

    return true;
}

bool
Eq::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    StackValue a, b;

    b = context.getTopVal();
    context.popVal();
    a = context.getTopVal();
    context.popVal();

    context.pushVal(-1 * (a == b));

    return true;
}

bool
Dot::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    context.printStackVal(context.getTopVal());
    context.popVal();
    
    return true;
}

bool
Emit::exec(ExecutionContext& context) {
    if (context.getStackDepth() < _depth) { return false; }
    context.printChar(char(context.getTopVal()));
    context.popVal();

    return true;
}

bool
Cr::exec(ExecutionContext& context) {
    context.println("");
    return true;
}

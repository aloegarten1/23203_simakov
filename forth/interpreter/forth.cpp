#include "forth.hpp"

#include <memory>

namespace Commands {
    frt::Command * createAdd() {
        return new frt::Add();
    }

    frt::Command * createDup() {
        return new frt::Dup();
    }

    frt::Command * createDrop() {
        return new frt::Drop();
    }

    frt::Command * createSwap() {
        return new frt::Swap();
    }

    frt::Command * createRot() {
        return new frt::Rot();
    }

    frt::Command * createOver() {
        return new frt::Over();
    }

    frt::Command * createDot() {
        return new frt::Dot();
    }

    frt::Command * createEmit() {
        return new frt::Emit();
    }

    frt::Command * createSubtract() {
        return new frt::Subtract();
    }

    frt::Command * createMult() {
        return new frt::Mult();
    }

    frt::Command * createDiv() {
        return new frt::Div();
    }

    frt::Command * createG() {
        return new frt::G();
    }

    frt::Command * createL() {
        return new frt::L();
    }

    frt::Command * createEq() {
        return new frt::Eq();
    }
}

namespace frt {
    bool Forth::execToken(Token * token) {
        return token->exec(context_);
    }
}

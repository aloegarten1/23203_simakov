#include "forth.hpp"

#include <memory>

namespace Commands {
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
}

namespace frt {
    bool Forth::execToken(Token * token) {
        return token->exec(context_);
    }
}

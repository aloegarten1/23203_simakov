#include "forth.hpp"

namespace Commands {
    std::shared_ptr<frt::Command> createAdd() {
        return std::make_shared<frt::Add>();
    }

    std::shared_ptr<frt::Command> createDup() {
        return std::make_shared<frt::Dup>();
    }

    std::shared_ptr<frt::Command> createDrop() {
        return std::make_shared<frt::Drop>();
    }

    std::shared_ptr<frt::Command> createSwap() {
        return std::make_shared<frt::Swap>();
    }

    std::shared_ptr<frt::Command> createRot() {
        return std::make_shared<frt::Rot>();
    }

    std::shared_ptr<frt::Command> createOver() {
        return std::make_shared<frt::Over>();
    }

    std::shared_ptr<frt::Command> createDot() {
        return std::make_shared<frt::Dot>();
    }

    std::shared_ptr<frt::Command> createEmit() {
        return std::make_shared<frt::Emit>();
    }

    std::shared_ptr<frt::Command> createSubtract() {
        return std::make_shared<frt::Subtract>();
    }

    std::shared_ptr<frt::Command> createMult() {
        return std::make_shared<frt::Mult>();
    }

    std::shared_ptr<frt::Command> createDiv() {
        return std::make_shared<frt::Div>();
    }

    std::shared_ptr<frt::Command> createMod() {
        return std::make_shared<frt::Mod>();
    }

    std::shared_ptr<frt::Command> createG() {
        return std::make_shared<frt::G>();
    }

    std::shared_ptr<frt::Command> createL() {
        return std::make_shared<frt::L>();
    }

    std::shared_ptr<frt::Command> createEq() {
        return std::make_shared<frt::Eq>();
    }

    std::shared_ptr<frt::Command> createCr() {
        return std::make_shared<frt::Cr>();
    }

 
}

namespace frt {
    bool Forth::execToken(Token * token) {
        return token->exec(context_);
    }
}

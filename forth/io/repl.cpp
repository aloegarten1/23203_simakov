#include "repl.hpp"

#include <memory>

namespace Commands {
    frt::Command * createDup();
    frt::Command * createDrop();
    frt::Command * createRot();
    frt::Command * createSwap();
    frt::Command * createOver();
    frt::Command * createDot();
}

void Repl::run() {
    loadCommands();
    output_ << "Welcome to Forth REPL mode" << std::endl;
    while (true) {
        output_ << "\nCurrent stack state: ";
        forth_.printStack();
        output_ << ">> ";

        readAndEvalToken();
    }
}

void Repl::loadCommands() {
    f_->regist3r("dup", Commands::createDup);
    f_->regist3r("drop", Commands::createDrop);
    f_->regist3r("swap", Commands::createSwap);
    f_->regist3r("rot", Commands::createRot);
    f_->regist3r("over", Commands::createOver);
    
    f_->regist3r(".", Commands::createDot);
}

bool Repl::isValid(std::string word) {
    for (std::size_t i = 0; i < word.length(); ++i) {
        if ((word[i] >= '0') && (word[i] <= '9')) { continue; }
        if (i != 0 && ((word[0] >= '0') && (word[0] <= '9'))) { return false; }
    }
    
    return true;
}

bool Repl::isNumber(std::string word) {
    for (std::size_t i = 0; i < word.length(); ++i) {
        if ((word[i] >= '0') && (word[i] <= '9')) { continue; }
        return false;
    }
    
    return true;
}

bool Repl::readAndEvalToken() {
    frt::Token * t;
    if (!t) { return false; }
    if(!readToken(&t, ' ')) {
        if (t) { delete t; }
        return false;
    }
    bool res = forth_.execToken(t);
    delete t;
    return res;
}

bool Repl::readToken(frt::Token ** t, char sep) {
    std::string word;
    *t = nullptr;

    readWord(word, ' ');
    std::cout << "WORD LENGTH - " << word.length() << std::endl;
    if ("" == word) { 
        return true;
    }

    if (!isValid(word)) {
        return false;
    }

    if (isNumber(word)) {
        frt::StackValue val = atoi(word.c_str());
        *t = new frt::ValueToken(val);

        return true;
    }

    if (f_->isRegistered(word)) {
        *t = f_->createCommandByName(word);
        return true;
    }

    return false;
}

void Repl::readWord(std::string& dst, char sep) 
{
    char c = skipSeps(sep);
    if ('\n' == c) { 
        
        return; 
    }
    while (c && (c != sep) && (c != '\n')) {
        output_ << "WAIT" << std::endl;
        dst += c;
        input_.get(c);
    }
}

char Repl::skipSeps(char sep) {
    char c;
    input_.get(c);
    while (c == sep) {
        input_.get(c);
    }
    return c;
}

int main() {
    std::string a;
    Repl rep(std::cin);

    rep.run();

    return 0;
}

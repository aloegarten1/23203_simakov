#include "repl.hpp"

#include <memory>

static bool contains(std::vector<char>& vec, char sym) {
    for (auto elem : vec) {
        if (elem == sym) { return true; }
    }

    return false;
} 

namespace {
    std::map<std::string, std::string> limiters {
        std::pair<std::string, std::string>({":", ";"}),
        std::pair<std::string, std::string>({"if", "then"}),
        std::pair<std::string, std::string>({"do", "loop"})
    };
}

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
    bool res = readToken(&t, std::vector<char>{' ', '\t'});
    if (!t) { return false; }
    if(!res) {
        if (t) { delete t; }
        return false;
    }
    res = forth_.execToken(t);
    delete t;
    return res;
}

bool Repl::readExpression(frt::Expression **e, std::string stop) {
    std::string word;
    frt::Token ** t;
    std::vector<frt::Token*> expr_;
    
    while (word != stop) {
        readWord(word, std::vector<char>{' ', '\t', '\n'});
        if (word == stop) { return true; }
        if ("" == word) { return false; }
        if (!isValid(word)) { return false; }

        if (isBasicToken(word, t)) {
            expr_.push_back(*t);
        }

        if ("if" == word) { 
            frt::Expression **body;
            readExpression(body, limiters[word]);
            
        }
    }
}

bool Repl::readToken(frt::Token ** t, std::vector<char> seps) {
    std::string word;
    *t = nullptr;

    readWord(word, seps);
    
    if ("" == word) { return true; }
    if (!isValid(word)) { return false; }
    if (isBasicToken(word, t)) { return true; }

    if (":" == word) {
        std::string name;
        readWord(name, std::vector<char>{'\n', ' ', '\t'});
        
        if (!isValid(name) || isBasicToken(name, nullptr)) {
            std::cerr << "ERROR: Double definition of <<" << name << ">>." << std::endl;
            return false; 
        }

        frt::Expression **e;
        frt::Token *t = *e;
        readExpression(e, limiters[word]);
        forth_.defineWord(name, *e);
    }

    return false;
}

bool Repl::isBasicToken(std::string& word, frt::Token **t) {
    if (isNumber(word)) {
        frt::StackValue val = atoi(word.c_str());
        *t = new frt::ValueToken(val);

        return true;
    }

    if (f_->isRegistered(word)) {
        *t = f_->createCommandByName(word);
        return true;
    }

    if(forth_.isWordDefined(word)) {
        *t = forth_.getDefinition(word);
        return true;
    }

    if(forth_.isVarDefined(word)) {
        frt::StackValue val = forth_.getVarVal(word);
        *t = new frt::ValueToken(val);

        return true;
    }

    return false;
}

void Repl::readWord(std::string& dst, std::vector<char> seps) 
{   
    char c = input_.get();
    if (contains(seps, c)) {
        c = skipSeps(seps);
    }
    while (c && !contains(seps, c) && (c != '\n')) {
        dst += c;
        input_.get(c);
    }
}

char Repl::skipSeps(std::vector<char> seps) {
    char c;
    input_.get(c);
    while (contains(seps, c)) {
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

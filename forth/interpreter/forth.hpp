#pragma once

#include "basics/commands/command_factory.hpp"
#include "basics/basics.hpp"
// #include <memory>

namespace frt {

class Forth {
public:
    Forth() = default;
    Forth(std::ostream& output) : context_(output) {}
    ~Forth() {
        for (auto word: words_){
            delete word.second;
            words_.erase(word.first);
        };
    }

    bool execToken(Token * token);
    void printStack() { context_.printStack(); }

    void defineWord(std::string& name, Expression *expr) {
        words_.insert(
            std::pair<std::string, Expression*>({name, expr})
        );
    }

    Expression* getDefinition(std::string& name) {
        return words_.find(name)->second;
    } 

    bool isWordDefined(std::string& name) {
        return words_.count(name) != 0;
    }

    bool isVarDefined(std::string& name) { 
        return context_.isVarDefined(name);
    }

    bool setVarVal(std::string& name, StackValue val) {
        return context_.setVarVal(name, val);
    }
    
    StackValue getVarVal(std::string& name) { 
        return context_.getVarVal(name);
    }

    void addVar(std::string name, StackValue val) {
        context_.addVar(name, val);
    }

    bool deleteVar(std::string& name) {
        if (!isVarDefined(name)) { return false; }
        context_.deleteVar(name);

        return true;
    }

private:
    ExecutionContext context_;

    std::map<std::string, Expression*> words_;
}; // class Forth

} // namespace frt
#pragma once


#include "basics/valueToken.hpp"
#include "basics/tokens.hpp"
#include "basics/commands/command_factory.hpp"
#include "internals/executionContext.hpp"

#include <memory>

namespace frt {

class Forth {
public:
    Forth() = default;
    Forth(std::ostream& output) : context_(output) {}
    ~Forth() = default;

    bool execToken(Token * token);
    void printStack() { context_.printStack(); }

    void defineWord(std::string& name, Expression *expr) {
        context_.defineWord(name, expr);
    }

    Expression* getDefinition(std::string& name) {
        return context_.getDefintionByName(name);
    } 

    bool isWordDefined(std::string& name) {
        return context_.isWordDefined(name);
    }

    bool isVarDefined(std::string& name) { 
        return context_.isVarDefined(name);
    }

    bool setVarVal(std::string& name, StackValue val) {
        return context_.setVarVal(name, val);
    }
    
    StackValue getVarVal(std::string& name) { 
        return context_.getVarValue(name);
    }

private:
    ExecutionContext context_;
}; // class Forth

} // namespace frt
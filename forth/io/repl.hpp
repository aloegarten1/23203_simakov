#pragma once

#include "../interpreter/forth.hpp"
#include "../interpreter/basics/commands/command_factory.hpp"
#include "scanner.hpp"


#include <iostream>
#include <string>

class Repl
{
public:
    Repl(std::istream &input, std::ostream &output) : scanner_(Scanner(input)), output_(output), forth_(output)
    {
        init(input);
    }

    Repl(std::istream &input) : scanner_(Scanner(input)), output_(std::cout) 
    {
        init(input);
    }

    void run();

private:
    Scanner scanner_;
    bool interactive_;


    std::ostream &output_;
    frt::Forth forth_;


    using CommandFactory = frt::CommandFactory<frt::Command, std::string, std::shared_ptr<frt::Command>(*)()>;
    CommandFactory *f_ = CommandFactory::getInstance();

private:
    
    bool readExpression(std::shared_ptr<frt::Expression> &expr);

    bool isValid(std::string word);
    bool isNumber(std::string word);
    bool isBasicToken(std::string &word, std::shared_ptr<frt::Token>& t);

    void init(std::istream &input);

};

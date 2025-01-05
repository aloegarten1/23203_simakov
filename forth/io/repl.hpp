#pragma once

#include "../interpreter/forth.hpp"
#include "../interpreter/basics/commands/command_factory.hpp"

#include <iostream>
#include <string>

class Repl
{
public:
    Repl(std::istream &input, std::ostream &output) : input_(input), output_(output), forth_(output)
    {
        init();
    }
    Repl(std::istream &stream) : input_(stream), output_(std::cout) 
    {
        init();
    }

    void run();

private:

    bool interactive_;

    std::istream &input_;
    std::ostream &output_;
    frt::Forth forth_;
    std::vector<char> seps = {' ', '\t', '\n'};

    using CommandFactory = frt::CommandFactory<frt::Command, std::string, frt::Command *(*)()>;
    CommandFactory *f_ = CommandFactory::getInstance();

private:
    void loadCommands();

    bool readWord(std::string &dst);
    bool readToken(frt::Token *&t);
    bool readAndEvalToken();
    bool readExpression(frt::Expression *&e, std::string stop);
    // bool readExpression(frt::Expression **e, std::string stop);

    char skipSeps(std::vector<char> seps);
    bool isValid(std::string word);
    bool isNumber(std::string word);
    bool isBasicToken(std::string &word, frt::Token *&t);
    void init();

};

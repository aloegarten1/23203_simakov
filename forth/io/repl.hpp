#pragma once

#include "../interpreter/forth.hpp"
#include "../interpreter/basics/commands/command_factory.hpp"

#include <iostream>
#include <string>

class Repl {
public:
    Repl(std::istream& input, std::ostream& output) : input_(input), output_(output), forth_(output) {}
    Repl(std::istream& stream) : input_(stream), output_(std::cout) {}

    void run();

    void readWord(std::string& dst, char sep);
    bool readToken(frt::Token ** t, char sep);
    bool readAndEvalToken();
private:
    std::istream& input_;
    std::ostream& output_;
    frt::Forth forth_;

    using CommandFactory = frt::CommandFactory<frt::Command, std::string, frt::Command*(*)()>;
    CommandFactory * f_ = CommandFactory::getInstance();
private:
    void loadCommands();
    char skipSeps(char sep = ' ');
    bool isValid(std::string word);
    bool isNumber(std::string word);
};

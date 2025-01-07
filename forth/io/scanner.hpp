#pragma once

#include <iostream>
#include <string>

class Scanner
{
public:
    Scanner(std::istream &input) : input_(input) {};
    ~Scanner() = default;

    bool readWord(std::string &dst);
    
private:
    bool hasRememberedWord;
    std::string rememberedWord;
    void remember(std::string word);
    void forget();

    std::istream &input_;
};
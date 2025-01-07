#include <stdio.h>
#include <iostream>
#include "scanner.hpp"
#include <vector>

static bool contains(std::vector<char> &vec, char sym)
{
    for (auto elem : vec)
    {
        if (elem == sym)
        {
            return true;
        }
    }

    return false;
}

bool Scanner::readWord(std::string &dst)
{
    if (hasRememberedWord)
    {
        dst += rememberedWord;
        forget();
        return true;
    }

    if (input_.eof())
    {
        return false;
    }

    char c;
    this->input_.get(c);

    while (c <= ' ')
    {
        if (input_.eof())
        {
            return false;
        }

        if (c == '\n')
        {
            dst = "\n";
            return true;
        }

        this->input_.get(c);
    }

    while (c > ' ')
    {
        if (input_.eof())
        {
            return true;
        }
        dst += c;

        this->input_.get(c);
    }

    if (c == '\n')
    {
        remember("\n");
    }

    return true;
}

void Scanner::remember(std::string word)
{
    rememberedWord = word;
    hasRememberedWord = true;
}

void Scanner::forget()
{
    rememberedWord = "";
    hasRememberedWord = false;
}

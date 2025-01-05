#include "repl.hpp"
#include "../interpreter/basics/errors.hpp"

#include <stdio.h>
#include <iostream>
#include <unistd.h> // 4 isatty
// #include <memory>

// #define DEBUG

namespace
{
    std::map<std::string, std::string> limiters{
        std::pair<std::string, std::string>({":", ";"}),
        std::pair<std::string, std::string>({"if", "then"}),
        std::pair<std::string, std::string>({"do", "loop"})};
}

namespace Commands
{
    frt::Command *createAdd();
    frt::Command *createSubtract();
    frt::Command *createMult();
    frt::Command *createDiv();

    frt::Command *createG();
    frt::Command *createL();
    frt::Command *createEq();

    frt::Command *createDup();
    frt::Command *createDrop();
    frt::Command *createRot();
    frt::Command *createSwap();
    frt::Command *createOver();

    frt::Command *createDot();
    frt::Command *createEmit();
}

void Repl::init()
{
    interactive_ = false;

    // test whether a file descriptor refers to a terminal
    // dirty hack: 0 - stdin
    if (&input_ == &std::cin && isatty(0))
    {
        interactive_ = true;
    }
}

void Repl::run()
{
    loadCommands();

    if (interactive_)
    {
        output_ << "Welcome to FORTH REPL mode." << std::endl;
    }

    frt::Token *t;

    while (true)
    {
        try
        {
            if (!readToken(t))
            {
                output_.flush();
                return;
            }
        }
        catch (const std::exception &e)
        {
            output_ << e.what() << std::endl;
            continue;
        }
    }
}

bool Repl::readExpression(frt::Expression *&e, std::string stop)
{
    std::string word;
    frt::Token *t;
    std::vector<frt::Token *> expr_;

    while (word != stop)
    {
        bool ok = readWord(word);
        if (!ok)
        {
            // end of input stream reached
            return false;
        }

        if (word == stop)
        {
            e = new frt::Expression(expr_);
            return true;
        }
        if ("" == word)
        {
            throw ForthError("readExpression error: empty word");
        }
        if (!isValid(word))
        {
            throw ForthError("readExpression error: invalid word " + word);
        }

        if (isBasicToken(word, t))
        {
            expr_.push_back(t);
        }

        if (":" == word)
        {
            std::string name;
            bool ok = readWord(name);
            if (!ok)
            {
                // end of input stream reached
                return false;
            }

            if (!isValid(name) || isBasicToken(name, t))
            {

                throw ForthError("readExpression error: Double definition of " + name);
            }

            frt::Expression *e;
            if (!readExpression(e, limiters[word]))
            {
                return false;
            }
            forth_.defineWord(name, e);
        }

        if ("if" == word)
        {
            frt::Expression *body;
            if (!readExpression(body, limiters[word]))
            {
                return false;
            }
            t = new frt::IfThen(body);
            expr_.push_back(t);
        }

        if ("do" == word)
        {
            frt::Expression *body;
            if (!readExpression(body, limiters[word]))
            {
                return false;
            }
            t = new frt::DoLoop(body);
            expr_.push_back(t);
        }

        word = "";
    }

    return true;
}

bool Repl::readToken(frt::Token *&t)
{
    std::string word;
    t = nullptr;

    bool ok = readWord(word);

    if (!ok)
    {
        // end of input stream reached
        return false;
    }

    if ("" == word)
    {
        return true;
    }

    if (!isValid(word))
    {
        throw ForthError("invalid word: " + word);
    }

    if (isBasicToken(word, t))
    {
        if (!forth_.execToken(t))
        {
            delete t;
            throw ForthError("exec error: " + word);
        }
        if (!forth_.isWordDefined(word))
        {
            delete t;
        }
        return true;
    }

    if (":" == word)
    {
        std::string name;
        bool ok = readWord(name);

        if (!ok)
        {
            // end of input stream reached
            return false;
        }

        if (!isValid(name) || isBasicToken(name, t))
        {

            throw ForthError("ERROR: Double definition of: " + name);
        }

        frt::Expression *e;
        bool res = readExpression(e, limiters[word]);
        if (res)
        {
            forth_.defineWord(name, e);
        }
        return true;
    }

    throw ForthError("undefined behavior ");
}

bool Repl::isBasicToken(std::string &word, frt::Token *&t)
{
    if (isNumber(word))
    {
        frt::StackValue val = atoi(word.c_str());
        t = new frt::ValueToken(val);

        return true;
    }

    if (f_->isRegistered(word))
    {
        t = f_->createCommandByName(word);
        return true;
    }

    if (forth_.isWordDefined(word))
    {
        t = forth_.getDefinition(word);
        return true;
    }

    if (forth_.isVarDefined(word))
    {
        frt::StackValue val = forth_.getVarVal(word);
        t = new frt::ValueToken(val);

        return true;
    }

    return false;
}

void Repl::loadCommands()
{
    f_->regist3r("+", Commands::createAdd);
    f_->regist3r("-", Commands::createSubtract);
    f_->regist3r("*", Commands::createMult);
    f_->regist3r("/", Commands::createDiv);

    f_->regist3r(">", Commands::createG);
    f_->regist3r("<", Commands::createL);
    f_->regist3r("=", Commands::createEq);

    f_->regist3r("dup", Commands::createDup);
    f_->regist3r("drop", Commands::createDrop);
    f_->regist3r("swap", Commands::createSwap);
    f_->regist3r("rot", Commands::createRot);
    f_->regist3r("over", Commands::createOver);

    f_->regist3r(".", Commands::createDot);
    f_->regist3r("emit", Commands::createEmit);
}

bool Repl::isValid(std::string word)
{
    for (std::size_t i = 0; i < word.length(); ++i)
    {
        if ((word[i] >= '0') && (word[i] <= '9'))
        {
            continue;
        }
        if (i != 0 && ((word[0] >= '0') && (word[0] <= '9')))
        {
            return false;
        }
    }

    return true;
}

bool Repl::isNumber(std::string word)
{
    for (std::size_t i = 0; i < word.length(); ++i)
    {
        if ((word[i] >= '0') && (word[i] <= '9'))
        {
            continue;
        }
        return false;
    }

    return true;
}

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

bool Repl::readWord(std::string &dst)
{
    try
    {

        if (input_.eof())
        {
            return false;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    char c;

#if defined(DEBUG)
    std::cerr << "readWord debug 1 \n";
#endif

    this->input_.get(c);

#if defined(DEBUG)
    std::cerr << "readWord debug 2 " << c << " \n";
#endif

    while (c <= ' ')
    {
        if (input_.eof())
        {
            return false;
        }

#if defined(DEBUG)
        std::cerr << "readWord debug 3 \n";
#endif
        this->input_.get(c);

#if defined(DEBUG)
        std::cerr << "readWord debug 4 " << c << " \n";
#endif
    }

    while (c > ' ')
    {
        if (input_.eof())
        {
            return true;
        }
        dst += c;

#if defined(DEBUG)
        std::cerr << "readWord debug 5 \n";
#endif
        this->input_.get(c);

#if defined(DEBUG)
        std::cerr << "readWord debug 6 " << c << " \n";
#endif
    }

    return true;
}

char Repl::skipSeps(std::vector<char> seps)
{
    char c;
    input_.get(c);
    while (contains(seps, c))
    {
        input_.get(c);
    }
    return c;
}

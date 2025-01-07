#include "repl.hpp"
#include "../interpreter/basics/errors.hpp"

#include <stdio.h>
#include <iostream>
#include <unistd.h> // 4 isatty
// #include <memory>

// #define DEBUG

namespace Commands
{
    std::shared_ptr<frt::Command> createAdd();
    std::shared_ptr<frt::Command> createSubtract();
    std::shared_ptr<frt::Command> createMult();
    std::shared_ptr<frt::Command> createDiv();
    std::shared_ptr<frt::Command> createMod();

    std::shared_ptr<frt::Command> createG();
    std::shared_ptr<frt::Command> createL();
    std::shared_ptr<frt::Command> createEq();

    std::shared_ptr<frt::Command> createDup();
    std::shared_ptr<frt::Command> createDrop();
    std::shared_ptr<frt::Command> createRot();
    std::shared_ptr<frt::Command> createSwap();
    std::shared_ptr<frt::Command> createOver();

    std::shared_ptr<frt::Command> createDot();
    std::shared_ptr<frt::Command> createEmit();

    std::shared_ptr<frt::Command> createCr();

}

void Repl::init(std::istream &input)
{
    interactive_ = false;

    // test whether a file descriptor refers to a terminal
    // dirty hack: 0 - stdin
    if (&input == &std::cin && isatty(0))
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

    while (true)
    {
        try
        {
            std::shared_ptr<frt::Expression> exprP;

            if (!readExpression(exprP))
            {
                break;
            }

            if (typeid(exprP.get()) == typeid(frt::Declaration))
            {
                frt::Declaration *decl = (frt::Declaration *)exprP.get();
                forth_.defineWord(decl->commandName, decl->commandExpr);
            }
            else
            {

                forth_.execToken(exprP.get());
            }
        }
        catch (const std::exception &e)
        {
            output_ << e.what() << std::endl;
            continue;
        }
    }
}

bool Repl::readExpression(std::shared_ptr<frt::Expression> &expr)
{
    std::vector<std::shared_ptr<frt::Token>> tokens;

    while (true)
    {
        std::string word;
        std::shared_ptr<frt::Token> t;

        bool ok = scanner_.readWord(word);

        if (!ok)
        {
            // end of input stream reached
            if (tokens.size() > 0)
            {
                break;
            }

            return false;
        }

        if ("" == word)
        {
            continue;
        }

        if (";" == word)
        {
            break;
        }

        if (isBasicToken(word, t))
        {
            tokens.push_back(t);
            continue;
        }

        if (":" == word)
        {

            std::string name;

            bool ok = scanner_.readWord(word);

            if (!ok)
            {
                // end of input stream reached
                if (tokens.size() > 0)
                {
                    break;
                }

                return false;
            }

            std::shared_ptr<frt::Expression> body;

            if (!readExpression(body))
            {
                // TODO - tests cover
                return false;
            }

            t = std::make_shared<frt::Declaration>(name, body);
            tokens.push_back(t);

            continue;
        }

        if ("if" == word)
        {
            std::shared_ptr<frt::Expression> body;
            if (!readExpression(body))
            {
                return false;
            }
            t = std::make_shared<frt::IfThen>(body);
            tokens.push_back(t);

            continue;
        }

        if ("then" == word)
        {
            continue;
        }

        if ("else" == word)
        {
            t = std::make_shared<frt::IfElse>();
            tokens.push_back(t);

            continue;
        }

        if ("do" == word)
        {

            std::shared_ptr<frt::Expression> body;
            if (!readExpression(body))
            {
                return false;
            }
            // forth_.deleteVar(name);
            t = std::make_shared<frt::DoLoop>(body);
            tokens.push_back(t);

            continue;
        }

        if ("i" == word)
        {
            t = std::make_shared<frt::DoLoopIterator>();
            tokens.push_back(t);
        }

        if ("\n" == word)
        {
            if (interactive_ && tokens.size() > 0)
            {
                break;
            }
            continue;
        }
    }

    expr = std::make_shared<frt::Expression>(tokens);

    return true;
}

bool Repl::isBasicToken(std::string &word, std::shared_ptr<frt::Token> &t)
{
#if defined(DEBUG)
    output_ << word << std::endl;
#endif

    if (isNumber(word))
    {
        frt::StackValue val = atoi(word.c_str());
        t = std::make_shared<frt::ValueToken>(val);

        return true;
    }

    // ."string output"
    if (word.length() > 2 && word[0] == '.' && word[1] == '"' && word[word.length() - 1] == '"')
    {

        std::string val = word.substr(2, word.length() - 3);
        t = std::make_shared<frt::StringOutToken>(val);
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

    return false;
}

void Repl::loadCommands()
{
    f_->regist3r("+", Commands::createAdd);
    f_->regist3r("-", Commands::createSubtract);
    f_->regist3r("*", Commands::createMult);
    f_->regist3r("/", Commands::createDiv);
    f_->regist3r("mod", Commands::createMod);

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

    f_->regist3r("cr", Commands::createCr);
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

        // negative
        if (i == 0 && word.length() > 1 && word[i] == '-')
        {
            continue;
        }
        return false;
    }

    return true;
}

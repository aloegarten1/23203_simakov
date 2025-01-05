#include "../io/repl.hpp"

#include <gtest/gtest.h>

using namespace std;


Repl MockRepl(std::string input){


    std::istringstream is(input);
    return Repl(is);
}

TEST(replt, test1)
{
}

TEST(NumberCheck, PushOnePositiveNumber)
{
    Repl repl = MockRepl("1");
    repl.run();
    // Interpreter &i = Interpreter::getInstance();
    // std::string input = "1";
    // EXPECT_EQ(i.interpret(input), "< ok\n");

    // input = "drop 12345 .";
    // EXPECT_EQ(i.interpret(input), "12345\n");
}

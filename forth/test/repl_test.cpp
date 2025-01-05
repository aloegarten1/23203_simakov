#include "../io/repl.hpp"

#include <gtest/gtest.h>

using namespace std;

Repl MockRepl(std::string input, std::ostream &os)
{

    std::istringstream is(input);
    return Repl(is, os);
}

TEST(REPL, PushOnePositiveNumber)
{
    std::ostringstream os;

    Repl repl = MockRepl("123\n.\n", os);
    repl.run();

    EXPECT_EQ(os.str(), "123 ");
}


TEST(REPL, PLUS_BAD)
{
    std::ostringstream os;

    Repl repl = MockRepl("2\n2\n+\n.\n", os);
    repl.run();

    EXPECT_NE(os.str(), "44");
}

TEST(REPL, PLUS_BAD_ES)
{
    std::ostringstream os;

    Repl repl = MockRepl("55\n+\n", os);
    repl.run();

    EXPECT_EQ(os.str(), "exec error: +\n");
}

TEST(REPL, PLUS_GOOD)
{
    std::ostringstream os;

    Repl repl = MockRepl("2\n2\n+\n.\n", os);
    repl.run();

    EXPECT_EQ(os.str(), "4 ");
}


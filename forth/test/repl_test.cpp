#include "../io/repl.hpp"

#include <gtest/gtest.h>

using namespace std;

/*

Repl MockRepl(std::string input, std::ostream &os)
{

    std::istringstream is(input);
    return Repl(is, os);
}

*/

std::string repl(std::string input)
{
    std::ostringstream os;
    std::istringstream is(input);
    Repl repl = Repl(is, os);
    repl.run();
    return os.str();
}

TEST(REPL, PushOnePositiveNumber)
{
    std::string res = repl("123\n.");
    EXPECT_EQ(res, "123");
}

TEST(REPL, PLUS_BAD)
{
    std::string res = repl("2\n2\n+\n.\n");
    EXPECT_NE(res, "44");
}

TEST(REPL, PLUS_BAD_ES)
{
    std::string res = repl("55\n+\n");
    EXPECT_EQ(res, "exec error: +\n");
}

TEST(REPL, PLUS_GOOD)
{

    std::string res = repl("2\n2\n+\n.\n");
    EXPECT_EQ(res, "4");
}


TEST(REPL, MINUS_BAD)
{
    std::string res = repl("2\n2\n-\n.\n");
    EXPECT_NE(res, "44");
}

TEST(REPL, MINUS_BAD_ES)
{
    std::string res = repl("55\n-\n");
    EXPECT_EQ(res, "exec error: -\n");
}

TEST(REPL, MINUS_GOOD)
{

    std::string res = repl("5\n10\n-\n.\n");
    EXPECT_EQ(res, "5");
}

// ref: https://docs.google.com/document/d/15ddUtdUvO8nRUtTUOUUR2OzP-fh3AZACDghveHQohJI/edit?tab=t.0
TEST(REPL, CR)
{

    std::string res = repl("100 200 . cr .");
    EXPECT_EQ(res, "200\n100");
}

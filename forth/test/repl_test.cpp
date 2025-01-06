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



TEST(REPL, MULT_BAD)
{
    std::string res = repl("2\n2\n*\n.\n");
    EXPECT_NE(res, "44");
}

TEST(REPL, MULT_BAD_ES)
{
    std::string res = repl("55\n*\n");
    EXPECT_EQ(res, "exec error: *\n");
}

TEST(REPL, MULT_GOOD)
{
    std::string res = repl("3\n3\n*\n.\n");
    EXPECT_EQ(res, "9");
}

TEST(REPL, DIV_BAD)
{
    std::string res = repl("20\n20\n/\n.\n");
    EXPECT_NE(res, "44");
}

TEST(REPL, DIV_BAD_ES)
{
    std::string res = repl("55\n/\n");
    EXPECT_EQ(res, "exec error: /\n");
}

TEST(REPL, DIV_GOOD)
{
    std::string res = repl("5 -50 / .");
    EXPECT_EQ(res, "-10");
}

TEST(REPL, MOD_BAD)
{
    std::string res = repl("20 20 mod .");
    EXPECT_NE(res, "44");
}

TEST(REPL, MOD_BAD_ES)
{
    std::string res = repl("55 mod");
    EXPECT_EQ(res, "exec error: mod\n");
}

TEST(REPL, MOD_GOOD)
{
    std::string res = repl("13 30 mod .");
    EXPECT_EQ(res, "4");
}


// ref: https://docs.google.com/document/d/15ddUtdUvO8nRUtTUOUUR2OzP-fh3AZACDghveHQohJI/edit?tab=t.0
TEST(REPL, CR)
{

    std::string res = repl("100 200 . cr .");
    EXPECT_EQ(res, "200\n100");
}


TEST(REPL, DUP)
{

    std::string res = repl("100 200 dup . cr . cr .");
    EXPECT_EQ(res, "200\n200\n100");
}


TEST(REPL, DROP)
{

    std::string res = repl("100 150 200 drop . cr .");
    EXPECT_EQ(res, "150\n100");
}


TEST(REPL, SWAP)
{

    std::string res = repl("13 17 19 swap . . .");
    EXPECT_EQ(res, "171913");
}



TEST(REPL, ROT)
{

    std::string res = repl("4 1 2 3 rot . . . .");
    EXPECT_EQ(res, "2134");
}

TEST(REPL, OVER)
{

    std::string res = repl("3 2 1 over . . . .");
    EXPECT_EQ(res, "2123");
}



TEST(REPL, EMIT)
{

    std::string res = repl("65 emit");
    EXPECT_EQ(res, "A");
}



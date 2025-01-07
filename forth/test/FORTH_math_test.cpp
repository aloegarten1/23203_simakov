#include "../io/repl.hpp"
#include "repl.hpp"
#include <gtest/gtest.h>

using namespace std;
 

TEST(FORTH_MATH, PLUS_BAD)
{
    std::string res = repl("2\n2\n+\n.\n");
    EXPECT_NE(res, "44");
}

TEST(FORTH_MATH, PLUS_BAD_ES)
{
    std::string res = repl("55\n+\n");
    EXPECT_EQ(res, "not enougth values in stack for +\n");
}

TEST(FORTH_MATH, PLUS_GOOD)
{

    std::string res = repl("2\n2\n+\n.\n");
    EXPECT_EQ(res, "4");
}


TEST(FORTH_MATH, MINUS_BAD)
{
    std::string res = repl("2\n2\n-\n.\n");
    EXPECT_NE(res, "44");
}

TEST(FORTH_MATH, MINUS_BAD_ES)
{
    std::string res = repl("55\n-\n");
    EXPECT_EQ(res, "not enougth values in stack for -\n");
}

TEST(FORTH_MATH, MINUS_GOOD_1)
{

    std::string res = repl("100 40 - .");
    EXPECT_EQ(res, "60");
}

TEST(FORTH_MATH, MINUS_GOOD_2)
{

    std::string res = repl("40 60 - .");
    EXPECT_EQ(res, "-20");
}

TEST(FORTH_MATH, MINUS_GOOD_3)
{

    std::string res = repl("-5 -3 - .");
    EXPECT_EQ(res, "-2");
}



TEST(FORTH_MATH, MULT_BAD)
{
    std::string res = repl("2\n2\n*\n.\n");
    EXPECT_NE(res, "44");
}

TEST(FORTH_MATH, MULT_BAD_ES)
{
    std::string res = repl("55\n*\n");
    EXPECT_EQ(res, "not enougth values in stack for *\n");
}

TEST(FORTH_MATH, MULT_GOOD)
{
    std::string res = repl("3\n3\n*\n.\n");
    EXPECT_EQ(res, "9");
}

TEST(FORTH_MATH, DIV_BAD)
{
    std::string res = repl("20\n20\n/\n.\n");
    EXPECT_NE(res, "44");
}

TEST(FORTH_MATH, DIV_BAD_ES)
{
    std::string res = repl("55\n/\n");
    EXPECT_EQ(res, "not enougth values in stack for /\n");
}

TEST(FORTH_MATH, DIV_GOOD_1)
{
    std::string res = repl("4 -2 / .");
    EXPECT_EQ(res, "-2");
}

TEST(FORTH_MATH, DIV_GOOD_2)
{
    std::string res = repl("4 4 / .");
    EXPECT_EQ(res, "1");
}

TEST(FORTH_MATH, DIV_GOOD_3)
{
    std::string res = repl("4 5 / .");
    EXPECT_EQ(res, "0");
}

TEST(FORTH_MATH, DIV_ZERO_1)
{
    std::string res = repl("0 2025 / .");
    EXPECT_EQ(res, "0");
}

TEST(FORTH_MATH, DIV_ZERO_2)
{
    std::string res = repl("2025 0 /");
    EXPECT_EQ(res, "Division by zero\n");
}

TEST(FORTH_MATH, MOD_BAD)
{
    std::string res = repl("20 20 mod .");
    EXPECT_NE(res, "44");
}

TEST(FORTH_MATH, MOD_BAD_ES)
{
    std::string res = repl("55 mod");
    EXPECT_EQ(res, "not enougth values in stack for mod\n");
}

TEST(FORTH_MATH, MOD_GOOD)
{
    std::string res = repl("30 13 mod .");
    EXPECT_EQ(res, "4");
}

TEST(FORTH_MATH, MOD_ZERO)
{
    std::string res = repl("2025 0 mod");
    EXPECT_EQ(res, "Division by zero\n");
}


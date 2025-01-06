#include "../io/repl.hpp"
#include "repl.hpp"
#include <gtest/gtest.h>

using namespace std;
 
TEST(FORTH_BASIC, PushOnePositiveNumber)
{
    std::string res = repl("123\n.");
    EXPECT_EQ(res, "123");
}


TEST(FORTH_BASIC, CR)
{

    std::string res = repl("100 200 . cr .");
    EXPECT_EQ(res, "200\n100");
}


TEST(FORTH_BASIC, DUP)
{

    std::string res = repl("100 200 dup . cr . cr .");
    EXPECT_EQ(res, "200\n200\n100");
}


TEST(FORTH_BASIC, DROP)
{

    std::string res = repl("100 150 200 drop . cr .");
    EXPECT_EQ(res, "150\n100");
}


TEST(FORTH_BASIC, SWAP)
{

    std::string res = repl("13 17 19 swap . . .");
    EXPECT_EQ(res, "171913");
}



TEST(FORTH_BASIC, ROT)
{

    std::string res = repl("4 1 2 3 rot . . . .");
    EXPECT_EQ(res, "2134");
}

TEST(FORTH_BASIC, OVER)
{

    std::string res = repl("3 2 1 over . . . .");
    EXPECT_EQ(res, "2123");
}



TEST(FORTH_BASIC, EMIT)
{

    std::string res = repl("65 emit");
    EXPECT_EQ(res, "A");
}



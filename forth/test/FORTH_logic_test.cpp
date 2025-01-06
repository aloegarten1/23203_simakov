#include "../io/repl.hpp"
#include "repl.hpp"
#include <gtest/gtest.h>

using namespace std;
 
TEST(FORTH_LOGIC, GT_0)
{
    std::string res = repl("1 >");
    EXPECT_EQ(res, "exec error: >\n");
}

TEST(FORTH_LOGIC, GT_1)
{
    std::string res = repl("10 5 > .");
    EXPECT_EQ(res, "-1");
}


TEST(FORTH_LOGIC, GT_2)
{
    std::string res = repl("5 10 > .");
    EXPECT_EQ(res, "0");
}

TEST(FORTH_LOGIC, GT_3)
{
    std::string res = repl("5 5 > .");
    EXPECT_EQ(res, "0");
}

TEST(FORTH_LOGIC, LT_1)
{
    std::string res = repl("-1 1 < .");
    EXPECT_EQ(res, "-1");
}

TEST(FORTH_LOGIC, LT_2)
{
    std::string res = repl("1 -1 < .");
    EXPECT_EQ(res, "0");
}

TEST(FORTH_LOGIC, LT_3)
{
    std::string res = repl("1 1 < 0 .");
    EXPECT_EQ(res, "0");
}

TEST(FORTH_LOGIC, EQ_1)
{
    std::string res = repl("=");
    EXPECT_EQ(res, "exec error: =\n");
}

TEST(FORTH_LOGIC, EQ_2)
{
    std::string res = repl("1 =");
    EXPECT_EQ(res, "exec error: =\n");
}

TEST(FORTH_LOGIC, EQ_3)
{
    std::string res = repl("1 1 = .");
    EXPECT_EQ(res, "-1");
}

TEST(FORTH_LOGIC, EQ_4)
{
    std::string res = repl("5 6 = .");
    EXPECT_EQ(res, "0");
}


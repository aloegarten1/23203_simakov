#include "../io/repl.hpp"
#include "repl.hpp"
#include <gtest/gtest.h>

using namespace std;


 
TEST(FORTH_LOOP, DO_LOOP_ES_1)
{
    std::string res = repl("do 86 emit loop ;");
    EXPECT_EQ(res, "do loop error: not enought values in stack\n");
}

TEST(FORTH_LOOP, DO_LOOP_ES_2)
{
    std::string res = repl("100500 do 86 emit loop ;");
    EXPECT_EQ(res, "do loop error: not enought values in stack\n");
}


TEST(FORTH_LOOP, DO_LOOP_1)
{
    std::string res = repl("45 2 over swap 1 do over * loop swap drop ; \n .");
    EXPECT_EQ(res, "2025");
}

TEST(FORTH_LOOP, DO_LOOP_ITER)
{
    std::string res = repl("9 1 + 0 swap 1 do i + loop ; \n .");
    EXPECT_EQ(res, "45");
}


TEST(FORTH_IF, IF_BR1_FALSE)
{
    std::string res = repl("85 emit\n 0 if 87 emit then ;\n  85 emit");
    EXPECT_EQ(res, "UU");
}

TEST(FORTH_IF, IF_BR1_TRUE)
{
    std::string res = repl("85 emit\n 1 if 87 emit then ;\n  85 emit");
    EXPECT_EQ(res, "UWU");
}

TEST(FORTH_IF, IF_BR2_FALSE)
{
     
    std::string res = repl("85 emit\n 0  if 65 emit else 66 emit then ;\n85 emit");
    EXPECT_EQ(res, "UBU");
}

TEST(FORTH_IF, IF_BR2_TRUE)
{
    std::string res = repl("85 emit\n 1  if 65 emit else 66 emit then ;\n85 emit");
    EXPECT_EQ(res, "UAU");
}

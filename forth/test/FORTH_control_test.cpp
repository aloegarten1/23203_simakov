#include "../io/repl.hpp"
#include "repl.hpp"
#include <gtest/gtest.h>

using namespace std;


 
TEST(FORTH_LOOP, DO_LOOP_ES_1)
{
    std::string res = repl(": f1 do 86 emit loop ;  \n f1");
    EXPECT_EQ(res, "do loop error: not enought values in stack\n");
}

TEST(FORTH_LOOP, DO_LOOP_ES_2)
{
    std::string res = repl(": f1 do 86 emit loop ;  \n 100500 f1");
    EXPECT_EQ(res, "do loop error: not enought values in stack\n");
}


TEST(FORTH_LOOP, DO_LOOP_1)
{
    std::string res = repl(": pow over swap 1 do over * loop swap drop ; \n45 2 pow .");
    EXPECT_EQ(res, "2025");
}

TEST(FORTH_LOOP, DO_LOOP_ITER)
{
    std::string res = repl(": nsum 1 + 0 swap 1 do i + loop ; \n9 nsum .");
    EXPECT_EQ(res, "45");
}


TEST(FORTH_LOOP, IF_BR1_FALSE)
{
    std::string res = repl(": ab if 87 emit then ;\n85 emit 0 ab 85 emit");
    EXPECT_EQ(res, "UU");
}

TEST(FORTH_LOOP, IF_BR1_TRUE)
{
    std::string res = repl(": ab if 87 emit then ;\n85 emit 1 ab 85 emit");
    EXPECT_EQ(res, "UWU");
}

TEST(FORTH_LOOP, IF_BR2_FALSE)
{
     
    std::string res = repl(": ab if 65 emit then 66 emit else ;\n85 emit 0 ab 85 emit");
    EXPECT_EQ(res, "UBU");
}

TEST(FORTH_LOOP, IF_BR2_TRUE)
{
    std::string res = repl(": ab if 65 emit then 66 emit else ;\n85 emit 1 ab 85 emit");
    EXPECT_EQ(res, "UAU");
}


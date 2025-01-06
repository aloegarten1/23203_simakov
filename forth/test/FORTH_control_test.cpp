#include "../io/repl.hpp"
#include "repl.hpp"
#include <gtest/gtest.h>

using namespace std;
 
TEST(FORTH_LOOP, GT_0)
{
    std::string res = repl(": pow over swap 1 do over * loop drop ; \n10 10 pow \n. cr ");
    EXPECT_EQ(res, "100000");
}
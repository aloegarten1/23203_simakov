#include "../interpreter/basics/expression.hpp"
#include "../interpreter/basics/tokens.hpp"

#include <gtest/gtest.h>

TEST(Expression, exec) {
    frt::ExecutionContext ctx;
    frt::Token *t1, *t2, *t3, *t4;

    t1 = new frt::ValueToken(4);
    t2 = new frt::ValueToken(5);
    t3 = new frt::Dup();

    std::vector<frt::Token *> expr = {t1, t2, t3};
    t4 = new frt::Expression(expr);

    ASSERT_TRUE(t4->exec(ctx));
    delete t4;

    ASSERT_EQ(ctx.getStackDepth(), 3);
    ASSERT_EQ(ctx.getTopVal(), 5);
    ASSERT_EQ(ctx.getSecondFromTop(), 5);
}

#include "../interpreter/basics/expression.hpp"
#include "../interpreter/basics/basics.hpp"

#include <gtest/gtest.h>

TEST(Expression, exec) {
    frt::ExecutionContext ctx;
    std::shared_ptr<frt::Token> t1, t2, t3, t4;

    t1 = std::make_shared<frt::ValueToken>(4);
    t2 = std::make_shared<frt::ValueToken>(5);
    t3 = std::make_shared<frt::Dup>();

    std::vector<std::shared_ptr<frt::Token>> expr = {t1, t2, t3};
    t4 = std::make_shared<frt::Expression>(expr);

    ASSERT_TRUE(t4->exec(ctx));

    ASSERT_EQ(ctx.getStackDepth(), 3);
    ASSERT_EQ(ctx.getTopVal(), 5);
    ASSERT_EQ(ctx.getSecondFromTop(), 5);
}

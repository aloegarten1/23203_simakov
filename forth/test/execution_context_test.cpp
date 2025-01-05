#include "../interpreter/internals/executionContext.hpp"

#include <gtest/gtest.h>

TEST(contextMethod, pushVal)
{
    frt::ExecutionContext context;

    ASSERT_TRUE(context.isStackEmpty());
    ASSERT_EQ(context.getStackDepth(), 0);
    context.pushVal(1);
    ASSERT_FALSE(context.isStackEmpty());
    ASSERT_EQ(context.getTopVal(), 1);
    ASSERT_EQ(context.getStackDepth(), 1);

    for (std::size_t i = 2; i < 100; ++i)
    {
        context.pushVal(i);
        ASSERT_FALSE(context.isStackEmpty());
        ASSERT_EQ(context.getTopVal(), i);
        ASSERT_EQ(context.getStackDepth(), i);
    }
}

TEST(contextMethod, popVal)
{
    frt::ExecutionContext context;

    ASSERT_TRUE(context.isStackEmpty());
    ASSERT_EQ(context.getStackDepth(), 0);
    ASSERT_FALSE(context.popVal());

    for (std::size_t i = 1; i < 100; ++i)
    {
        context.pushVal(i);
        ASSERT_FALSE(context.isStackEmpty());
        ASSERT_EQ(context.getTopVal(), i);
        ASSERT_EQ(context.getStackDepth(), i);
    }

    for (std::size_t i = 98; i > 0; --i)
    {
        ASSERT_TRUE(context.popVal());
        ASSERT_EQ(context.getTopVal(), i);
        ASSERT_EQ(context.getStackDepth(), i);
        ASSERT_FALSE(context.isStackEmpty());
    }

    ASSERT_TRUE(context.popVal());
    ASSERT_EQ(context.getStackDepth(), 0);
    ASSERT_TRUE(context.isStackEmpty());
    ASSERT_FALSE(context.popVal());
}

TEST(contextMethod, getSecondFromTop)
{
    frt::ExecutionContext context;

    ASSERT_TRUE(context.isStackEmpty());
    ASSERT_EQ(context.getStackDepth(), 0);

    context.pushVal(1);
    ASSERT_EQ(context.getTopVal(), 1);
    ASSERT_EQ(context.getStackDepth(), 1);

    context.pushVal(2);
    ASSERT_EQ(context.getTopVal(), 2);
    ASSERT_EQ(context.getStackDepth(), 2);
    ASSERT_EQ(context.getSecondFromTop(), 1);

    context.pushVal(1);
    ASSERT_EQ(context.getTopVal(), 1);
    ASSERT_EQ(context.getStackDepth(), 3);
    ASSERT_EQ(context.getSecondFromTop(), 2);
}

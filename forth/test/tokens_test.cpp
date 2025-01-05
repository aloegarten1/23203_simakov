#include "../interpreter/basics/valueToken.hpp"
#include "../interpreter/basics/commands/dup.hpp"
#include "../interpreter/internals/executionContext.hpp"

#include <gtest/gtest.h>

TEST(ValueToken, exec) {
    frt::ExecutionContext context;

    ASSERT_TRUE(context.isStackEmpty());

    for (std::size_t i = 1; i < 10; ++i) {
        frt::ValueToken val(i);
        ASSERT_TRUE(val.exec(context));
        ASSERT_FALSE(context.isStackEmpty());
        ASSERT_EQ(context.getStackDepth(), i);
        ASSERT_EQ(context.getTopVal(), i);
    }
}

TEST(Command, Dup) {
    frt::ExecutionContext context;
    frt::Dup command;

    ASSERT_TRUE(context.isStackEmpty());
    ASSERT_EQ(context.getStackDepth(), 0);
    ASSERT_FALSE(command.exec(context));

    for (std::size_t i = 1; i < 10; ++i) {
        frt::ValueToken val(i);
        ASSERT_TRUE(val.exec(context));
        ASSERT_FALSE(context.isStackEmpty());
        ASSERT_EQ(context.getStackDepth(), i);
        ASSERT_EQ(context.getTopVal(), i);
    }

    for (std::size_t i = 1; i < 10; ++i) {
        ASSERT_TRUE(command.exec(context));
        ASSERT_FALSE(context.isStackEmpty());
        ASSERT_EQ(context.getStackDepth(), 9 + i);
        ASSERT_EQ(context.getTopVal(), 9);
    }
}
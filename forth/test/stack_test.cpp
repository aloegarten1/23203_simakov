#include "../interpreter/internals/stack/stack.hpp"

#include <gtest/gtest.h>

using namespace std;

TEST(method, push) {
    frt::Stack s;

    ASSERT_TRUE(s.isEmpty());

    s.push(1);
    ASSERT_FALSE(s.isEmpty());
    ASSERT_EQ(s.top(), 1);

    for (frt::StackValue i = 0; i < 100; ++i) {
        s.push(i);
        ASSERT_EQ(s.top(), i);
        ASSERT_EQ(s.depth(), 2 + i);
    }
}

TEST(method, pop) {
    frt::Stack s;

    ASSERT_TRUE(s.isEmpty());
    ASSERT_FALSE(s.pop());
    for (frt::StackValue i = 0; i < 100; ++i) {
        s.push(i);
        ASSERT_EQ(s.top(), i);
        ASSERT_EQ(s.depth(), 1 + i);
    }
    ASSERT_FALSE(s.isEmpty());
    for (frt::StackValue i = 0; i < 100; ++i) {
        ASSERT_TRUE(s.pop());
        ASSERT_EQ(s.depth(), 99 - i);
    }
    ASSERT_TRUE(s.isEmpty());
}

TEST(method, getSecondFromTop) {
    frt::Stack s;

    ASSERT_TRUE(s.isEmpty());
    s.push(1);
    ASSERT_EQ(s.top(), 1);
    s.push(2);
    ASSERT_EQ(s.top(), 2);
    ASSERT_EQ(s.getSecondFromTop(), 1);
    s.push(3);
    ASSERT_EQ(s.top(), 3);
    ASSERT_EQ(s.getSecondFromTop(), 2);
}

TEST(method, swap) {
    frt::Stack s;

    ASSERT_TRUE(s.isEmpty());
    ASSERT_EQ(s.depth(), 0);
    ASSERT_FALSE(s.swap());
    
    s.push(1);
    ASSERT_FALSE(s.isEmpty());
    ASSERT_EQ(s.depth(), 1);
    ASSERT_EQ(s.top(), 1);
    ASSERT_FALSE(s.swap());

    s.push(2);
    ASSERT_FALSE(s.isEmpty());
    ASSERT_EQ(s.depth(), 2);
    ASSERT_EQ(s.top(), 2);
    ASSERT_EQ(s.getSecondFromTop(), 1);

    ASSERT_TRUE(s.swap());
    ASSERT_EQ(s.depth(), 2);
    ASSERT_EQ(s.top(), 1);
    ASSERT_EQ(s.getSecondFromTop(), 2);

    s.push(3);
    ASSERT_FALSE(s.isEmpty());
    ASSERT_EQ(s.depth(), 3);
    ASSERT_EQ(s.top(), 3);
    ASSERT_EQ(s.getSecondFromTop(), 1);

    ASSERT_TRUE(s.swap());
    ASSERT_EQ(s.depth(), 3);
    ASSERT_EQ(s.top(), 1);
    ASSERT_EQ(s.getSecondFromTop(), 3);
}

TEST(method, rot) {
    frt::Stack s;

    ASSERT_TRUE(s.isEmpty());
    ASSERT_EQ(s.depth(), 0);
    ASSERT_FALSE(s.rot());
    
    s.push(1);
    ASSERT_FALSE(s.isEmpty());
    ASSERT_EQ(s.depth(), 1);
    ASSERT_EQ(s.top(), 1);
    ASSERT_FALSE(s.rot());

    s.push(2);
    ASSERT_FALSE(s.isEmpty());
    ASSERT_EQ(s.depth(), 2);
    ASSERT_EQ(s.top(), 2);
    ASSERT_EQ(s.getSecondFromTop(), 1);
    ASSERT_FALSE(s.rot());

    s.push(3);
    ASSERT_FALSE(s.isEmpty());
    ASSERT_EQ(s.depth(), 3);
    ASSERT_EQ(s.top(), 3);
    ASSERT_EQ(s.getSecondFromTop(), 2);

    ASSERT_TRUE(s.rot());
    ASSERT_EQ(s.depth(), 3);
    ASSERT_EQ(s.top(), 2);
    ASSERT_EQ(s.getSecondFromTop(), 1);
    
    ASSERT_TRUE(s.pop());
    ASSERT_EQ(s.depth(), 2);
    ASSERT_EQ(s.getSecondFromTop(), 3);
}

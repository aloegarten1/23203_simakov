#include <gtest/gtest.h>

TEST(constructor, copy_constructor) {
    HashTable a;
    a.insert(Key("Anton"), Value(19, 67));
    a.insert(Key("Aleksey"), Value(21, 52));
    a.insert(Key("Igor"), Value(20, 87));
    a.insert(Key("Fedya"), Value(18, 54));
}
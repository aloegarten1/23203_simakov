#include <gtest/gtest.h>
#include "../lib/hash_table.h"

TEST(constructor, copy_constructor) {
    HashTable a;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));

    HashTable b(a);

    EXPECT_EQ(b.size(), 4);
    EXPECT_TRUE(b.contains(Key("alex")));
    EXPECT_TRUE(b.contains(Key("freeman")));
    EXPECT_TRUE(b.contains(Key("denis")));
    EXPECT_TRUE(b.contains(Key("paul")));
}

TEST(operator, assigment) {
    HashTable a;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    
    HashTable b = a;

    EXPECT_EQ(b.size(), 4);
    EXPECT_TRUE(b.contains(Key("alex")));
    EXPECT_TRUE(b.contains(Key("freeman")));
    EXPECT_TRUE(b.contains(Key("denis")));
    EXPECT_TRUE(b.contains(Key("paul")));

}

TEST(operator, subscript) {
    HashTable a;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));

    Value testT = a[Key("paul")];
    EXPECT_TRUE(testT.age == 14 && testT.weight == 88);

    Value testF = a[Key("jpegmafia")];
    Value testA = a[Key("allah")];

    EXPECT_EQ(a.size(), 6);
    EXPECT_TRUE(testF.age == 0 && testF.weight == 0);
    EXPECT_TRUE(testA.age == 0 && testA.weight == 0);
}

TEST(method, swap) {
    HashTable a;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));

    HashTable b;
    b.insert(Key("eh"), Value(13, 100));

    a.swap(b);
    EXPECT_EQ(b.size(), 4);
    EXPECT_EQ(a.size(), 1);
    EXPECT_TRUE(a.contains(Key("eh")));
    EXPECT_TRUE(b.contains(Key("alex")));
    EXPECT_TRUE(b.contains(Key("freeman")));
    EXPECT_TRUE(b.contains(Key("denis")));
    EXPECT_FALSE(b.contains(Key("eh")));
    EXPECT_TRUE(b.contains(Key("paul")));
}

TEST(method, insert) {
    HashTable a;
    EXPECT_TRUE(a.empty());
    a.insert(Key("IGOR."), Value(19, 55));
    EXPECT_FALSE(a.empty());
    EXPECT_TRUE(a.contains(Key("IGOR.")));
    EXPECT_EQ(a.size(), 1);
}

TEST(method, erase) {
    HashTable a;
    EXPECT_FALSE(a.erase(Key("aloegarten.")));

    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));

    EXPECT_FALSE(a.erase(Key("ROOTMAN")));
    EXPECT_TRUE(a.erase(Key("alex")));
    EXPECT_EQ(a.size(), 3);
    EXPECT_FALSE(a.erase(Key("greg lake")));
}

TEST(method, clear) {
    HashTable a;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));

    EXPECT_EQ(a.size(), 4);
    a.clear();
    EXPECT_EQ(a.size(), 0);
}

TEST(method, size) {
    HashTable a;
    EXPECT_EQ(a.size(), 0);
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    EXPECT_EQ(a.size(), 4);
}

TEST(method, empty) {
    HashTable a;
    EXPECT_TRUE(a.empty());
    a.insert(Key("alex"), Value(19, 67));
    EXPECT_FALSE(a.empty());
}

TEST(operator, equal) {
    HashTable a, b;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));

    b = a;
    EXPECT_TRUE(a == b);
    a.insert(Key("greg lake"), Value(52, 80));
    EXPECT_FALSE(a == b);
}

TEST(operator, unequal) {
    HashTable a, b;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));

    b = a;
    EXPECT_FALSE(a != b);
    a.insert(Key("greg lake"), Value(52, 80));
    EXPECT_TRUE(a != b);
}

TEST(operator, at) {
    HashTable a, b;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));

    try {
        a.at(Key("petr hohlin"));
    } catch (std::invalid_argument const &error) {
        EXPECT_EQ(error.what(), std::string("Key was not found."));
    }

    Value val = a.at(Key("paul"));
    EXPECT_TRUE(val.age == 14 && val.weight == 88);
    const Value c = a.at(Key("denis"));
    EXPECT_TRUE(c.age == 20 && c.weight == 87);

    const HashTable h = a;
    EXPECT_EQ(h.at("denis").weight, 87);
}

TEST(method, resize) {
    HashTable a;
    EXPECT_TRUE(a.empty());

    a.insert(Key("a"), Value(1, 1));
    a.insert(Key("b"), Value(2, 2));
    a.insert(Key("c"), Value(3, 3));
    a.insert(Key("d"), Value(4, 4));
    a.insert(Key("e"), Value(5, 5));
    a.insert(Key("f"), Value(6, 6));
    a.insert(Key("g"), Value(7, 7));
    a.insert(Key("h"), Value(8, 8));
    a.insert(Key("aa"), Value(1, 1));
    a.insert(Key("bb"), Value(2, 2));
    a.insert(Key("cc"), Value(3, 3));
    a.insert(Key("dd"), Value(4, 4));
    a.insert(Key("ee"), Value(5, 5));
    a.insert(Key("ff"), Value(6, 6));
    a.insert(Key("gg"), Value(7, 7));
    a.insert(Key("hh"), Value(8, 8));
    
    EXPECT_FALSE(a.empty());
}

TEST(constructor, move) {
    HashTable a;
    EXPECT_EQ(a.size(), 0);

    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    EXPECT_EQ(a.size(), 4);

    HashTable b = std::move(a);
    EXPECT_EQ(b.size(), 4);
    EXPECT_TRUE(b.contains("alex"));
    EXPECT_TRUE(b.contains("freeman"));
    EXPECT_TRUE(b.contains("denis"));
    EXPECT_TRUE(b.contains("paul"));
    EXPECT_EQ(a.size(), 0);
    EXPECT_TRUE(!a.contains("alex"));
    EXPECT_TRUE(!a.contains("freeman"));
    EXPECT_TRUE(!a.contains("denis"));
    EXPECT_TRUE(!a.contains("paul"));
}

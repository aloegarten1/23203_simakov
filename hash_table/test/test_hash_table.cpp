#include <gtest/gtest.h>
#include "../lib/hash_table.hpp"

struct Value {
    Value() : age(0), weight(0) {}
    Value(unsigned a, unsigned w) : age(a), weight(w) {}

    friend bool operator==(const Value& a, const Value& b);

    unsigned age;
    unsigned weight;
};

bool operator==(const Value& a, const Value& b) {
    return (a.age == b.age) && (a.weight == b.weight);
}

typedef std::string Key;

TEST(constructor, def) {
    HashTable<Key,Value> a;

    EXPECT_EQ(a.size(), 0);
}

TEST(method, insert) {
    HashTable<Key,Value> a;

    EXPECT_TRUE(a.empty());

    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    a.insert(Key("alex1"), Value(19, 67));
    a.insert(Key("freeman1"), Value(21, 52));
    a.insert(Key("denis1"), Value(20, 87));
    a.insert(Key("paul1"), Value(14, 88));
    a.insert(Key("goaaaal"), Value(12, 53));

    EXPECT_FALSE(a.empty());

    EXPECT_TRUE(a.contains(Key("alex")));
    EXPECT_TRUE(a.contains(Key("freeman")));
    EXPECT_TRUE(a.contains(Key("denis")));
    EXPECT_TRUE(a.contains(Key("paul")));
    EXPECT_TRUE(a.contains(Key("alex1")));
    EXPECT_TRUE(a.contains(Key("freeman1")));
    EXPECT_TRUE(a.contains(Key("denis1")));
    EXPECT_TRUE(a.contains(Key("paul1")));
    EXPECT_TRUE(a.contains(Key("goaaaal")));
    
    EXPECT_EQ(a.size(), 9);

    EXPECT_EQ(a.at(Key("alex")), Value(19, 67));
    EXPECT_EQ(a.at(Key("freeman")), Value(21, 52));
    EXPECT_EQ(a.at(Key("denis")), Value(20, 87));
    EXPECT_EQ(a.at(Key("paul")), Value(14, 88));
    EXPECT_EQ(a.at(Key("alex1")), Value(19, 67));
    EXPECT_EQ(a.at(Key("freeman1")), Value(21, 52));
    EXPECT_EQ(a.at(Key("denis1")), Value(20, 87));
    EXPECT_EQ(a.at(Key("paul1")), Value(14, 88));
    EXPECT_EQ(a.at(Key("goaaaal")), Value(12, 53));

    a.insert(Key("paul1"), Value(1, 2));
    EXPECT_EQ(a.at(Key("goaaaal")), Value(12, 53));
}

TEST(method, contains) {
    HashTable<Key,Value> a;
    EXPECT_FALSE(a.contains(Key("alex")));

    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    a.insert(Key("alex1"), Value(19, 67));
    a.insert(Key("freeman1"), Value(21, 52));
    a.insert(Key("denis1"), Value(20, 87));
    a.insert(Key("paul1"), Value(14, 88));
    a.insert(Key("goaaaal"), Value(12, 53));
    
    EXPECT_FALSE(a.empty());
    EXPECT_FALSE(a.contains(Key("andy morin")));

    EXPECT_TRUE(a.contains(Key("alex")));
    EXPECT_TRUE(a.contains(Key("freeman")));
    EXPECT_TRUE(a.contains(Key("denis")));
    EXPECT_TRUE(a.contains(Key("paul")));
    EXPECT_TRUE(a.contains(Key("alex1")));
    EXPECT_TRUE(a.contains(Key("freeman1")));
    EXPECT_TRUE(a.contains(Key("denis1")));
    EXPECT_TRUE(a.contains(Key("paul1")));
    EXPECT_TRUE(a.contains(Key("goaaaal")));
}

TEST(method, erase) {
    HashTable<Key,Value> a;
    EXPECT_FALSE(a.erase(Key("aloegarten.")));

    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    a.insert(Key("alex1"), Value(19, 67));
    a.insert(Key("freeman1"), Value(21, 52));
    a.insert(Key("denis1"), Value(20, 87));
    a.insert(Key("paul1"), Value(14, 88));
    a.insert(Key("goaaaal"), Value(12, 53));

    EXPECT_FALSE(a.erase(Key("ROOTMAN")));
    EXPECT_EQ(a.size(), 9);

    EXPECT_TRUE(a.erase(Key("alex")));
    EXPECT_TRUE(a.erase(Key("freeman")));
    EXPECT_TRUE(a.erase(Key("denis")));
    EXPECT_TRUE(a.erase(Key("paul")));
    EXPECT_TRUE(a.erase(Key("alex1")));
    EXPECT_TRUE(a.erase(Key("freeman1")));
    EXPECT_TRUE(a.erase(Key("denis1")));
    EXPECT_TRUE(a.erase(Key("paul1")));
    EXPECT_TRUE(a.erase(Key("goaaaal")));
    
    EXPECT_EQ(a.size(), 0);
    EXPECT_FALSE(a.contains(Key("alex")));
    EXPECT_FALSE(a.contains(Key("freeman")));
    EXPECT_FALSE(a.contains(Key("denis")));
    EXPECT_FALSE(a.contains(Key("paul")));
    EXPECT_FALSE(a.contains(Key("alex1")));
    EXPECT_FALSE(a.contains(Key("freeman1")));
    EXPECT_FALSE(a.contains(Key("denis1")));
    EXPECT_FALSE(a.contains(Key("paul1")));
    EXPECT_FALSE(a.contains(Key("goaaaal")));
}

TEST(constructor, copy_constructor) {
    HashTable<Key,Value> a;
    
    HashTable<Key,Value> b(a);
    EXPECT_EQ(b.size(), 0);

    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    a.insert(Key("alex1"), Value(19, 67));
    a.insert(Key("freeman1"), Value(21, 52));
    a.insert(Key("denis1"), Value(20, 87));
    a.insert(Key("paul1"), Value(14, 88));
    a.insert(Key("goaaaal"), Value(12, 53));

    HashTable<Key,Value> c(a);

    EXPECT_EQ(c.size(), 9);
    EXPECT_TRUE(c.contains(Key("alex")));
    EXPECT_TRUE(c.contains(Key("freeman")));
    EXPECT_TRUE(c.contains(Key("denis")));
    EXPECT_TRUE(c.contains(Key("paul")));
    EXPECT_TRUE(c.contains(Key("alex1")));
    EXPECT_TRUE(c.contains(Key("freeman1")));
    EXPECT_TRUE(c.contains(Key("denis1")));
    EXPECT_TRUE(c.contains(Key("paul1")));
    EXPECT_TRUE(c.contains(Key("goaaaal")));

    EXPECT_TRUE(a.erase(Key("alex")));
    EXPECT_TRUE(a.erase(Key("freeman")));
    EXPECT_TRUE(a.erase(Key("denis")));
    EXPECT_TRUE(a.erase(Key("paul")));
    EXPECT_TRUE(a.erase(Key("alex1")));
    EXPECT_TRUE(a.erase(Key("freeman1")));
    EXPECT_TRUE(a.erase(Key("denis1")));
    EXPECT_TRUE(a.erase(Key("paul1")));
    EXPECT_TRUE(a.erase(Key("goaaaal")));

    HashTable<Key,Value> d(a);
    EXPECT_EQ(d.size(), 0);
}

TEST(constructor, move) {
    HashTable<Key,Value> a;
    EXPECT_EQ(a.size(), 0);

    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    EXPECT_EQ(a.size(), 4);

    HashTable<Key,Value> b(std::move(a));
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

TEST(operator, assigment) {
    HashTable<Key,Value> a;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    
    HashTable<Key,Value> b = a;

    EXPECT_EQ(b.size(), 4);
    EXPECT_TRUE(b.contains(Key("alex")));
    EXPECT_TRUE(b.contains(Key("freeman")));
    EXPECT_TRUE(b.contains(Key("denis")));
    EXPECT_TRUE(b.contains(Key("paul")));

}

TEST(operator, move) {
    HashTable<Key,Value> a;
    EXPECT_EQ(a.size(), 0);

    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    EXPECT_EQ(a.size(), 4);

    HashTable<Key,Value> b = std::move(a);
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

TEST(method, empty) {
    HashTable<Key,Value> a;
    EXPECT_TRUE(a.empty());
    a.insert(Key("alex"), Value(19, 67));
    EXPECT_FALSE(a.empty());
}

TEST(method, size) {
    HashTable<Key,Value> a;
    EXPECT_EQ(a.size(), 0);
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));
    EXPECT_EQ(a.size(), 4);
}

TEST(operator, subscript) {
    HashTable<Key,Value> a;
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
    HashTable<Key,Value> a;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));

    HashTable<Key,Value> b;
    b.insert(Key("eh"), Value(13, 100));

    a.swap(b);
    EXPECT_EQ(b.size(), 4);
    EXPECT_EQ(a.size(), 1);

    EXPECT_TRUE(a.contains(Key("eh")));
    EXPECT_FALSE(a.contains(Key("alex")));
    EXPECT_FALSE(a.contains(Key("freeman")));
    EXPECT_FALSE(a.contains(Key("denis")));
    EXPECT_FALSE(a.contains(Key("paul")));
    
    EXPECT_FALSE(b.contains(Key("eh")));
    EXPECT_TRUE(b.contains(Key("alex")));
    EXPECT_TRUE(b.contains(Key("freeman")));
    EXPECT_TRUE(b.contains(Key("denis")));
    EXPECT_TRUE(b.contains(Key("paul")));
}

TEST(method, clear) {
    HashTable<Key,Value> a;
    a.insert(Key("alex"), Value(19, 67));
    a.insert(Key("freeman"), Value(21, 52));
    a.insert(Key("denis"), Value(20, 87));
    a.insert(Key("paul"), Value(14, 88));

    EXPECT_EQ(a.size(), 4);
    EXPECT_TRUE(a.contains(Key("alex")));
    EXPECT_TRUE(a.contains(Key("freeman")));
    EXPECT_TRUE(a.contains(Key("denis")));
    EXPECT_TRUE(a.contains(Key("paul")));
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_FALSE(a.contains(Key("alex")));
    EXPECT_FALSE(a.contains(Key("freeman")));
    EXPECT_FALSE(a.contains(Key("denis")));
    EXPECT_FALSE(a.contains(Key("paul")));
}

// TEST(operator, equal) {
//     HashTable<Key,Value> a, b;
//     a.insert(Key("alex"), Value(19, 67));
//     a.insert(Key("freeman"), Value(21, 52));
//     a.insert(Key("denis"), Value(20, 87));
//     a.insert(Key("paul"), Value(14, 88));

//     b = a;
//     EXPECT_TRUE(a == b);
//     a.insert(Key("greg lake"), Value(52, 80));
//     EXPECT_FALSE(a == b);
// }

// TEST(operator, unequal) {
//     HashTable<Key,Value> a, b;
//     a.insert(Key("alex"), Value(19, 67));
//     a.insert(Key("freeman"), Value(21, 52));
//     a.insert(Key("denis"), Value(20, 87));
//     a.insert(Key("paul"), Value(14, 88));

//     b = a;
//     EXPECT_FALSE(a != b);
//     a.insert(Key("greg lake"), Value(52, 80));
//     EXPECT_TRUE(a != b);
// }

TEST(operator, at) {
    HashTable<Key,Value> a, b;
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

    const HashTable<Key,Value> h = a;
    EXPECT_EQ(h.at("denis").weight, 87);
}

TEST(method, resize) {
    HashTable<Key,Value> a;
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

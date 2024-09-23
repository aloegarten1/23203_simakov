/**
 * This class defines a Hash Table interface.
 * 
 * Hash table is a data structure (container) that implements an associative array interface.
 */

#pragma once 

#include <memory>
#include <string>

namespace myHashTable {


/**
 * @todo (aloegarten1): create a template key and value
 */
typedef std::string Key;

struct Value {
    Value(unsigned a, unsigned w) : age(a), weight(w) {}

    unsigned age;
    unsigned weight;
};

class HashTable {

public:
    HashTable();
    ~HashTable();
    
    /**
     * Copy operator.
     */
    HashTable& operator=(const HashTable& b);

    /**
     * Move operator.
    */
    HashTable& operator=(HashTable&& b);

    /**
     * Clears container.
     */
    void clear();

    /**
     * Erases element from continer by key.
     * 
     * @return success of erasure:
     * true - element was erased successfully
     * false - element wasn't removed
     */
    bool erase(const Key& k);

    /**
     * Inserts element into container
     * 
     * @return success of insertation
     * true - element was inserted successfully
     * false - element wasn't inserted
     */
    bool insert(const Key& k, const Value& v);

    /**
     * @return is an element with key "k" in container
     */
    bool contains(const Key& k) const;

    /**
     * @return a value from container by key.
     * If value does not exist, intializes a default value,
     * inserts into container and returns a reference.
     */
    Value& operator[](const Key& k);

    /**
     * @return a value from container by key.
     * @throw exception if key ont exists.
     */
    Value& at(const Key& k);
    const Value& at(const Key& k) const;

    /**
     * @return number of elements in contatiner.
     */
    size_t size() const noexcept;

    /**
     * @return is container empty.
     */
    bool empty() const noexcept;

    /**
     * Compare operators.
     * Hash tables are equal if they contain same elements.
     */
    friend bool operator==(const HashTable& a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);

private:
    struct Node {
        Node(Key k, Value v) : key(std::move(k)), value(v) {}

        Key key;
        Value value;
        std::unique_ptr<Node> next;
    };

    static const size_t _INITIAL_CAPACITY = 8;
    static const size_t _HASH = 9;
    static const size_t _CAPACITY_EXPAND_COEFF = 2;
    static const size_t _SIZE_PART = 0.75;

    size_t _capacity;
    size_t _size;
    std::unique_ptr<std::unique_ptr<Node>[]> _storage;

    size_t _hash(const Key& k) const;

    bool _insertNode(const Key& k, const Value& v);

    void _resizeStorage();

}; // class HashTable
} // namespace myHashTable

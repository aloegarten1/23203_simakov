#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <memory>
#include <string>

template<class Key, class Value>
class HashTable {

public:

    /**
     * Initializes an empty hash table.
     */
    HashTable();
    
    /**
     * Initializes a copy of hash table from argument. 
     */ 
    HashTable(const HashTable& ht);
    
    /**
     * Moves a table from argument to a current table.
     */
    HashTable(HashTable&& ht) noexcept;
    
    /**
     * Erases all elements from hashtable,
     * then destructing it.
     */
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
     * Erases every single element from the table.
     */
    void clear();

    /**
     * Erases element from continer by key.
     * 
     * @return was erasure successful:
     * true - element was erased successfully
     * false - element wasn't removed, nothing was done
     */
    bool erase(const Key& k);

    /**
     * Inserts element into container
     * 
     * @return was insertation successful
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
     * @throw exception if key does not exist.
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
     * Swaps two tables.
     */
    void swap(HashTable &b);

    /**
     * @return true, if hash tables contain same objects, 
     * else - false
     */
    // friend bool operator==(const HashTable& a, const HashTable& b);

    // /**
    //  * @return true, if hash tables contain different objects, 
    //  * else - false
    //  */
    // friend bool operator!=(const HashTable& a, const HashTable& b);

private:

    /**
     * There node is a structure that represents a linked list 
     * (used as bucket).
     * 
     * User is not supposed to know about 
     * container implementation, so
     * node is a private structure of Hash table.
     */
    struct Node {
        Node() : key(std::string()), value(Value()) {}
        Node(Key k, Value v) : key(std::move(k)), value(v) {}

        Key key;
        Value value;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<std::unique_ptr<Node>[]> __storage;
    size_t __capacity = INITIAL_CAPACITY, __size = 0;

    size_t _hash(const Key& k) const;
    bool _insertNode(const Key& k, const Value& v);
    void _resizeStorage();
    void _copy(const HashTable &b);

}; // class HashTable

#include "../src/hash_table.cpp"

#endif

/**
 * shed my skin
 * leave it for the homeless to sleep in
 */

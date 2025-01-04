#include "../lib/hash_table.hpp"

#include <iostream>

namespace {
    static constexpr size_t INITIAL_CAPACITY = 2;
    static constexpr size_t HASH = 9;
    static constexpr size_t EXPAND_COEFF = 2;
    static constexpr float MAX_LOAD_FACTOR = 2;
}

template<class Key, class Value> HashTable<Key, Value>::HashTable() : 
    __storage(std::make_unique<std::unique_ptr<Node>[]>(INITIAL_CAPACITY)),
    __capacity(INITIAL_CAPACITY),
    __size(0) 
{ }

template<class Key, class Value> HashTable<Key, Value>::HashTable(const HashTable<Key,Value>& ht) :
    __storage(std::make_unique<std::unique_ptr<Node>[]>(ht.__capacity)),
    __capacity(ht.__capacity),
    __size(0)
{
    _copy(ht);
}

template<class Key, class Value> HashTable<Key, Value>::HashTable(HashTable<Key,Value>&& ht) noexcept:
    __storage(std::move(ht.__storage)),
    __capacity(ht.__capacity),
    __size(ht.__size)
{
    // Probably we can use a default constructor instead of this three lines.
    ht.__capacity = INITIAL_CAPACITY;
    ht.__size = 0;
    ht.__storage = std::make_unique<std::unique_ptr<Node>[]>(INITIAL_CAPACITY);
}

template<class Key, class Value> HashTable<Key, Value>::~HashTable() = default;

template<class Key, class Value> HashTable<Key, Value> & HashTable<Key, Value>::operator=(const HashTable<Key,Value> &b) {
    _copy(b);
    return *this;
}

template<class Key, class Value> HashTable<Key,Value>  &  HashTable<Key, Value>::operator=(HashTable<Key,Value>&& b) {
    __capacity = b.__capacity;
    __size = b.__size;
    __storage = std::move(b.__storage);

    b.__capacity = INITIAL_CAPACITY;
    b.__size = 0;
    b.__storage = std::make_unique<std::unique_ptr<Node>[]>(b.__capacity);

    return *this;
}

template<class Key, class Value> bool HashTable<Key, Value>::empty() const noexcept {
    return __size == 0;
}

template<class Key, class Value> std::size_t HashTable<Key, Value>::size() const noexcept {
    return __size;
}

template<class Key, class Value> bool HashTable<Key, Value>::insert(const Key& k, const Value& v) {
   //?????????????????????????//
    if ((double) __size >= MAX_LOAD_FACTOR * (double) __capacity - 1) {
        _resizeStorage();
    }

    return _insertNode(k, v);
}

template<class Key, class Value> void HashTable<Key, Value>::clear() {
    for (std::size_t i = 0; i < __capacity; i++) {
        if (__storage[i]) {
            while (__storage[i]) {
                //???????????????????????
                //???????????????????????
                //????????????????????????
                __storage[i] = std::move(__storage[i]->next);
                __size--;
            }
        }
    }
}

template<class Key, class Value> bool HashTable<Key, Value>::erase(const Key& k) {
    std::size_t hash = _hash(k);
    Node* curr = __storage[hash].get();
    if (!curr) { return false; }

    if (curr->key == k) {
        __storage[hash] = std::move(__storage[hash]->next);
        __size--;
        return true;
    }

    while (curr->next) {
        if (curr->key == k) {
            curr->next = std::move(curr->next->next);
            __size--;
            return true;
        }
    }

    return false;
}

template<class Key, class Value> bool HashTable<Key, Value>::contains(const Key &k) const {
    size_t hash = _hash(k);
    if (!__storage[hash]) {
        return false;
    }
    Node *curr = __storage[hash].get();
    while (curr) {
        if (curr->key == k) {
            return true;
        }
        curr = curr->next.get();
    }
    return false;
}

template<class Key, class Value> Value& HashTable<Key, Value>::at(const Key &k) {
    const size_t hash = _hash(k);
    Node *curr = __storage[hash].get();
    while (curr) {
        if (curr->key == k) {
            return curr->value;
        }
        curr = curr->next.get();
    }
    throw std::invalid_argument("Key was not found.");
}

template<class Key, class Value> const Value& HashTable<Key, Value>::at(const Key &k) const {
    return const_cast<HashTable *>(this)->at(k);
}

template<class Key, class Value> void HashTable<Key, Value>::swap(HashTable<Key,Value> &b) {
    std::swap(__capacity, b.__capacity);
    std::swap(__size, b.__size);
    std::swap(__storage, b.__storage);
}

template<class Key, class Value> Value& HashTable<Key, Value>::operator[](const Key& k) {
    const size_t hash = _hash(k);
    if (!__storage[hash]) {
        __storage[hash] = std::make_unique<Node>(k, Value());
        __size++;

        return __storage[hash]->value;
    }

    Node* curr = __storage[hash].get();
    while (curr) {
        if (curr->key == k) {
            return curr->value;
        }
        curr = curr->next.get();
    }
    __storage[hash]->next = std::make_unique<Node>(k, Value());
    __size++;
    
    return __storage[hash]->next->value;
}

// bool operator==(const HashTable<Key,Value> &a, const HashTable<Key,Value> &b) {
//     if (a.__capacity != b.__capacity || a.__size != b.__size ) {
//         return false;
//     }

//     for (std::size_t i = 0; i < a.__capacity; ++i) {
//         template<class Key, class Value> HashTable<Key, Value>::Node *curr_a = a.__storage[i].get();
//         template<class Key, class Value> HashTable<Key, Value>::Node *curr_b = b.__storage[i].get();
//         while (curr_a && curr_b) {
//             /**
//              * According to this silly equal checks,
//              * @todo: operators "==" and "!=" for value
//              */
//             bool isKeyEq = curr_a->key != curr_b->key;
//             bool isWeightEq = curr_a->value.weight != curr_b->value.weight;
//             bool isAgeEq = curr_a->value.age != curr_b->value.age;
            
//             if (isKeyEq || isWeightEq || isAgeEq) { return false; }
            
//             curr_a = curr_a->next.get();
//             curr_b = curr_b->next.get();
//         }
//     }

//     return true;
// }

// bool operator!=(const HashTable<Key,Value> &a, const HashTable<Key,Value> &b) {
//     return !(a == b);
// }

template<class Key, class Value> std::size_t HashTable<Key, Value>::_hash(const Key &key) const {
    size_t hash = 0;
    for (char i: key) {
        int x = (int) (i - 'a' + 1);
        hash = (hash * HASH + x) % __capacity;
    }
    
    return hash;
}

template<class Key, class Value> void HashTable<Key, Value>::_resizeStorage() {
   //???????????????
    std::unique_ptr<std::unique_ptr<HashTable<Key, Value>::Node>[]> oldStorage = std::move(__storage);
    __storage = std::make_unique<std::unique_ptr<Node>[]>(__capacity * 2);

    for (std::size_t i = 0; i < __capacity; ++i) {
        if (oldStorage[i]) {
            while (oldStorage[i]->next) {
                _insertNode(oldStorage[i]->next->key, oldStorage[i]->next->value);
                oldStorage[i] = std::move(oldStorage[i]->next);
            }
            _insertNode(oldStorage[i]->key, oldStorage[i]->value);
        }
        oldStorage[i].reset();
    }
    __capacity *= EXPAND_COEFF;
}

template<class Key, class Value> bool HashTable<Key, Value>::_insertNode(const Key &k, const Value &v) {
    const std::size_t hash = _hash(k);
    Node *curr = __storage[hash].get();

    while (curr) {
        if (curr->key == k) { return false; }
        if (!curr->next) {
            curr->next = std::make_unique<Node>(k, v);
            __size++;

            return true;
        }
        curr = curr->next.get();
    }

    __storage[hash] = std::make_unique<Node>(k, v);
    __size++;
    
    return true;
}

template<class Key, class Value> void HashTable<Key, Value>::_copy(const HashTable<Key,Value> &b) {
    __storage = std::make_unique<std::unique_ptr<Node>[]>(b.__capacity);
    __size = 0;
    __capacity = b.__capacity;
    for (std::size_t i = 0; i < __capacity; i++) {
        Node *curr = b.__storage[i].get();
        while (curr) {
            _insertNode(curr->key, curr->value);
            curr = curr->next.get();
        }
    }
}



/**
 * aloegarten..
 */

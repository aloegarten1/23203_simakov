#include "../lib/hash_table.h"

#include <iostream>

HashTable::HashTable() : 
    __storage(std::make_unique<std::unique_ptr<Node>[]>(INITIAL_CAPACITY)),
    __capacity(INITIAL_CAPACITY),
    __size(0) 
{ }

HashTable::HashTable(const HashTable& ht) :
    __storage(std::make_unique<std::unique_ptr<Node>[]>(ht.__capacity)),
    __capacity(ht.__capacity),
    __size(0)
{
    for (size_t i = 0; i < this->__capacity; ++i) {
        Node* curr = ht.__storage[i].get();
        while (curr) {
            _insertNode(curr->key, curr->value);
            curr = curr->next.get();
        }
    }
}

HashTable::HashTable(HashTable &&ht):
    __storage(std::move(ht.__storage)),
    __capacity(ht.__capacity),
    __size(ht.__size)
{
    // Probably we can use a default constructor instead of this three lines.
    ht.__capacity = INITIAL_CAPACITY;
    ht.__size = 0;
    ht.__storage = std::make_unique<std::unique_ptr<Node>[]>(ht.__capacity);
}

HashTable::~HashTable() {
    clear();
}

HashTable &HashTable::operator=(const HashTable &b) {
    _copy(b);
    return *this;
}

HashTable& HashTable::operator=(HashTable&& b) {
    this->__capacity = b.__capacity;
    this->__size = b.__size;
    this->__storage = std::move(b.__storage);

    b.__capacity = INITIAL_CAPACITY;
    b.__size = 0;
    b.__storage = std::make_unique<std::unique_ptr<Node>[]>(b.__capacity);

    return *this;
}

bool HashTable::empty() const noexcept {
    return this->__size == 0;
}

std::size_t HashTable::size() const noexcept {
    return this->__size;
}

bool HashTable::insert(const Key& k, const Value& v) {
    if ((double) this->__size >= MAX_LOAD_FACTOR * (double) this->__capacity - 1) {
        _resizeStorage();
    }

    return _insertNode(k, v);
}

void HashTable::clear() {
    for (std::size_t i = 0; i < this->__capacity; i++) {
        if (this->__storage[i]) {
            while (this->__storage[i]) {
                this->__storage[i] = std::move(this->__storage[i]->next);
                this->__size--;
            }
        }
    }
}

bool HashTable::erase(const Key& k) {
    std::size_t hash = _hash(k);
    Node* curr = this->__storage[hash].get();
    if (!curr) { return false; }

    if (curr->key == k) {
        this->__storage[hash] = std::move(this->__storage[hash]->next);
        this->__size--;
        return true;
    }

    while (curr->next) {
        if (curr->key == k) {
            curr->next = std::move(curr->next->next);
            this->__size--;
            return true;
        }
    }

    return false;
}

bool HashTable::contains(const Key &k) const {
    size_t hash = _hash(k);
    if (!this->__storage[hash]) {
        return false;
    }
    Node *curr = this->__storage[hash].get();
    while (curr) {
        if (curr->key == k) {
            return true;
        }
        curr = curr->next.get();
    }
    return false;
}


Value &HashTable::at(const Key &k) {
    const size_t hash = _hash(k);
    Node *curr = this->__storage[hash].get();
    while (curr) {
        if (curr->key == k) {
            return curr->value;
        }
        curr = curr->next.get();
    }
    throw std::invalid_argument("Key was not found.");
}

const Value &HashTable::at(const Key &k) const {
    return const_cast<HashTable *>(this)->at(k);
}

void HashTable::swap(HashTable &b) {
    std::swap(this->__capacity, b.__capacity);
    std::swap(this->__size, b.__size);
    std::swap(this->__storage, b.__storage);
}

Value& HashTable::operator[](const Key& k) {
    const size_t hash = _hash(k);
    if (!this->__storage[hash]) {
        this->__storage[hash] = std::make_unique<Node>(k, Value());
        this->__size++;

        return this->__storage[hash]->value;
    }

    Node* curr = this->__storage[hash].get();
    while (curr) {
        if (curr->key == k) {
            return curr->value;
        }
        curr = curr->next.get();
    }
    this->__storage[hash]->next = std::make_unique<Node>(k, Value());
    this->__size++;
    
    return this->__storage[hash]->next->value;
}

bool operator==(const HashTable &a, const HashTable &b) {
    if (a.__capacity != b.__capacity || a.__size != b.__size ) {
        return false;
    }

    for (std::size_t i = 0; i < a.__capacity; ++i) {
        HashTable::Node *curr_a = a.__storage[i].get();
        HashTable::Node *curr_b = b.__storage[i].get();
        while (curr_a && curr_b) {
            bool isKeyEq = curr_a->key != curr_b->key;
            /**
             * According to this silly equal checks,
             * @todo: operators "==" and "!=" for value
             */
            bool isWeightEq = curr_a->value.weight != curr_b->value.weight;
            bool isAgeEq = curr_a->value.age != curr_b->value.age;
            
            if (isKeyEq || isWeightEq || isAgeEq) { return false; }
            
            curr_a = curr_a->next.get();
            curr_b = curr_b->next.get();
        }
    }

    return true;
}

bool operator!=(const HashTable &a, const HashTable &b) {
    return !(a == b);
}

std::size_t HashTable::_hash(const Key &key) const {
    size_t hash = 0;
    for (char i: key) {
        int x = (int) (i - 'a' + 1);
        hash = (hash * HASH + x) % this->__capacity;
    }
    
    return hash;
}

void HashTable::_resizeStorage() {
    /**
     * I hope we can use "auto" instead of this long bullshit, 
     * but im not really sure..
     */
    std::unique_ptr<std::unique_ptr<HashTable::Node>[]> oldStorage = std::move(this->__storage);
    this->__storage = std::make_unique<std::unique_ptr<Node>[]>(this->__capacity * 2);

    for (std::size_t i = 0; i < this->__capacity; ++i) {
        if (oldStorage[i]) {
            while (oldStorage[i]->next) {
                _insertNode(oldStorage[i]->next->key, oldStorage[i]->next->value);
                oldStorage[i] = std::move(oldStorage[i]->next);
            }
            _insertNode(oldStorage[i]->key, oldStorage[i]->value);
        }
        oldStorage[i].reset();
    }
    this->__capacity *= EXPAND_COEFF;
}

bool HashTable::_insertNode(const Key &k, const Value &v) {
    const std::size_t hash = _hash(k);
    Node *curr = this->__storage[hash].get();

    while (curr) {
        if (curr->key == k) { return false; }
        if (!curr->next) {
            curr->next = std::make_unique<Node>(k, v);
            this->__size++;

            return true;
        }
        curr = curr->next.get();
    }

    this->__storage[hash] = std::make_unique<Node>(k, v);
    this->__size++;
    
    return true;
}

void HashTable::_copy(const HashTable &b) {
    this->__storage = std::make_unique<std::unique_ptr<Node>[]>(b.__capacity);
    this->__size = 0;
    this->__capacity = b.__capacity;
    for (std::size_t i = 0; i < this->__capacity; i++) {
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

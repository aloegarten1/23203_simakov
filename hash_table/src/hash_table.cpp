#include "lib/hash_table.h"

using namespace myHashTable;

HashTable::HashTable() {
    this->_storage = std::make_unique<std::unique_ptr<Node>[]>(_INITIAL_CAPACITY);
    this->_capacity = _INITIAL_CAPACITY;
    this->_size = 0;
}

HashTable::~HashTable() {
    this->clear();
}

size_t HashTable::_hash(const Key& k) const {
    size_t hash = 0;
    for (char i: k) {
        int x = (int) (i - 'a' + 1);
        hash = (hash * _HASH + x) % this->_capacity;
    }

    return hash;
}

size_t HashTable::size() const noexcept {
    return this->_size;
}

bool HashTable::empty() const noexcept {
    return this->_size == 0;
}

void HashTable::_resizeStorage() {
    auto legacyStorage = std::move(this->_storage);
    this->_storage = std::make_unique<std::unique_ptr<Node>[]>(this->_capacity * _CAPACITY_EXPAND_COEFF);

    for (std::size_t i = 0; i < this->_capacity; i++) {
        if (legacyStorage[i]) { // finally null (nullptr) is 0
            while (legacyStorage[i]->next) {
                _insertNode(legacyStorage[i]->next->key, legacyStorage[i]->next->value);
                legacyStorage[i] = std::move(legacyStorage[i]->next);
            }
        }
        legacyStorage[i].reset();
    }

    this->_capacity *= _CAPACITY_EXPAND_COEFF;
}

bool HashTable::_insertNode(const Key& k, const Value& v) {
    const size_t hash = _hash(k);
    Node* curr = this->_storage[hash].get();

    while (curr) {
        if (curr->key == k) { return false; }
        if (!curr->next) {
            curr->next = std::make_unique<Node>(k, v);
            this->_size++;
            return true;
        }
        curr = curr->next.get();
    }

    this->_storage[hash] = std::make_unique<Node>(k, v);
    this->_size++;

    return true;
}

bool HashTable::insert(const Key &k, const Value &v) {
    if ((double) this->_size >= _SIZE_PART * (double) this->_capacity - 1) {
        _resizeStorage();
    }
    return _insertNode(k, v);
}

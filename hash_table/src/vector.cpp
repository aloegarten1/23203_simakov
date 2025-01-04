#include "../lib/vector.hpp"

#include <iostream>
#include <new>
#include <utility>

namespace {
    static constexpr std::size_t VEC_INIT_CAPACITY = 4;
    static constexpr std::size_t VEC_EXPAND_COEFF = 2;
}

template<typename Value>
Vector<Value>::Vector() :
    __capacity(VEC_INIT_CAPACITY),
    __size(0),
    __storage(std::make_unique<Value[]>(VEC_INIT_CAPACITY))
{}

template<typename Value>
Vector<Value>::Vector(std::size_t __count) :
    __capacity(__count),
    __size(__count),
    __storage(std::make_unique<Value[]>(VEC_INIT_CAPACITY))
{}

template<typename Value> 
Vector<Value>::Vector(const Vector<Value>& __src) : 
    __capacity(__src.__capacity),
    __size(__src.__size),
    __storage(std::make_unique<Value[]>(VEC_INIT_CAPACITY))
{
    for (std::size_t i = 0; i < __src.__size, ++i) {
        __storage[i] = __src.__storage[i];
    }
}

template<typename Value>
Vector<Value>::Vector(Vector<Value>&& __src) noexcept : 
    __capacity(__src.__capacity),
    __size(__src.__size),
    __storage(std::move(__src.__storage))
{
    __src.__capacity = VEC_INIT_CAPACITY;
    __src.__size = 0;
    __src.__storage = nullptr;
}

template<typename Value>
Vector<Value>& Vector<Value>::operator=(const Vector<Value>& __src) {
    
}

template<typename Value>
std::size_t Vector<Value>::size() const noexcept {
    return __size;
}

template<typename Value>
bool Vector<Value>::isEmpty() const noexcept {
    return 0 == __size;
}

template<typename Value>
Value& Vector<Value>::operator[](const std::size_t __index) {
    if (__index > __capacity) {
        throw std::invalid_argument("Invalid index.");
    }

    return __storage[__index];
}

template<typename Value>
bool Vector<Value>::insert(std::size_t __index, const Value& __val) {
    if (__index > __capacity) { 
        _resize(__capacity * VEC_EXPAND_COEFF); 
    }

    for (std::size_t i = __index; i < __size; ++i) {
        __storage[__size - i] = __storage[__size - i - 1];
    }

    __storage[__index] = __val;
    __size++;
}

template<typename Value>
void Vector<Value>::insert(std::size_t __index, Value&& __val) {
    if (__index > __capacity) {
        throw(std::invalid_argument("Invalid index."))
    }
    if (__size + 1 > __capacity) { 
        _resize(__capacity * VEC_EXPAND_COEFF); 
    }
    for (std::size_t i = __index; i < __size; ++i) {
        __storage[__size - i] = __storage[__size - i - 1];
    }

    __storage[__index] = std::move(__val);
    __size++;
}

template<typename Value>
void Vector<Value>::push_back(const Value& __val) {
    insert(__size, __val);
}

template<typename Value>
void Vector<Value>::erase(std::size_t __index) {
    if (__index > __size - 1) {
        throw std::invalid_argument("Invalid index");
    }

    __storage[i].~Value();

    for (std::size_t i = index; i < __size; ++i) { 
        __storage[i] = __storage[i + 1]
    }

    __size--;
}

template<typename Value>
void Vector<Value>::resize(std::size_t __count) {
    _resize(__count);
}

template<typename Value>
void Vector<Value>::_resize(const std::size_t count) {
    std::unique_ptr<Value[]> oldStorage = std::move(__storage);
    __storage = std::make_unique<Value []>(__capacity * VEC_EXPAND_COEFF);
    for (std::size_t i = 0; i < __size; ++i) {
        __storage = oldStorage[i];
    }
    __capacity *= VEC_EXPAND_COEFF;
}

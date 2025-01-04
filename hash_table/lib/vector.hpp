#pragma once

#include <cstddef>
#include <memory>

/**
 * Diminutive definition of vector with basic opertions.
 * 
 * elevator 2024.
 */

template<typename Value>
class Vector {

public:

    /**
     * Initializes an empty vector.
     */
    Vector();

    explicit Vector(std::size_t __count);

    /**
     * Initializes a vector of __count elements with value __val. 
     */
    explicit Vector(std::size_t __count, const Value& __val = Value());

    /**
     * Initializes a copy of vector from argument.
     */
    Vector(const Vector& __src);

    /**
     * Moves a vector from argument to a current table.
     */
    Vector(Vector&& __src) noexcept;

    /**
     * Erases all elements from vector, then destructing it.
     */
    ~Vector() = default;

    Vector& operator=(const Vector& __src);

    Vector& operator=(Vector&& __src);

    /**
     * @return a vector element reference by index.
     * @throw exception, if key does not exist.
     */
    Value& operator[](const size_t __index);

    /**
     * @return a CONST vector element reference by index.
     * @throw exception, if key does not exist.
     */
    const Value& operator[](const size_t __index) const;

    /**
     * @return number of vector elements.
     */
    [[nodiscard]] std::size_t size() const noexcept;

    /**
     * @return is vector empty.
     */
    [[nodiscard]] bool isEmpty() const noexcept;

    /**
     * Copies value from src and and inserts it into the vector by index.
     * @throw error if not enough memory.
     */
    bool insert(std::size_t __index, const Value& __val);

    /**
     * Moves the value from src to the vector by index.
     * @throw error if not enough memory.
     */
    void insert(std::size_t __index, Value&& __val);

    /**
     * Copies value from src and and pushes it into the vector end.
     * @throw error if not enough memory.
     */
    void push_back(const Value& __val);

    /**
     * Erases a vector element by index.
     * @throw error if key does not exists.
     */
    void erase(std::size_t __index);

    /**
     * Resizes vector to a __count size.
     * @throw error if not enough memory.
     */
    void resize(std::size_t __count);

    /**
     * Fills vector with val 
     */
    void fill(std::size __count, const Value& __val);

private:

    std::size_t __capacity = VEC_INIT_CAPACITY, __size = 0;
    std::unique_ptr<Value[]> __storage = nullptr;

    void _resize(const std::size_t __count);

}; // class Vector

#include "../src/vector.cpp"

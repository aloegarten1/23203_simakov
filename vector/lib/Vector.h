#ifndef _VECTOR_H
#define _VECTOR_H

#include <cstdlib>

namespace myVector {

typedef int vectorT;

class Vector
{

public:
    Vector() noexcept;
    Vector(const Vector& v) noexcept;

    ~Vector() noexcept;

    const vectorT operator[](size_t right_operand) { return this->__storage[right_operand]; }
    Vector& operator=(const Vector& src) noexcept;

    const size_t getLength() noexcept { return this->__length; }
    void pushBack(const vectorT val);
    void popByIndex(const size_t index);


private:
    vectorT* __storage;
    size_t __capacity, __length;

    static const size_t __initialCapacity = 4;

}; // class Vector
}; // namespace myVector

#endif
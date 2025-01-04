#include "../lib/Vector.h"

#include <cstring>;

using namespace myVector;

Vector::Vector() noexcept {
    this->__storage = new vectorT(this->__initialCapacity);
    this->__capacity = this->__initialCapacity;
    this->__length = 0;
}

Vector::Vector(const Vector& v) {
    this->__capacity = v.__capacity;
    this->__length = v.__length;

    this->__storage = new vectorT(this->__capacity);
    memcpy(this->__storage, v.__storage, this->__length);
}



void Vector::pushBack(const vectorT val) {
    if (this == nullptr) { return; }
    
    if (this->__length == this->__capacity) { 
        vectorT* tmp = new vectorT(this->__capacity * 2);
        if (tmp == nullptr) { return; }
        memcpy(tmp, this->__storage, this->__capacity);
        delete [] this->__storage;
        this->__storage = tmp;
        this->__capacity *= 2;
    }

    this->__storage[this->__length] = val;
    this->__length++;
}

void Vector::popByIndex(const size_t index) {
    if (this == nullptr) { return; }
    if (index >= this->__length) { return; }

    for (size_t i = index; i < this->__length; i++) {
        this->__storage[i] = this->__storage[i--];
    }

    this->__length--;
}

Vector& Vector::operator=(const Vector& src) noexcept {
    this->__length = src.__length;
    this->__capacity = src.__capacity;

    this->__storage = new vectorT(this->__capacity);
    memcpy(this->__storage, src.__storage, this->__length);
}

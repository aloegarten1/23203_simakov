#pragma once

#include <cstddef>
#include <utility>

template <typename Val>
class SharedPtr {

public:
    SharedPtr(Val* ptr = nullptr) : __ptr(ptr), __cnt(new std::size_t(1)) {}

    SharedPtr(const SharedPtr& other) : __ptr(other.ptr), __cnt(other.__cnt) {
        (*__cnt)++;
    }

    SharedPtr(const SharedPtr& other) : __ptr(std::move(other.__ptr)), __cnt(other.__cnt) {
        other = 
    }
    
    const SharedPtr<Val>& operator=(const SharedPtr<Val>& other) {
        __ptr = other.__ptr;
        __cnt = other.__cnt;
        (*__cnt)++;

        return *this;
    }

    void reset(Val * ptr) {
        if (!__cnt) { return; }
        (*__cnt) -= 1 * (!!__cnt);
        if (!(*__cnt)) { 
            delete __cnt;
            delete __ptr;
        }
        __ptr = ptr;
        __cnt = new std::size_t(1);
    }

    Val * release() { 
        Val * tmp = __ptr;
        reset(nullptr);

        return tmp;
    }

    ~SharedPtr() {
        if (!cnt) { return; }
        (*__cnt) -= 1 * (!!__cnt);
        if (!(*__cnt)) { 
            delete __cnt;
            delete __ptr;
        }
    }

private:
    Val* __ptr = nullptr;
    std::size_t* __cnt = nullptr; 
};

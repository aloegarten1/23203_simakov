#include "stack.hpp"

frt::StackValue frt::Stack::top() const noexcept {
    if (depth_ <= 0) {
        return 0; 
    }

    return storage_[depth_ - 1];
}

void frt::Stack::push(const frt::StackValue val) {
    storage_.push_back(val);
    depth_++;
}

bool frt::Stack::pop() noexcept {
    if(0 == depth_) { return false; }
    storage_.pop_back();
    depth_--;

    return true;
}

bool frt::Stack::isEmpty() const noexcept {
    return !depth_;
}

std::size_t frt::Stack::depth() const noexcept {
    return depth_;
}

bool frt::Stack::swap() noexcept {
    if (depth_ < 2) { return false; }
    std::swap(storage_[depth_ - 1], storage_[depth_ - 2]);

    return true;
}

bool frt::Stack::rot() noexcept {
    if (depth_ < 3) { return false; }
    std::swap(storage_[depth_ - 3], storage_[depth_ - 1]);
    std::swap(storage_[depth_ - 2], storage_[depth_ - 1]);

    return true;
}

frt::StackValue frt::Stack::getSecondFromTop() const noexcept {
    if (depth_ < 2) { 
        return 0;
    }

    return storage_[depth_ - 2];
}

void frt::Stack::printStack(std::ostream& stream) noexcept {
    for (StackValue val : storage_) {
        stream << val << " ";
    }
    stream << std::endl;
}

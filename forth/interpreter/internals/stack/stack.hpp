#pragma once

#include "../hardcoded.hpp"

#include <cstddef>
#include <iostream>
#include <vector>

namespace frt {

class Stack {
public:
    Stack() = default;
    
    StackValue top() const noexcept ;

    void push(const StackValue val);
    
    bool pop() noexcept;

    /**
     * Swaps two last elements in stack.
     * @example: 0 1 2 3 -> 0 1 3 2
     */
    bool swap() noexcept; 

    /**
     * “Rotates” the top three elements of the stack. 
     * 
     * The third element from the top of the stack gets moved 
     * to the top of the stack, pushing the other two elements down.
     */
    bool rot() noexcept;

    void printStack(std::ostream& stream) noexcept;

    [[nodiscard]] bool isEmpty() const noexcept;
    [[nodiscard]] std::size_t depth() const noexcept;  

    [[nodiscard]] StackValue getSecondFromTop() const noexcept;

private:
    std::vector<StackValue> storage_;
    std::size_t depth_ = 0;

}; // class Stack

} // namespace frt

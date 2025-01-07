#pragma once

#include "../internals/executionContext.hpp"
#include "errors.hpp"
namespace frt {

class Token {
public:
    Token() = default;
    virtual ~Token() = default;

    /**
     * Executes token.
     * @returns true, if token was completely executed.
     * Else - false.
     * 
     * @param context: ExecutionContext that contains stack
     * to operate with.
     */
    virtual bool exec(ExecutionContext& context) = 0;
}; // class Token

} // namespace frt

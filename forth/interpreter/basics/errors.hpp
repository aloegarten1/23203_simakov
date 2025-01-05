#pragma once

#include <stdexcept>
#include <string>

class ForthError : public std::runtime_error {
public:
  explicit ForthError(const std::string &msg)
    : std::runtime_error(msg) {}
};

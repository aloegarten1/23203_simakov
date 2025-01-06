#pragma once

#include <cassert>
#include <iostream>
#include <map>
#include <memory>

namespace frt {

template<class Product, class Id, class Creator>
class CommandFactory {
public:
    static CommandFactory * getInstance() {
        static CommandFactory f;
        return &f;
    }

    [[nodiscard]] std::shared_ptr<Product> createCommandByName(const Id& name) const {
        auto it = creators_.find(name);
        if (it != creators_.end()) {
            return it->second();
        }
        throw std::invalid_argument("Invalid command name!");
    }

    bool regist3r(const Id& name, Creator creator) {
        if (creators_.contains(name)) { return false; }
        assert(creator);
        creators_[name] = creator;

        return true;
    }

    [[nodiscard]] bool isRegistered(const Id& name) const noexcept {
        return creators_.contains(name);
    }

private:
    CommandFactory() = default;
    std::map<Id, Creator> creators_;
}; // class CommandFactory
} // namespace frt

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 1, 2, 3 };

    v.insert(v.begin() + 4, 5);
    for (std::size_t i = 0; i < 5; ++i) { 
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    v.insert(v.begin() + 10, 5);
    for (std::size_t i = 0; i < 5; ++i) { 
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> b = {};

    for (std::size_t i = 0; i < b.size(); ++i) { 
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    b[0] = 1;
    b[1] = 2;

    for (std::size_t i = 0; i < b.size(); ++i) { 
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

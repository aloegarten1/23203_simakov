#include <iostream>

int main() {
    std::istream &i = std::cin; 
    
    while (true) {
        while (!i.bad() || !i.fail() || !i.eof()) {
            char c;
            i.get(c);
            std::cout << char(10) << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}

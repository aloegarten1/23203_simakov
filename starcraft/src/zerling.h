#include <iostream>

class Zerling {

public:
    virtual void move(int x, int y) {
        std::cout << "MOVE." << std::endl;
    }

    virtual void attack(int x) {
        std::cout << "ATTACK." << std::endl;
    }

};

#include "repl.hpp"

#include <fstream>

int main(int argc, char *argv[]) {
    if (argc > 1) 
    {
        std::ifstream input;
        try 
        {
            input = std::ifstream(argv[1], std::ios_base::in);
        }
        catch (...) 
        {
            throw "Failed to open a file.";
        }
        Repl r(input);
        r.run();

        return 0;
    }

    Repl r(std::cin);
    r.run();

    return 0;
}

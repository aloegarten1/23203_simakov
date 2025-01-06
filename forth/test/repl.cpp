#include "repl.hpp"

std::string repl(std::string input)
{
    std::ostringstream os;
    std::istringstream is(input);
    Repl repl = Repl(is, os);
    repl.run();
    return os.str();
}

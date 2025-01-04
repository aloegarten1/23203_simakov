cmake_minimum_required(VERSION 3.22)
project(forth_interpreter)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
        forth 
        io/repl.cpp io/repl.hpp
        interpreter/forth.cpp interpreter/forth.hpp

        interpreter/internals/executionContext.cpp
        interpreter/internals/executionContext.hpp
        
        interpreter/internals/stack/stack.cpp
        interpreter/internals/stack/stack.hpp

        interpreter/basics/token.hpp
        interpreter/basics/tokens.hpp
        interpreter/basics/valueToken.hpp

        interpreter/basics/expression.hpp
        interpreter/basics/expression.cpp

        interpreter/basics/commands/command.hpp
        interpreter/basics/commands/commands.cpp

        interpreter/basics/commands/command_factory.hpp
)

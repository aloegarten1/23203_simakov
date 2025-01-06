cmake_minimum_required(VERSION 3.22)
project(forth_interpreter)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_executable(
        forth 
        io/main.cpp
        io/repl.cpp
        interpreter/forth.cpp
        interpreter/internals/executionContext.cpp
        interpreter/internals/stack/stack.cpp
        interpreter/basics/expression.cpp
        interpreter/basics/commands/commands.cpp
        interpreter/basics/commands/math.cpp
        interpreter/basics/commands/logic.cpp
        )

 

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
  forth_test
  test/main_tests.cpp
  test/stack_test.cpp
  test/tokens_test.cpp
  test/execution_context_test.cpp
  test/expression_test.cpp
  test/repl.cpp
  test/FORTH_basic_test.cpp
  test/FORTH_math_test.cpp
  test/FORTH_logic_test.cpp
  test/FORTH_control_test.cpp
  interpreter/internals/stack/stack.cpp
  interpreter/internals/stack/stack.hpp
  interpreter/forth.cpp
  interpreter/internals/executionContext.hpp
  interpreter/basics/expression.cpp
  interpreter/basics/commands/commands.cpp
  interpreter/basics/commands/math.cpp
  interpreter/basics/commands/logic.cpp
  io/repl.cpp
)

target_link_libraries(
  forth_test GTest::gtest_main  
)

include(GoogleTest)
gtest_discover_tests(forth_test)
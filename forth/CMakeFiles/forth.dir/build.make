# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stepan/projects/cpp/23203_simakov/forth

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stepan/projects/cpp/23203_simakov/forth

# Include any dependencies generated for this target.
include CMakeFiles/forth.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/forth.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/forth.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/forth.dir/flags.make

CMakeFiles/forth.dir/io/repl.cpp.o: CMakeFiles/forth.dir/flags.make
CMakeFiles/forth.dir/io/repl.cpp.o: io/repl.cpp
CMakeFiles/forth.dir/io/repl.cpp.o: CMakeFiles/forth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stepan/projects/cpp/23203_simakov/forth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/forth.dir/io/repl.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/forth.dir/io/repl.cpp.o -MF CMakeFiles/forth.dir/io/repl.cpp.o.d -o CMakeFiles/forth.dir/io/repl.cpp.o -c /home/stepan/projects/cpp/23203_simakov/forth/io/repl.cpp

CMakeFiles/forth.dir/io/repl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/forth.dir/io/repl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stepan/projects/cpp/23203_simakov/forth/io/repl.cpp > CMakeFiles/forth.dir/io/repl.cpp.i

CMakeFiles/forth.dir/io/repl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/forth.dir/io/repl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stepan/projects/cpp/23203_simakov/forth/io/repl.cpp -o CMakeFiles/forth.dir/io/repl.cpp.s

CMakeFiles/forth.dir/interpreter/forth.cpp.o: CMakeFiles/forth.dir/flags.make
CMakeFiles/forth.dir/interpreter/forth.cpp.o: interpreter/forth.cpp
CMakeFiles/forth.dir/interpreter/forth.cpp.o: CMakeFiles/forth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stepan/projects/cpp/23203_simakov/forth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/forth.dir/interpreter/forth.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/forth.dir/interpreter/forth.cpp.o -MF CMakeFiles/forth.dir/interpreter/forth.cpp.o.d -o CMakeFiles/forth.dir/interpreter/forth.cpp.o -c /home/stepan/projects/cpp/23203_simakov/forth/interpreter/forth.cpp

CMakeFiles/forth.dir/interpreter/forth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/forth.dir/interpreter/forth.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stepan/projects/cpp/23203_simakov/forth/interpreter/forth.cpp > CMakeFiles/forth.dir/interpreter/forth.cpp.i

CMakeFiles/forth.dir/interpreter/forth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/forth.dir/interpreter/forth.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stepan/projects/cpp/23203_simakov/forth/interpreter/forth.cpp -o CMakeFiles/forth.dir/interpreter/forth.cpp.s

CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.o: CMakeFiles/forth.dir/flags.make
CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.o: interpreter/internals/executionContext.cpp
CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.o: CMakeFiles/forth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stepan/projects/cpp/23203_simakov/forth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.o -MF CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.o.d -o CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.o -c /home/stepan/projects/cpp/23203_simakov/forth/interpreter/internals/executionContext.cpp

CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stepan/projects/cpp/23203_simakov/forth/interpreter/internals/executionContext.cpp > CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.i

CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stepan/projects/cpp/23203_simakov/forth/interpreter/internals/executionContext.cpp -o CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.s

CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.o: CMakeFiles/forth.dir/flags.make
CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.o: interpreter/internals/stack/stack.cpp
CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.o: CMakeFiles/forth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stepan/projects/cpp/23203_simakov/forth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.o -MF CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.o.d -o CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.o -c /home/stepan/projects/cpp/23203_simakov/forth/interpreter/internals/stack/stack.cpp

CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stepan/projects/cpp/23203_simakov/forth/interpreter/internals/stack/stack.cpp > CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.i

CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stepan/projects/cpp/23203_simakov/forth/interpreter/internals/stack/stack.cpp -o CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.s

CMakeFiles/forth.dir/interpreter/basics/expression.cpp.o: CMakeFiles/forth.dir/flags.make
CMakeFiles/forth.dir/interpreter/basics/expression.cpp.o: interpreter/basics/expression.cpp
CMakeFiles/forth.dir/interpreter/basics/expression.cpp.o: CMakeFiles/forth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stepan/projects/cpp/23203_simakov/forth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/forth.dir/interpreter/basics/expression.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/forth.dir/interpreter/basics/expression.cpp.o -MF CMakeFiles/forth.dir/interpreter/basics/expression.cpp.o.d -o CMakeFiles/forth.dir/interpreter/basics/expression.cpp.o -c /home/stepan/projects/cpp/23203_simakov/forth/interpreter/basics/expression.cpp

CMakeFiles/forth.dir/interpreter/basics/expression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/forth.dir/interpreter/basics/expression.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stepan/projects/cpp/23203_simakov/forth/interpreter/basics/expression.cpp > CMakeFiles/forth.dir/interpreter/basics/expression.cpp.i

CMakeFiles/forth.dir/interpreter/basics/expression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/forth.dir/interpreter/basics/expression.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stepan/projects/cpp/23203_simakov/forth/interpreter/basics/expression.cpp -o CMakeFiles/forth.dir/interpreter/basics/expression.cpp.s

CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.o: CMakeFiles/forth.dir/flags.make
CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.o: interpreter/basics/commands/commands.cpp
CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.o: CMakeFiles/forth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stepan/projects/cpp/23203_simakov/forth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.o -MF CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.o.d -o CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.o -c /home/stepan/projects/cpp/23203_simakov/forth/interpreter/basics/commands/commands.cpp

CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stepan/projects/cpp/23203_simakov/forth/interpreter/basics/commands/commands.cpp > CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.i

CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stepan/projects/cpp/23203_simakov/forth/interpreter/basics/commands/commands.cpp -o CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.s

# Object files for target forth
forth_OBJECTS = \
"CMakeFiles/forth.dir/io/repl.cpp.o" \
"CMakeFiles/forth.dir/interpreter/forth.cpp.o" \
"CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.o" \
"CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.o" \
"CMakeFiles/forth.dir/interpreter/basics/expression.cpp.o" \
"CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.o"

# External object files for target forth
forth_EXTERNAL_OBJECTS =

forth: CMakeFiles/forth.dir/io/repl.cpp.o
forth: CMakeFiles/forth.dir/interpreter/forth.cpp.o
forth: CMakeFiles/forth.dir/interpreter/internals/executionContext.cpp.o
forth: CMakeFiles/forth.dir/interpreter/internals/stack/stack.cpp.o
forth: CMakeFiles/forth.dir/interpreter/basics/expression.cpp.o
forth: CMakeFiles/forth.dir/interpreter/basics/commands/commands.cpp.o
forth: CMakeFiles/forth.dir/build.make
forth: CMakeFiles/forth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stepan/projects/cpp/23203_simakov/forth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable forth"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/forth.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/forth.dir/build: forth
.PHONY : CMakeFiles/forth.dir/build

CMakeFiles/forth.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/forth.dir/cmake_clean.cmake
.PHONY : CMakeFiles/forth.dir/clean

CMakeFiles/forth.dir/depend:
	cd /home/stepan/projects/cpp/23203_simakov/forth && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stepan/projects/cpp/23203_simakov/forth /home/stepan/projects/cpp/23203_simakov/forth /home/stepan/projects/cpp/23203_simakov/forth /home/stepan/projects/cpp/23203_simakov/forth /home/stepan/projects/cpp/23203_simakov/forth/CMakeFiles/forth.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/forth.dir/depend

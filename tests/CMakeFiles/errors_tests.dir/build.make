# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/konrad/Documents/GitHub/errors

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/konrad/Documents/GitHub/errors

# Include any dependencies generated for this target.
include tests/CMakeFiles/errors_tests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/errors_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/errors_tests.dir/flags.make

tests/CMakeFiles/errors_tests.dir/errors_test.cc.o: tests/CMakeFiles/errors_tests.dir/flags.make
tests/CMakeFiles/errors_tests.dir/errors_test.cc.o: tests/errors_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Documents/GitHub/errors/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/errors_tests.dir/errors_test.cc.o"
	cd /home/konrad/Documents/GitHub/errors/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/errors_tests.dir/errors_test.cc.o -c /home/konrad/Documents/GitHub/errors/tests/errors_test.cc

tests/CMakeFiles/errors_tests.dir/errors_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/errors_tests.dir/errors_test.cc.i"
	cd /home/konrad/Documents/GitHub/errors/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Documents/GitHub/errors/tests/errors_test.cc > CMakeFiles/errors_tests.dir/errors_test.cc.i

tests/CMakeFiles/errors_tests.dir/errors_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/errors_tests.dir/errors_test.cc.s"
	cd /home/konrad/Documents/GitHub/errors/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Documents/GitHub/errors/tests/errors_test.cc -o CMakeFiles/errors_tests.dir/errors_test.cc.s

# Object files for target errors_tests
errors_tests_OBJECTS = \
"CMakeFiles/errors_tests.dir/errors_test.cc.o"

# External object files for target errors_tests
errors_tests_EXTERNAL_OBJECTS =

bin/errors_tests: tests/CMakeFiles/errors_tests.dir/errors_test.cc.o
bin/errors_tests: tests/CMakeFiles/errors_tests.dir/build.make
bin/errors_tests: lib/libgtestd.a
bin/errors_tests: lib/libgtest_maind.a
bin/errors_tests: lib/libgtestd.a
bin/errors_tests: tests/CMakeFiles/errors_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/konrad/Documents/GitHub/errors/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/errors_tests"
	cd /home/konrad/Documents/GitHub/errors/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/errors_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/errors_tests.dir/build: bin/errors_tests

.PHONY : tests/CMakeFiles/errors_tests.dir/build

tests/CMakeFiles/errors_tests.dir/clean:
	cd /home/konrad/Documents/GitHub/errors/tests && $(CMAKE_COMMAND) -P CMakeFiles/errors_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/errors_tests.dir/clean

tests/CMakeFiles/errors_tests.dir/depend:
	cd /home/konrad/Documents/GitHub/errors && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/konrad/Documents/GitHub/errors /home/konrad/Documents/GitHub/errors/tests /home/konrad/Documents/GitHub/errors /home/konrad/Documents/GitHub/errors/tests /home/konrad/Documents/GitHub/errors/tests/CMakeFiles/errors_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/errors_tests.dir/depend

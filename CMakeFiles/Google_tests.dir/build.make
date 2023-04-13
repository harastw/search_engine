# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/sark/code/cxx/search_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sark/code/cxx/search_engine

# Include any dependencies generated for this target.
include CMakeFiles/Google_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Google_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Google_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Google_tests.dir/flags.make

CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.o: CMakeFiles/Google_tests.dir/flags.make
CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.o: Google_tests/InverterIndexTest.cpp
CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.o: CMakeFiles/Google_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sark/code/cxx/search_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.o -MF CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.o.d -o CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.o -c /home/sark/code/cxx/search_engine/Google_tests/InverterIndexTest.cpp

CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sark/code/cxx/search_engine/Google_tests/InverterIndexTest.cpp > CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.i

CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sark/code/cxx/search_engine/Google_tests/InverterIndexTest.cpp -o CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.s

CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.o: CMakeFiles/Google_tests.dir/flags.make
CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.o: Google_tests/SearchServerTest.cpp
CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.o: CMakeFiles/Google_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sark/code/cxx/search_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.o -MF CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.o.d -o CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.o -c /home/sark/code/cxx/search_engine/Google_tests/SearchServerTest.cpp

CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sark/code/cxx/search_engine/Google_tests/SearchServerTest.cpp > CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.i

CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sark/code/cxx/search_engine/Google_tests/SearchServerTest.cpp -o CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.s

CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.o: CMakeFiles/Google_tests.dir/flags.make
CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.o: src/InvertedIndex.cpp
CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.o: CMakeFiles/Google_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sark/code/cxx/search_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.o -MF CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.o.d -o CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.o -c /home/sark/code/cxx/search_engine/src/InvertedIndex.cpp

CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sark/code/cxx/search_engine/src/InvertedIndex.cpp > CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.i

CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sark/code/cxx/search_engine/src/InvertedIndex.cpp -o CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.s

CMakeFiles/Google_tests.dir/src/SearchServer.cpp.o: CMakeFiles/Google_tests.dir/flags.make
CMakeFiles/Google_tests.dir/src/SearchServer.cpp.o: src/SearchServer.cpp
CMakeFiles/Google_tests.dir/src/SearchServer.cpp.o: CMakeFiles/Google_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sark/code/cxx/search_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Google_tests.dir/src/SearchServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Google_tests.dir/src/SearchServer.cpp.o -MF CMakeFiles/Google_tests.dir/src/SearchServer.cpp.o.d -o CMakeFiles/Google_tests.dir/src/SearchServer.cpp.o -c /home/sark/code/cxx/search_engine/src/SearchServer.cpp

CMakeFiles/Google_tests.dir/src/SearchServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_tests.dir/src/SearchServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sark/code/cxx/search_engine/src/SearchServer.cpp > CMakeFiles/Google_tests.dir/src/SearchServer.cpp.i

CMakeFiles/Google_tests.dir/src/SearchServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_tests.dir/src/SearchServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sark/code/cxx/search_engine/src/SearchServer.cpp -o CMakeFiles/Google_tests.dir/src/SearchServer.cpp.s

# Object files for target Google_tests
Google_tests_OBJECTS = \
"CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.o" \
"CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.o" \
"CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.o" \
"CMakeFiles/Google_tests.dir/src/SearchServer.cpp.o"

# External object files for target Google_tests
Google_tests_EXTERNAL_OBJECTS =

bin/Google_tests: CMakeFiles/Google_tests.dir/Google_tests/InverterIndexTest.cpp.o
bin/Google_tests: CMakeFiles/Google_tests.dir/Google_tests/SearchServerTest.cpp.o
bin/Google_tests: CMakeFiles/Google_tests.dir/src/InvertedIndex.cpp.o
bin/Google_tests: CMakeFiles/Google_tests.dir/src/SearchServer.cpp.o
bin/Google_tests: CMakeFiles/Google_tests.dir/build.make
bin/Google_tests: lib/libgtest.a
bin/Google_tests: lib/libgtest_main.a
bin/Google_tests: lib/libgtest.a
bin/Google_tests: CMakeFiles/Google_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sark/code/cxx/search_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bin/Google_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Google_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Google_tests.dir/build: bin/Google_tests
.PHONY : CMakeFiles/Google_tests.dir/build

CMakeFiles/Google_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Google_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Google_tests.dir/clean

CMakeFiles/Google_tests.dir/depend:
	cd /home/sark/code/cxx/search_engine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sark/code/cxx/search_engine /home/sark/code/cxx/search_engine /home/sark/code/cxx/search_engine /home/sark/code/cxx/search_engine /home/sark/code/cxx/search_engine/CMakeFiles/Google_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Google_tests.dir/depend


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
CMAKE_SOURCE_DIR = /home/dersa/npl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dersa/npl/build

# Include any dependencies generated for this target.
include CMakeFiles/sniff.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sniff.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sniff.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sniff.dir/flags.make

CMakeFiles/sniff.dir/src/sniff.cpp.o: CMakeFiles/sniff.dir/flags.make
CMakeFiles/sniff.dir/src/sniff.cpp.o: ../src/sniff.cpp
CMakeFiles/sniff.dir/src/sniff.cpp.o: CMakeFiles/sniff.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dersa/npl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sniff.dir/src/sniff.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sniff.dir/src/sniff.cpp.o -MF CMakeFiles/sniff.dir/src/sniff.cpp.o.d -o CMakeFiles/sniff.dir/src/sniff.cpp.o -c /home/dersa/npl/src/sniff.cpp

CMakeFiles/sniff.dir/src/sniff.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sniff.dir/src/sniff.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dersa/npl/src/sniff.cpp > CMakeFiles/sniff.dir/src/sniff.cpp.i

CMakeFiles/sniff.dir/src/sniff.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sniff.dir/src/sniff.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dersa/npl/src/sniff.cpp -o CMakeFiles/sniff.dir/src/sniff.cpp.s

# Object files for target sniff
sniff_OBJECTS = \
"CMakeFiles/sniff.dir/src/sniff.cpp.o"

# External object files for target sniff
sniff_EXTERNAL_OBJECTS =

sniff: CMakeFiles/sniff.dir/src/sniff.cpp.o
sniff: CMakeFiles/sniff.dir/build.make
sniff: CMakeFiles/sniff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dersa/npl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sniff"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sniff.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sniff.dir/build: sniff
.PHONY : CMakeFiles/sniff.dir/build

CMakeFiles/sniff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sniff.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sniff.dir/clean

CMakeFiles/sniff.dir/depend:
	cd /home/dersa/npl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dersa/npl /home/dersa/npl /home/dersa/npl/build /home/dersa/npl/build /home/dersa/npl/build/CMakeFiles/sniff.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sniff.dir/depend

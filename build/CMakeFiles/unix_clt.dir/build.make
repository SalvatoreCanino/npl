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
include CMakeFiles/unix_clt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/unix_clt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/unix_clt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unix_clt.dir/flags.make

CMakeFiles/unix_clt.dir/src/unix_clt.cpp.o: CMakeFiles/unix_clt.dir/flags.make
CMakeFiles/unix_clt.dir/src/unix_clt.cpp.o: ../src/unix_clt.cpp
CMakeFiles/unix_clt.dir/src/unix_clt.cpp.o: CMakeFiles/unix_clt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dersa/npl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unix_clt.dir/src/unix_clt.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unix_clt.dir/src/unix_clt.cpp.o -MF CMakeFiles/unix_clt.dir/src/unix_clt.cpp.o.d -o CMakeFiles/unix_clt.dir/src/unix_clt.cpp.o -c /home/dersa/npl/src/unix_clt.cpp

CMakeFiles/unix_clt.dir/src/unix_clt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unix_clt.dir/src/unix_clt.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dersa/npl/src/unix_clt.cpp > CMakeFiles/unix_clt.dir/src/unix_clt.cpp.i

CMakeFiles/unix_clt.dir/src/unix_clt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unix_clt.dir/src/unix_clt.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dersa/npl/src/unix_clt.cpp -o CMakeFiles/unix_clt.dir/src/unix_clt.cpp.s

# Object files for target unix_clt
unix_clt_OBJECTS = \
"CMakeFiles/unix_clt.dir/src/unix_clt.cpp.o"

# External object files for target unix_clt
unix_clt_EXTERNAL_OBJECTS =

unix_clt: CMakeFiles/unix_clt.dir/src/unix_clt.cpp.o
unix_clt: CMakeFiles/unix_clt.dir/build.make
unix_clt: CMakeFiles/unix_clt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dersa/npl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unix_clt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unix_clt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unix_clt.dir/build: unix_clt
.PHONY : CMakeFiles/unix_clt.dir/build

CMakeFiles/unix_clt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unix_clt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unix_clt.dir/clean

CMakeFiles/unix_clt.dir/depend:
	cd /home/dersa/npl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dersa/npl /home/dersa/npl /home/dersa/npl/build /home/dersa/npl/build /home/dersa/npl/build/CMakeFiles/unix_clt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unix_clt.dir/depend


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
include CMakeFiles/unix_srv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/unix_srv.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/unix_srv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unix_srv.dir/flags.make

CMakeFiles/unix_srv.dir/src/unix_srv.cpp.o: CMakeFiles/unix_srv.dir/flags.make
CMakeFiles/unix_srv.dir/src/unix_srv.cpp.o: ../src/unix_srv.cpp
CMakeFiles/unix_srv.dir/src/unix_srv.cpp.o: CMakeFiles/unix_srv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dersa/npl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unix_srv.dir/src/unix_srv.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unix_srv.dir/src/unix_srv.cpp.o -MF CMakeFiles/unix_srv.dir/src/unix_srv.cpp.o.d -o CMakeFiles/unix_srv.dir/src/unix_srv.cpp.o -c /home/dersa/npl/src/unix_srv.cpp

CMakeFiles/unix_srv.dir/src/unix_srv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unix_srv.dir/src/unix_srv.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dersa/npl/src/unix_srv.cpp > CMakeFiles/unix_srv.dir/src/unix_srv.cpp.i

CMakeFiles/unix_srv.dir/src/unix_srv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unix_srv.dir/src/unix_srv.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dersa/npl/src/unix_srv.cpp -o CMakeFiles/unix_srv.dir/src/unix_srv.cpp.s

# Object files for target unix_srv
unix_srv_OBJECTS = \
"CMakeFiles/unix_srv.dir/src/unix_srv.cpp.o"

# External object files for target unix_srv
unix_srv_EXTERNAL_OBJECTS =

unix_srv: CMakeFiles/unix_srv.dir/src/unix_srv.cpp.o
unix_srv: CMakeFiles/unix_srv.dir/build.make
unix_srv: CMakeFiles/unix_srv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dersa/npl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unix_srv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unix_srv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unix_srv.dir/build: unix_srv
.PHONY : CMakeFiles/unix_srv.dir/build

CMakeFiles/unix_srv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unix_srv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unix_srv.dir/clean

CMakeFiles/unix_srv.dir/depend:
	cd /home/dersa/npl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dersa/npl /home/dersa/npl /home/dersa/npl/build /home/dersa/npl/build /home/dersa/npl/build/CMakeFiles/unix_srv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unix_srv.dir/depend


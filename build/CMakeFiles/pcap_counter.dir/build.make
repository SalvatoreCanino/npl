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
include CMakeFiles/pcap_counter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pcap_counter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pcap_counter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pcap_counter.dir/flags.make

CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.o: CMakeFiles/pcap_counter.dir/flags.make
CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.o: ../src/pcap_counter.cpp
CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.o: CMakeFiles/pcap_counter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dersa/npl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.o -MF CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.o.d -o CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.o -c /home/dersa/npl/src/pcap_counter.cpp

CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dersa/npl/src/pcap_counter.cpp > CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.i

CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dersa/npl/src/pcap_counter.cpp -o CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.s

# Object files for target pcap_counter
pcap_counter_OBJECTS = \
"CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.o"

# External object files for target pcap_counter
pcap_counter_EXTERNAL_OBJECTS =

pcap_counter: CMakeFiles/pcap_counter.dir/src/pcap_counter.cpp.o
pcap_counter: CMakeFiles/pcap_counter.dir/build.make
pcap_counter: CMakeFiles/pcap_counter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dersa/npl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pcap_counter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pcap_counter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pcap_counter.dir/build: pcap_counter
.PHONY : CMakeFiles/pcap_counter.dir/build

CMakeFiles/pcap_counter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pcap_counter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pcap_counter.dir/clean

CMakeFiles/pcap_counter.dir/depend:
	cd /home/dersa/npl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dersa/npl /home/dersa/npl /home/dersa/npl/build /home/dersa/npl/build /home/dersa/npl/build/CMakeFiles/pcap_counter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pcap_counter.dir/depend

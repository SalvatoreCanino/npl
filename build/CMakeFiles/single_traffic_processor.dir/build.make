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
include CMakeFiles/single_traffic_processor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/single_traffic_processor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/single_traffic_processor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/single_traffic_processor.dir/flags.make

CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.o: CMakeFiles/single_traffic_processor.dir/flags.make
CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.o: ../esami/18-11-22/single_traffic_processor.cpp
CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.o: CMakeFiles/single_traffic_processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dersa/npl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.o -MF CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.o.d -o CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.o -c /home/dersa/npl/esami/18-11-22/single_traffic_processor.cpp

CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dersa/npl/esami/18-11-22/single_traffic_processor.cpp > CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.i

CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dersa/npl/esami/18-11-22/single_traffic_processor.cpp -o CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.s

# Object files for target single_traffic_processor
single_traffic_processor_OBJECTS = \
"CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.o"

# External object files for target single_traffic_processor
single_traffic_processor_EXTERNAL_OBJECTS =

single_traffic_processor: CMakeFiles/single_traffic_processor.dir/esami/18-11-22/single_traffic_processor.cpp.o
single_traffic_processor: CMakeFiles/single_traffic_processor.dir/build.make
single_traffic_processor: CMakeFiles/single_traffic_processor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dersa/npl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable single_traffic_processor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/single_traffic_processor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/single_traffic_processor.dir/build: single_traffic_processor
.PHONY : CMakeFiles/single_traffic_processor.dir/build

CMakeFiles/single_traffic_processor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/single_traffic_processor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/single_traffic_processor.dir/clean

CMakeFiles/single_traffic_processor.dir/depend:
	cd /home/dersa/npl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dersa/npl /home/dersa/npl /home/dersa/npl/build /home/dersa/npl/build /home/dersa/npl/build/CMakeFiles/single_traffic_processor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/single_traffic_processor.dir/depend


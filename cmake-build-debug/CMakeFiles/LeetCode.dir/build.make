# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/caffe/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/caffe/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/caffe/CLionProjects/LeetCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/caffe/CLionProjects/LeetCode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LeetCode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LeetCode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LeetCode.dir/flags.make

CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.o: CMakeFiles/LeetCode.dir/flags.make
CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.o: ../src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caffe/CLionProjects/LeetCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.o -c /home/caffe/CLionProjects/LeetCode/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp

CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caffe/CLionProjects/LeetCode/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp > CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.i

CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caffe/CLionProjects/LeetCode/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp -o CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.s

# Object files for target LeetCode
LeetCode_OBJECTS = \
"CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.o"

# External object files for target LeetCode
LeetCode_EXTERNAL_OBJECTS =

LeetCode: CMakeFiles/LeetCode.dir/src/80_Remove_Duplicates_from_Sorted_Array_II/solution1.cpp.o
LeetCode: CMakeFiles/LeetCode.dir/build.make
LeetCode: CMakeFiles/LeetCode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caffe/CLionProjects/LeetCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LeetCode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LeetCode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LeetCode.dir/build: LeetCode

.PHONY : CMakeFiles/LeetCode.dir/build

CMakeFiles/LeetCode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LeetCode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LeetCode.dir/clean

CMakeFiles/LeetCode.dir/depend:
	cd /home/caffe/CLionProjects/LeetCode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caffe/CLionProjects/LeetCode /home/caffe/CLionProjects/LeetCode /home/caffe/CLionProjects/LeetCode/cmake-build-debug /home/caffe/CLionProjects/LeetCode/cmake-build-debug /home/caffe/CLionProjects/LeetCode/cmake-build-debug/CMakeFiles/LeetCode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LeetCode.dir/depend


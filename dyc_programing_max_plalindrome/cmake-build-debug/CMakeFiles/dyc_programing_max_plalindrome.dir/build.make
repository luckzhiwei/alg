# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhiwei/alg/dyc_programing_max_plalindrome

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhiwei/alg/dyc_programing_max_plalindrome/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dyc_programing_max_plalindrome.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dyc_programing_max_plalindrome.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dyc_programing_max_plalindrome.dir/flags.make

CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o: CMakeFiles/dyc_programing_max_plalindrome.dir/flags.make
CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiwei/alg/dyc_programing_max_plalindrome/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o -c /Users/zhiwei/alg/dyc_programing_max_plalindrome/main.cpp

CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiwei/alg/dyc_programing_max_plalindrome/main.cpp > CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.i

CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiwei/alg/dyc_programing_max_plalindrome/main.cpp -o CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.s

CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o.requires

CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o.provides: CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/dyc_programing_max_plalindrome.dir/build.make CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o.provides

CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o.provides.build: CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o


# Object files for target dyc_programing_max_plalindrome
dyc_programing_max_plalindrome_OBJECTS = \
"CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o"

# External object files for target dyc_programing_max_plalindrome
dyc_programing_max_plalindrome_EXTERNAL_OBJECTS =

dyc_programing_max_plalindrome: CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o
dyc_programing_max_plalindrome: CMakeFiles/dyc_programing_max_plalindrome.dir/build.make
dyc_programing_max_plalindrome: CMakeFiles/dyc_programing_max_plalindrome.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhiwei/alg/dyc_programing_max_plalindrome/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dyc_programing_max_plalindrome"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dyc_programing_max_plalindrome.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dyc_programing_max_plalindrome.dir/build: dyc_programing_max_plalindrome

.PHONY : CMakeFiles/dyc_programing_max_plalindrome.dir/build

CMakeFiles/dyc_programing_max_plalindrome.dir/requires: CMakeFiles/dyc_programing_max_plalindrome.dir/main.cpp.o.requires

.PHONY : CMakeFiles/dyc_programing_max_plalindrome.dir/requires

CMakeFiles/dyc_programing_max_plalindrome.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dyc_programing_max_plalindrome.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dyc_programing_max_plalindrome.dir/clean

CMakeFiles/dyc_programing_max_plalindrome.dir/depend:
	cd /Users/zhiwei/alg/dyc_programing_max_plalindrome/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhiwei/alg/dyc_programing_max_plalindrome /Users/zhiwei/alg/dyc_programing_max_plalindrome /Users/zhiwei/alg/dyc_programing_max_plalindrome/cmake-build-debug /Users/zhiwei/alg/dyc_programing_max_plalindrome/cmake-build-debug /Users/zhiwei/alg/dyc_programing_max_plalindrome/cmake-build-debug/CMakeFiles/dyc_programing_max_plalindrome.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dyc_programing_max_plalindrome.dir/depend


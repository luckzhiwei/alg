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
CMAKE_SOURCE_DIR = /Users/zhiwei/alg/meituan/zigesai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhiwei/alg/meituan/zigesai/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zigesai.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zigesai.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zigesai.dir/flags.make

CMakeFiles/zigesai.dir/main.cpp.o: CMakeFiles/zigesai.dir/flags.make
CMakeFiles/zigesai.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhiwei/alg/meituan/zigesai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zigesai.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zigesai.dir/main.cpp.o -c /Users/zhiwei/alg/meituan/zigesai/main.cpp

CMakeFiles/zigesai.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zigesai.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhiwei/alg/meituan/zigesai/main.cpp > CMakeFiles/zigesai.dir/main.cpp.i

CMakeFiles/zigesai.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zigesai.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhiwei/alg/meituan/zigesai/main.cpp -o CMakeFiles/zigesai.dir/main.cpp.s

CMakeFiles/zigesai.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/zigesai.dir/main.cpp.o.requires

CMakeFiles/zigesai.dir/main.cpp.o.provides: CMakeFiles/zigesai.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/zigesai.dir/build.make CMakeFiles/zigesai.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/zigesai.dir/main.cpp.o.provides

CMakeFiles/zigesai.dir/main.cpp.o.provides.build: CMakeFiles/zigesai.dir/main.cpp.o


# Object files for target zigesai
zigesai_OBJECTS = \
"CMakeFiles/zigesai.dir/main.cpp.o"

# External object files for target zigesai
zigesai_EXTERNAL_OBJECTS =

zigesai: CMakeFiles/zigesai.dir/main.cpp.o
zigesai: CMakeFiles/zigesai.dir/build.make
zigesai: CMakeFiles/zigesai.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhiwei/alg/meituan/zigesai/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zigesai"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zigesai.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zigesai.dir/build: zigesai

.PHONY : CMakeFiles/zigesai.dir/build

CMakeFiles/zigesai.dir/requires: CMakeFiles/zigesai.dir/main.cpp.o.requires

.PHONY : CMakeFiles/zigesai.dir/requires

CMakeFiles/zigesai.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zigesai.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zigesai.dir/clean

CMakeFiles/zigesai.dir/depend:
	cd /Users/zhiwei/alg/meituan/zigesai/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhiwei/alg/meituan/zigesai /Users/zhiwei/alg/meituan/zigesai /Users/zhiwei/alg/meituan/zigesai/cmake-build-debug /Users/zhiwei/alg/meituan/zigesai/cmake-build-debug /Users/zhiwei/alg/meituan/zigesai/cmake-build-debug/CMakeFiles/zigesai.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zigesai.dir/depend


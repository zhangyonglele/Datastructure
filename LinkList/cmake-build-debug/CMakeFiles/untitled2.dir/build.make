# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\c++\CLion 2018.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\c++\CLion 2018.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\untitled2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\untitled2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled2.dir/flags.make

CMakeFiles/untitled2.dir/main.cpp.obj: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\untitled2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled2.dir/main.cpp.obj"
	D:\c++\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\untitled2.dir\main.cpp.obj -c E:\untitled2\main.cpp

CMakeFiles/untitled2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/main.cpp.i"
	D:\c++\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\untitled2\main.cpp > CMakeFiles\untitled2.dir\main.cpp.i

CMakeFiles/untitled2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/main.cpp.s"
	D:\c++\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\untitled2\main.cpp -o CMakeFiles\untitled2.dir\main.cpp.s

CMakeFiles/untitled2.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/untitled2.dir/main.cpp.obj.requires

CMakeFiles/untitled2.dir/main.cpp.obj.provides: CMakeFiles/untitled2.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\untitled2.dir\build.make CMakeFiles/untitled2.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/untitled2.dir/main.cpp.obj.provides

CMakeFiles/untitled2.dir/main.cpp.obj.provides.build: CMakeFiles/untitled2.dir/main.cpp.obj


# Object files for target untitled2
untitled2_OBJECTS = \
"CMakeFiles/untitled2.dir/main.cpp.obj"

# External object files for target untitled2
untitled2_EXTERNAL_OBJECTS =

untitled2.exe: CMakeFiles/untitled2.dir/main.cpp.obj
untitled2.exe: CMakeFiles/untitled2.dir/build.make
untitled2.exe: CMakeFiles/untitled2.dir/linklibs.rsp
untitled2.exe: CMakeFiles/untitled2.dir/objects1.rsp
untitled2.exe: CMakeFiles/untitled2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\untitled2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable untitled2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled2.dir/build: untitled2.exe

.PHONY : CMakeFiles/untitled2.dir/build

CMakeFiles/untitled2.dir/requires: CMakeFiles/untitled2.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/untitled2.dir/requires

CMakeFiles/untitled2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled2.dir/clean

CMakeFiles/untitled2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\untitled2 E:\untitled2 E:\untitled2\cmake-build-debug E:\untitled2\cmake-build-debug E:\untitled2\cmake-build-debug\CMakeFiles\untitled2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled2.dir/depend


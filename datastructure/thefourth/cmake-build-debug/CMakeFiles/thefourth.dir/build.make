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
CMAKE_SOURCE_DIR = E:\datastructure\thefourth

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\datastructure\thefourth\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/thefourth.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/thefourth.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thefourth.dir/flags.make

CMakeFiles/thefourth.dir/main.cpp.obj: CMakeFiles/thefourth.dir/flags.make
CMakeFiles/thefourth.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\datastructure\thefourth\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thefourth.dir/main.cpp.obj"
	D:\c++\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\thefourth.dir\main.cpp.obj -c E:\datastructure\thefourth\main.cpp

CMakeFiles/thefourth.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thefourth.dir/main.cpp.i"
	D:\c++\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\datastructure\thefourth\main.cpp > CMakeFiles\thefourth.dir\main.cpp.i

CMakeFiles/thefourth.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thefourth.dir/main.cpp.s"
	D:\c++\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\datastructure\thefourth\main.cpp -o CMakeFiles\thefourth.dir\main.cpp.s

CMakeFiles/thefourth.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/thefourth.dir/main.cpp.obj.requires

CMakeFiles/thefourth.dir/main.cpp.obj.provides: CMakeFiles/thefourth.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\thefourth.dir\build.make CMakeFiles/thefourth.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/thefourth.dir/main.cpp.obj.provides

CMakeFiles/thefourth.dir/main.cpp.obj.provides.build: CMakeFiles/thefourth.dir/main.cpp.obj


# Object files for target thefourth
thefourth_OBJECTS = \
"CMakeFiles/thefourth.dir/main.cpp.obj"

# External object files for target thefourth
thefourth_EXTERNAL_OBJECTS =

thefourth.exe: CMakeFiles/thefourth.dir/main.cpp.obj
thefourth.exe: CMakeFiles/thefourth.dir/build.make
thefourth.exe: CMakeFiles/thefourth.dir/linklibs.rsp
thefourth.exe: CMakeFiles/thefourth.dir/objects1.rsp
thefourth.exe: CMakeFiles/thefourth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\datastructure\thefourth\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable thefourth.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\thefourth.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thefourth.dir/build: thefourth.exe

.PHONY : CMakeFiles/thefourth.dir/build

CMakeFiles/thefourth.dir/requires: CMakeFiles/thefourth.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/thefourth.dir/requires

CMakeFiles/thefourth.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\thefourth.dir\cmake_clean.cmake
.PHONY : CMakeFiles/thefourth.dir/clean

CMakeFiles/thefourth.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\datastructure\thefourth E:\datastructure\thefourth E:\datastructure\thefourth\cmake-build-debug E:\datastructure\thefourth\cmake-build-debug E:\datastructure\thefourth\cmake-build-debug\CMakeFiles\thefourth.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thefourth.dir/depend


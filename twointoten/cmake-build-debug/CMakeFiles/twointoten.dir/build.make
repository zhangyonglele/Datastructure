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
CMAKE_SOURCE_DIR = E:\twointoten

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\twointoten\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/twointoten.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/twointoten.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/twointoten.dir/flags.make

CMakeFiles/twointoten.dir/main.cpp.obj: CMakeFiles/twointoten.dir/flags.make
CMakeFiles/twointoten.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\twointoten\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/twointoten.dir/main.cpp.obj"
	D:\c++\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\twointoten.dir\main.cpp.obj -c E:\twointoten\main.cpp

CMakeFiles/twointoten.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/twointoten.dir/main.cpp.i"
	D:\c++\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\twointoten\main.cpp > CMakeFiles\twointoten.dir\main.cpp.i

CMakeFiles/twointoten.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/twointoten.dir/main.cpp.s"
	D:\c++\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\twointoten\main.cpp -o CMakeFiles\twointoten.dir\main.cpp.s

CMakeFiles/twointoten.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/twointoten.dir/main.cpp.obj.requires

CMakeFiles/twointoten.dir/main.cpp.obj.provides: CMakeFiles/twointoten.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\twointoten.dir\build.make CMakeFiles/twointoten.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/twointoten.dir/main.cpp.obj.provides

CMakeFiles/twointoten.dir/main.cpp.obj.provides.build: CMakeFiles/twointoten.dir/main.cpp.obj


# Object files for target twointoten
twointoten_OBJECTS = \
"CMakeFiles/twointoten.dir/main.cpp.obj"

# External object files for target twointoten
twointoten_EXTERNAL_OBJECTS =

twointoten.exe: CMakeFiles/twointoten.dir/main.cpp.obj
twointoten.exe: CMakeFiles/twointoten.dir/build.make
twointoten.exe: CMakeFiles/twointoten.dir/linklibs.rsp
twointoten.exe: CMakeFiles/twointoten.dir/objects1.rsp
twointoten.exe: CMakeFiles/twointoten.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\twointoten\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable twointoten.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\twointoten.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/twointoten.dir/build: twointoten.exe

.PHONY : CMakeFiles/twointoten.dir/build

CMakeFiles/twointoten.dir/requires: CMakeFiles/twointoten.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/twointoten.dir/requires

CMakeFiles/twointoten.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\twointoten.dir\cmake_clean.cmake
.PHONY : CMakeFiles/twointoten.dir/clean

CMakeFiles/twointoten.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\twointoten E:\twointoten E:\twointoten\cmake-build-debug E:\twointoten\cmake-build-debug E:\twointoten\cmake-build-debug\CMakeFiles\twointoten.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/twointoten.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Software\CLion 2021.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Software\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\cool stuff\Temp Code\My Stack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\cool stuff\Temp Code\My Stack\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/My_Stack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/My_Stack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/My_Stack.dir/flags.make

CMakeFiles/My_Stack.dir/mystack.c.obj: CMakeFiles/My_Stack.dir/flags.make
CMakeFiles/My_Stack.dir/mystack.c.obj: ../mystack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\cool stuff\Temp Code\My Stack\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/My_Stack.dir/mystack.c.obj"
	D:\Software\Mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\My_Stack.dir\mystack.c.obj -c "D:\cool stuff\Temp Code\My Stack\mystack.c"

CMakeFiles/My_Stack.dir/mystack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/My_Stack.dir/mystack.c.i"
	D:\Software\Mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\cool stuff\Temp Code\My Stack\mystack.c" > CMakeFiles\My_Stack.dir\mystack.c.i

CMakeFiles/My_Stack.dir/mystack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/My_Stack.dir/mystack.c.s"
	D:\Software\Mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\cool stuff\Temp Code\My Stack\mystack.c" -o CMakeFiles\My_Stack.dir\mystack.c.s

# Object files for target My_Stack
My_Stack_OBJECTS = \
"CMakeFiles/My_Stack.dir/mystack.c.obj"

# External object files for target My_Stack
My_Stack_EXTERNAL_OBJECTS =

My_Stack.exe: CMakeFiles/My_Stack.dir/mystack.c.obj
My_Stack.exe: CMakeFiles/My_Stack.dir/build.make
My_Stack.exe: CMakeFiles/My_Stack.dir/linklibs.rsp
My_Stack.exe: CMakeFiles/My_Stack.dir/objects1.rsp
My_Stack.exe: CMakeFiles/My_Stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\cool stuff\Temp Code\My Stack\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable My_Stack.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\My_Stack.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/My_Stack.dir/build: My_Stack.exe

.PHONY : CMakeFiles/My_Stack.dir/build

CMakeFiles/My_Stack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\My_Stack.dir\cmake_clean.cmake
.PHONY : CMakeFiles/My_Stack.dir/clean

CMakeFiles/My_Stack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\cool stuff\Temp Code\My Stack" "D:\cool stuff\Temp Code\My Stack" "D:\cool stuff\Temp Code\My Stack\cmake-build-debug" "D:\cool stuff\Temp Code\My Stack\cmake-build-debug" "D:\cool stuff\Temp Code\My Stack\cmake-build-debug\CMakeFiles\My_Stack.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/My_Stack.dir/depend

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
CMAKE_SOURCE_DIR = "D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Pointer_Varifier.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pointer_Varifier.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pointer_Varifier.dir/flags.make

CMakeFiles/Pointer_Varifier.dir/main.c.obj: CMakeFiles/Pointer_Varifier.dir/flags.make
CMakeFiles/Pointer_Varifier.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Pointer_Varifier.dir/main.c.obj"
	D:\Software\Mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Pointer_Varifier.dir\main.c.obj -c "D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier\main.c"

CMakeFiles/Pointer_Varifier.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Pointer_Varifier.dir/main.c.i"
	D:\Software\Mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier\main.c" > CMakeFiles\Pointer_Varifier.dir\main.c.i

CMakeFiles/Pointer_Varifier.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Pointer_Varifier.dir/main.c.s"
	D:\Software\Mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier\main.c" -o CMakeFiles\Pointer_Varifier.dir\main.c.s

# Object files for target Pointer_Varifier
Pointer_Varifier_OBJECTS = \
"CMakeFiles/Pointer_Varifier.dir/main.c.obj"

# External object files for target Pointer_Varifier
Pointer_Varifier_EXTERNAL_OBJECTS =

Pointer_Varifier.exe: CMakeFiles/Pointer_Varifier.dir/main.c.obj
Pointer_Varifier.exe: CMakeFiles/Pointer_Varifier.dir/build.make
Pointer_Varifier.exe: CMakeFiles/Pointer_Varifier.dir/linklibs.rsp
Pointer_Varifier.exe: CMakeFiles/Pointer_Varifier.dir/objects1.rsp
Pointer_Varifier.exe: CMakeFiles/Pointer_Varifier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Pointer_Varifier.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Pointer_Varifier.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pointer_Varifier.dir/build: Pointer_Varifier.exe

.PHONY : CMakeFiles/Pointer_Varifier.dir/build

CMakeFiles/Pointer_Varifier.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Pointer_Varifier.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Pointer_Varifier.dir/clean

CMakeFiles/Pointer_Varifier.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier" "D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier" "D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier\cmake-build-debug" "D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier\cmake-build-debug" "D:\cool stuff\Temp Code\CProgrammingLanguageExperiment\Exp 12\Pointer Varifier\cmake-build-debug\CMakeFiles\Pointer_Varifier.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Pointer_Varifier.dir/depend


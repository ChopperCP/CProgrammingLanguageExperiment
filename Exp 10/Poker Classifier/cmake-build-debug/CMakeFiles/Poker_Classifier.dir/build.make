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
CMAKE_SOURCE_DIR = "D:\cool stuff\Temp Code\Poker Classifier"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\cool stuff\Temp Code\Poker Classifier\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Poker_Classifier.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Poker_Classifier.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Poker_Classifier.dir/flags.make

CMakeFiles/Poker_Classifier.dir/main.c.obj: CMakeFiles/Poker_Classifier.dir/flags.make
CMakeFiles/Poker_Classifier.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\cool stuff\Temp Code\Poker Classifier\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Poker_Classifier.dir/main.c.obj"
	D:\Software\Mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Poker_Classifier.dir\main.c.obj -c "D:\cool stuff\Temp Code\Poker Classifier\main.c"

CMakeFiles/Poker_Classifier.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Poker_Classifier.dir/main.c.i"
	D:\Software\Mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\cool stuff\Temp Code\Poker Classifier\main.c" > CMakeFiles\Poker_Classifier.dir\main.c.i

CMakeFiles/Poker_Classifier.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Poker_Classifier.dir/main.c.s"
	D:\Software\Mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\cool stuff\Temp Code\Poker Classifier\main.c" -o CMakeFiles\Poker_Classifier.dir\main.c.s

# Object files for target Poker_Classifier
Poker_Classifier_OBJECTS = \
"CMakeFiles/Poker_Classifier.dir/main.c.obj"

# External object files for target Poker_Classifier
Poker_Classifier_EXTERNAL_OBJECTS =

Poker_Classifier.exe: CMakeFiles/Poker_Classifier.dir/main.c.obj
Poker_Classifier.exe: CMakeFiles/Poker_Classifier.dir/build.make
Poker_Classifier.exe: CMakeFiles/Poker_Classifier.dir/linklibs.rsp
Poker_Classifier.exe: CMakeFiles/Poker_Classifier.dir/objects1.rsp
Poker_Classifier.exe: CMakeFiles/Poker_Classifier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\cool stuff\Temp Code\Poker Classifier\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Poker_Classifier.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Poker_Classifier.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Poker_Classifier.dir/build: Poker_Classifier.exe

.PHONY : CMakeFiles/Poker_Classifier.dir/build

CMakeFiles/Poker_Classifier.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Poker_Classifier.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Poker_Classifier.dir/clean

CMakeFiles/Poker_Classifier.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\cool stuff\Temp Code\Poker Classifier" "D:\cool stuff\Temp Code\Poker Classifier" "D:\cool stuff\Temp Code\Poker Classifier\cmake-build-debug" "D:\cool stuff\Temp Code\Poker Classifier\cmake-build-debug" "D:\cool stuff\Temp Code\Poker Classifier\cmake-build-debug\CMakeFiles\Poker_Classifier.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Poker_Classifier.dir/depend


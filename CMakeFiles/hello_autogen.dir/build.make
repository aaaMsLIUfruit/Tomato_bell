# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ayako/桌面/fqz

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ayako/桌面/fqz

# Utility rule file for hello_autogen.

# Include the progress variables for this target.
include CMakeFiles/hello_autogen.dir/progress.make

CMakeFiles/hello_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ayako/桌面/fqz/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target hello"
	/usr/bin/cmake -E cmake_autogen /home/ayako/桌面/fqz/CMakeFiles/hello_autogen.dir/AutogenInfo.json ""

hello_autogen: CMakeFiles/hello_autogen
hello_autogen: CMakeFiles/hello_autogen.dir/build.make

.PHONY : hello_autogen

# Rule to build all files generated by this target.
CMakeFiles/hello_autogen.dir/build: hello_autogen

.PHONY : CMakeFiles/hello_autogen.dir/build

CMakeFiles/hello_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_autogen.dir/clean

CMakeFiles/hello_autogen.dir/depend:
	cd /home/ayako/桌面/fqz && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ayako/桌面/fqz /home/ayako/桌面/fqz /home/ayako/桌面/fqz /home/ayako/桌面/fqz /home/ayako/桌面/fqz/CMakeFiles/hello_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_autogen.dir/depend


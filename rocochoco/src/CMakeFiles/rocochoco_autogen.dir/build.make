# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco

# Utility rule file for rocochoco_autogen.

# Include the progress variables for this target.
include src/CMakeFiles/rocochoco_autogen.dir/progress.make

src/CMakeFiles/rocochoco_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target rocochoco"
	cd /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco/src && /usr/bin/cmake -E cmake_autogen /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco/src/CMakeFiles/rocochoco_autogen.dir ""

rocochoco_autogen: src/CMakeFiles/rocochoco_autogen
rocochoco_autogen: src/CMakeFiles/rocochoco_autogen.dir/build.make

.PHONY : rocochoco_autogen

# Rule to build all files generated by this target.
src/CMakeFiles/rocochoco_autogen.dir/build: rocochoco_autogen

.PHONY : src/CMakeFiles/rocochoco_autogen.dir/build

src/CMakeFiles/rocochoco_autogen.dir/clean:
	cd /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco/src && $(CMAKE_COMMAND) -P CMakeFiles/rocochoco_autogen.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/rocochoco_autogen.dir/clean

src/CMakeFiles/rocochoco_autogen.dir/depend:
	cd /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco/src /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco/src /home/alvaro/Escritorio/UNI/Clase/Robotica/Workspace/robocomp/components/Robotica/rocochoco/src/CMakeFiles/rocochoco_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/rocochoco_autogen.dir/depend


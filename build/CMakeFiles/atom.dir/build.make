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
CMAKE_SOURCE_DIR = /home/crisan007/Desktop/Tema_2_ok/Tema_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crisan007/Desktop/Tema_2_ok/Tema_2/build

# Include any dependencies generated for this target.
include CMakeFiles/atom.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/atom.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/atom.dir/flags.make

CMakeFiles/atom.dir/src/main.cpp.o: CMakeFiles/atom.dir/flags.make
CMakeFiles/atom.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crisan007/Desktop/Tema_2_ok/Tema_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/atom.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/atom.dir/src/main.cpp.o -c /home/crisan007/Desktop/Tema_2_ok/Tema_2/src/main.cpp

CMakeFiles/atom.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/atom.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crisan007/Desktop/Tema_2_ok/Tema_2/src/main.cpp > CMakeFiles/atom.dir/src/main.cpp.i

CMakeFiles/atom.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/atom.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crisan007/Desktop/Tema_2_ok/Tema_2/src/main.cpp -o CMakeFiles/atom.dir/src/main.cpp.s

# Object files for target atom
atom_OBJECTS = \
"CMakeFiles/atom.dir/src/main.cpp.o"

# External object files for target atom
atom_EXTERNAL_OBJECTS =

atom: CMakeFiles/atom.dir/src/main.cpp.o
atom: CMakeFiles/atom.dir/build.make
atom: src/libsrc.a
atom: src/Compound/libCompound.a
atom: src/Atom/libAtom.a
atom: CMakeFiles/atom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/crisan007/Desktop/Tema_2_ok/Tema_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable atom"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/atom.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/atom.dir/build: atom

.PHONY : CMakeFiles/atom.dir/build

CMakeFiles/atom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/atom.dir/cmake_clean.cmake
.PHONY : CMakeFiles/atom.dir/clean

CMakeFiles/atom.dir/depend:
	cd /home/crisan007/Desktop/Tema_2_ok/Tema_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crisan007/Desktop/Tema_2_ok/Tema_2 /home/crisan007/Desktop/Tema_2_ok/Tema_2 /home/crisan007/Desktop/Tema_2_ok/Tema_2/build /home/crisan007/Desktop/Tema_2_ok/Tema_2/build /home/crisan007/Desktop/Tema_2_ok/Tema_2/build/CMakeFiles/atom.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/atom.dir/depend


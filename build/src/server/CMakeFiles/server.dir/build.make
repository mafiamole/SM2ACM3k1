# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mafiamole/projects/SM2ACM3k1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mafiamole/projects/SM2ACM3k1/build

# Include any dependencies generated for this target.
include src/server/CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include src/server/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include src/server/CMakeFiles/server.dir/flags.make

src/server/CMakeFiles/server.dir/Game.cpp.o: src/server/CMakeFiles/server.dir/flags.make
src/server/CMakeFiles/server.dir/Game.cpp.o: ../src/server/Game.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/server/CMakeFiles/server.dir/Game.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/Game.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/server/Game.cpp

src/server/CMakeFiles/server.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/Game.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/server/Game.cpp > CMakeFiles/server.dir/Game.cpp.i

src/server/CMakeFiles/server.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/Game.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/server/Game.cpp -o CMakeFiles/server.dir/Game.cpp.s

src/server/CMakeFiles/server.dir/Game.cpp.o.requires:
.PHONY : src/server/CMakeFiles/server.dir/Game.cpp.o.requires

src/server/CMakeFiles/server.dir/Game.cpp.o.provides: src/server/CMakeFiles/server.dir/Game.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/server.dir/build.make src/server/CMakeFiles/server.dir/Game.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/server.dir/Game.cpp.o.provides

src/server/CMakeFiles/server.dir/Game.cpp.o.provides.build: src/server/CMakeFiles/server.dir/Game.cpp.o

src/server/CMakeFiles/server.dir/Main.cpp.o: src/server/CMakeFiles/server.dir/flags.make
src/server/CMakeFiles/server.dir/Main.cpp.o: ../src/server/Main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/server/CMakeFiles/server.dir/Main.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/server.dir/Main.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/server/Main.cpp

src/server/CMakeFiles/server.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/Main.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/server/Main.cpp > CMakeFiles/server.dir/Main.cpp.i

src/server/CMakeFiles/server.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/Main.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/server/Main.cpp -o CMakeFiles/server.dir/Main.cpp.s

src/server/CMakeFiles/server.dir/Main.cpp.o.requires:
.PHONY : src/server/CMakeFiles/server.dir/Main.cpp.o.requires

src/server/CMakeFiles/server.dir/Main.cpp.o.provides: src/server/CMakeFiles/server.dir/Main.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/server.dir/build.make src/server/CMakeFiles/server.dir/Main.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/server.dir/Main.cpp.o.provides

src/server/CMakeFiles/server.dir/Main.cpp.o.provides.build: src/server/CMakeFiles/server.dir/Main.cpp.o

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/Game.cpp.o" \
"CMakeFiles/server.dir/Main.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

src/server/server: src/server/CMakeFiles/server.dir/Game.cpp.o
src/server/server: src/server/CMakeFiles/server.dir/Main.cpp.o
src/server/server: src/server/CMakeFiles/server.dir/build.make
src/server/server: /usr/local/lib/libMoleBox.so
src/server/server: /usr/local/lib64/libsfml-system.so
src/server/server: /usr/local/lib64/libsfml-window.so
src/server/server: /usr/local/lib64/libsfml-graphics.so
src/server/server: /usr/local/lib64/libsfml-audio.so
src/server/server: /usr/local/lib64/libsfml-network.so
src/server/server: src/server/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable server"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/server/CMakeFiles/server.dir/build: src/server/server
.PHONY : src/server/CMakeFiles/server.dir/build

src/server/CMakeFiles/server.dir/requires: src/server/CMakeFiles/server.dir/Game.cpp.o.requires
src/server/CMakeFiles/server.dir/requires: src/server/CMakeFiles/server.dir/Main.cpp.o.requires
.PHONY : src/server/CMakeFiles/server.dir/requires

src/server/CMakeFiles/server.dir/clean:
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/server && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : src/server/CMakeFiles/server.dir/clean

src/server/CMakeFiles/server.dir/depend:
	cd /home/mafiamole/projects/SM2ACM3k1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mafiamole/projects/SM2ACM3k1 /home/mafiamole/projects/SM2ACM3k1/src/server /home/mafiamole/projects/SM2ACM3k1/build /home/mafiamole/projects/SM2ACM3k1/build/src/server /home/mafiamole/projects/SM2ACM3k1/build/src/server/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/server/CMakeFiles/server.dir/depend


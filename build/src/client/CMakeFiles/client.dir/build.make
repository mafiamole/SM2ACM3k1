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
include src/client/CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include src/client/CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include src/client/CMakeFiles/client.dir/flags.make

src/client/CMakeFiles/client.dir/Game.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/Game.cpp.o: ../src/client/Game.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/Game.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/Game.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/Game.cpp

src/client/CMakeFiles/client.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/Game.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/Game.cpp > CMakeFiles/client.dir/Game.cpp.i

src/client/CMakeFiles/client.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/Game.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/Game.cpp -o CMakeFiles/client.dir/Game.cpp.s

src/client/CMakeFiles/client.dir/Game.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/Game.cpp.o.requires

src/client/CMakeFiles/client.dir/Game.cpp.o.provides: src/client/CMakeFiles/client.dir/Game.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/Game.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/Game.cpp.o.provides

src/client/CMakeFiles/client.dir/Game.cpp.o.provides.build: src/client/CMakeFiles/client.dir/Game.cpp.o

src/client/CMakeFiles/client.dir/Main.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/Main.cpp.o: ../src/client/Main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/Main.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/Main.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/Main.cpp

src/client/CMakeFiles/client.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/Main.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/Main.cpp > CMakeFiles/client.dir/Main.cpp.i

src/client/CMakeFiles/client.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/Main.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/Main.cpp -o CMakeFiles/client.dir/Main.cpp.s

src/client/CMakeFiles/client.dir/Main.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/Main.cpp.o.requires

src/client/CMakeFiles/client.dir/Main.cpp.o.provides: src/client/CMakeFiles/client.dir/Main.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/Main.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/Main.cpp.o.provides

src/client/CMakeFiles/client.dir/Main.cpp.o.provides.build: src/client/CMakeFiles/client.dir/Main.cpp.o

src/client/CMakeFiles/client.dir/Map.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/Map.cpp.o: ../src/client/Map.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/Map.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/Map.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/Map.cpp

src/client/CMakeFiles/client.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/Map.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/Map.cpp > CMakeFiles/client.dir/Map.cpp.i

src/client/CMakeFiles/client.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/Map.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/Map.cpp -o CMakeFiles/client.dir/Map.cpp.s

src/client/CMakeFiles/client.dir/Map.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/Map.cpp.o.requires

src/client/CMakeFiles/client.dir/Map.cpp.o.provides: src/client/CMakeFiles/client.dir/Map.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/Map.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/Map.cpp.o.provides

src/client/CMakeFiles/client.dir/Map.cpp.o.provides.build: src/client/CMakeFiles/client.dir/Map.cpp.o

src/client/CMakeFiles/client.dir/HUD.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/HUD.cpp.o: ../src/client/HUD.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/HUD.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/HUD.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/HUD.cpp

src/client/CMakeFiles/client.dir/HUD.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/HUD.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/HUD.cpp > CMakeFiles/client.dir/HUD.cpp.i

src/client/CMakeFiles/client.dir/HUD.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/HUD.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/HUD.cpp -o CMakeFiles/client.dir/HUD.cpp.s

src/client/CMakeFiles/client.dir/HUD.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/HUD.cpp.o.requires

src/client/CMakeFiles/client.dir/HUD.cpp.o.provides: src/client/CMakeFiles/client.dir/HUD.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/HUD.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/HUD.cpp.o.provides

src/client/CMakeFiles/client.dir/HUD.cpp.o.provides.build: src/client/CMakeFiles/client.dir/HUD.cpp.o

src/client/CMakeFiles/client.dir/MapLoader.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/MapLoader.cpp.o: ../src/client/MapLoader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/MapLoader.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/MapLoader.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/MapLoader.cpp

src/client/CMakeFiles/client.dir/MapLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/MapLoader.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/MapLoader.cpp > CMakeFiles/client.dir/MapLoader.cpp.i

src/client/CMakeFiles/client.dir/MapLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/MapLoader.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/MapLoader.cpp -o CMakeFiles/client.dir/MapLoader.cpp.s

src/client/CMakeFiles/client.dir/MapLoader.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/MapLoader.cpp.o.requires

src/client/CMakeFiles/client.dir/MapLoader.cpp.o.provides: src/client/CMakeFiles/client.dir/MapLoader.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/MapLoader.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/MapLoader.cpp.o.provides

src/client/CMakeFiles/client.dir/MapLoader.cpp.o.provides.build: src/client/CMakeFiles/client.dir/MapLoader.cpp.o

src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o: ../src/client/UI/UI_Elements.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/UI/UI_Elements.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/UI/UI_Elements.cpp

src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/UI/UI_Elements.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/UI/UI_Elements.cpp > CMakeFiles/client.dir/UI/UI_Elements.cpp.i

src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/UI/UI_Elements.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/UI/UI_Elements.cpp -o CMakeFiles/client.dir/UI/UI_Elements.cpp.s

src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o.requires

src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o.provides: src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o.provides

src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o.provides.build: src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o

src/client/CMakeFiles/client.dir/tcp_net.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/tcp_net.cpp.o: ../src/client/tcp_net.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/tcp_net.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/tcp_net.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/tcp_net.cpp

src/client/CMakeFiles/client.dir/tcp_net.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/tcp_net.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/tcp_net.cpp > CMakeFiles/client.dir/tcp_net.cpp.i

src/client/CMakeFiles/client.dir/tcp_net.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/tcp_net.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/tcp_net.cpp -o CMakeFiles/client.dir/tcp_net.cpp.s

src/client/CMakeFiles/client.dir/tcp_net.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/tcp_net.cpp.o.requires

src/client/CMakeFiles/client.dir/tcp_net.cpp.o.provides: src/client/CMakeFiles/client.dir/tcp_net.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/tcp_net.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/tcp_net.cpp.o.provides

src/client/CMakeFiles/client.dir/tcp_net.cpp.o.provides.build: src/client/CMakeFiles/client.dir/tcp_net.cpp.o

src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o: ../src/client/Players/PlayerInformation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/Players/PlayerInformation.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/Players/PlayerInformation.cpp

src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/Players/PlayerInformation.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/Players/PlayerInformation.cpp > CMakeFiles/client.dir/Players/PlayerInformation.cpp.i

src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/Players/PlayerInformation.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/Players/PlayerInformation.cpp -o CMakeFiles/client.dir/Players/PlayerInformation.cpp.s

src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o.requires

src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o.provides: src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o.provides

src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o.provides.build: src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o

src/client/CMakeFiles/client.dir/Player.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/Player.cpp.o: ../src/client/Player.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/Player.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/Player.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/Player.cpp

src/client/CMakeFiles/client.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/Player.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/Player.cpp > CMakeFiles/client.dir/Player.cpp.i

src/client/CMakeFiles/client.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/Player.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/Player.cpp -o CMakeFiles/client.dir/Player.cpp.s

src/client/CMakeFiles/client.dir/Player.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/Player.cpp.o.requires

src/client/CMakeFiles/client.dir/Player.cpp.o.provides: src/client/CMakeFiles/client.dir/Player.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/Player.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/Player.cpp.o.provides

src/client/CMakeFiles/client.dir/Player.cpp.o.provides.build: src/client/CMakeFiles/client.dir/Player.cpp.o

src/client/CMakeFiles/client.dir/mersenne.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/mersenne.cpp.o: ../src/client/mersenne.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/mersenne.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/mersenne.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/mersenne.cpp

src/client/CMakeFiles/client.dir/mersenne.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/mersenne.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/mersenne.cpp > CMakeFiles/client.dir/mersenne.cpp.i

src/client/CMakeFiles/client.dir/mersenne.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/mersenne.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/mersenne.cpp -o CMakeFiles/client.dir/mersenne.cpp.s

src/client/CMakeFiles/client.dir/mersenne.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/mersenne.cpp.o.requires

src/client/CMakeFiles/client.dir/mersenne.cpp.o.provides: src/client/CMakeFiles/client.dir/mersenne.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/mersenne.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/mersenne.cpp.o.provides

src/client/CMakeFiles/client.dir/mersenne.cpp.o.provides.build: src/client/CMakeFiles/client.dir/mersenne.cpp.o

src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o: ../src/shared/Packets.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/__/shared/Packets.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/shared/Packets.cpp

src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/__/shared/Packets.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/shared/Packets.cpp > CMakeFiles/client.dir/__/shared/Packets.cpp.i

src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/__/shared/Packets.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/shared/Packets.cpp -o CMakeFiles/client.dir/__/shared/Packets.cpp.s

src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o.requires

src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o.provides: src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o.provides

src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o.provides.build: src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o

src/client/CMakeFiles/client.dir/Map/Tile.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/Map/Tile.cpp.o: ../src/client/Map/Tile.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/Map/Tile.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/Map/Tile.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/Map/Tile.cpp

src/client/CMakeFiles/client.dir/Map/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/Map/Tile.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/Map/Tile.cpp > CMakeFiles/client.dir/Map/Tile.cpp.i

src/client/CMakeFiles/client.dir/Map/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/Map/Tile.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/Map/Tile.cpp -o CMakeFiles/client.dir/Map/Tile.cpp.s

src/client/CMakeFiles/client.dir/Map/Tile.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/Map/Tile.cpp.o.requires

src/client/CMakeFiles/client.dir/Map/Tile.cpp.o.provides: src/client/CMakeFiles/client.dir/Map/Tile.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/Map/Tile.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/Map/Tile.cpp.o.provides

src/client/CMakeFiles/client.dir/Map/Tile.cpp.o.provides.build: src/client/CMakeFiles/client.dir/Map/Tile.cpp.o

src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o: ../src/client/SpriteSheet.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/SpriteSheet.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/SpriteSheet.cpp

src/client/CMakeFiles/client.dir/SpriteSheet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/SpriteSheet.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/SpriteSheet.cpp > CMakeFiles/client.dir/SpriteSheet.cpp.i

src/client/CMakeFiles/client.dir/SpriteSheet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/SpriteSheet.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/SpriteSheet.cpp -o CMakeFiles/client.dir/SpriteSheet.cpp.s

src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o.requires

src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o.provides: src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o.provides

src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o.provides.build: src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o

src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o: src/client/CMakeFiles/client.dir/flags.make
src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o: ../src/client/SpriteSheetAnimator.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/SM2ACM3k1/build/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o -c /home/mafiamole/projects/SM2ACM3k1/src/client/SpriteSheetAnimator.cpp

src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/SpriteSheetAnimator.cpp.i"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/SM2ACM3k1/src/client/SpriteSheetAnimator.cpp > CMakeFiles/client.dir/SpriteSheetAnimator.cpp.i

src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/SpriteSheetAnimator.cpp.s"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/SM2ACM3k1/src/client/SpriteSheetAnimator.cpp -o CMakeFiles/client.dir/SpriteSheetAnimator.cpp.s

src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o.requires:
.PHONY : src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o.requires

src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o.provides: src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o.requires
	$(MAKE) -f src/client/CMakeFiles/client.dir/build.make src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o.provides.build
.PHONY : src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o.provides

src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o.provides.build: src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/Game.cpp.o" \
"CMakeFiles/client.dir/Main.cpp.o" \
"CMakeFiles/client.dir/Map.cpp.o" \
"CMakeFiles/client.dir/HUD.cpp.o" \
"CMakeFiles/client.dir/MapLoader.cpp.o" \
"CMakeFiles/client.dir/UI/UI_Elements.cpp.o" \
"CMakeFiles/client.dir/tcp_net.cpp.o" \
"CMakeFiles/client.dir/Players/PlayerInformation.cpp.o" \
"CMakeFiles/client.dir/Player.cpp.o" \
"CMakeFiles/client.dir/mersenne.cpp.o" \
"CMakeFiles/client.dir/__/shared/Packets.cpp.o" \
"CMakeFiles/client.dir/Map/Tile.cpp.o" \
"CMakeFiles/client.dir/SpriteSheet.cpp.o" \
"CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

src/client/client: src/client/CMakeFiles/client.dir/Game.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/Main.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/Map.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/HUD.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/MapLoader.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/tcp_net.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/Player.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/mersenne.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/Map/Tile.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o
src/client/client: src/client/CMakeFiles/client.dir/build.make
src/client/client: /usr/local/lib/libMoleBox.so
src/client/client: /usr/local/lib64/libsfml-system.so
src/client/client: /usr/local/lib64/libsfml-window.so
src/client/client: /usr/local/lib64/libsfml-graphics.so
src/client/client: /usr/local/lib64/libsfml-audio.so
src/client/client: /usr/local/lib64/libsfml-network.so
src/client/client: /usr/lib64/liblua-5.1.so
src/client/client: /usr/lib64/libm.so
src/client/client: src/client/CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable client"
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/client/CMakeFiles/client.dir/build: src/client/client
.PHONY : src/client/CMakeFiles/client.dir/build

src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/Game.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/Main.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/Map.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/HUD.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/MapLoader.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/UI/UI_Elements.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/tcp_net.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/Players/PlayerInformation.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/Player.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/mersenne.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/__/shared/Packets.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/Map/Tile.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/SpriteSheet.cpp.o.requires
src/client/CMakeFiles/client.dir/requires: src/client/CMakeFiles/client.dir/SpriteSheetAnimator.cpp.o.requires
.PHONY : src/client/CMakeFiles/client.dir/requires

src/client/CMakeFiles/client.dir/clean:
	cd /home/mafiamole/projects/SM2ACM3k1/build/src/client && $(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : src/client/CMakeFiles/client.dir/clean

src/client/CMakeFiles/client.dir/depend:
	cd /home/mafiamole/projects/SM2ACM3k1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mafiamole/projects/SM2ACM3k1 /home/mafiamole/projects/SM2ACM3k1/src/client /home/mafiamole/projects/SM2ACM3k1/build /home/mafiamole/projects/SM2ACM3k1/build/src/client /home/mafiamole/projects/SM2ACM3k1/build/src/client/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/client/CMakeFiles/client.dir/depend


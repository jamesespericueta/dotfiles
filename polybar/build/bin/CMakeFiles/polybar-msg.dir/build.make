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
CMAKE_SOURCE_DIR = /home/james/src/polybar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/james/src/polybar/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/polybar-msg.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/polybar-msg.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/polybar-msg.dir/flags.make

bin/CMakeFiles/polybar-msg.dir/ipc.cpp.o: bin/CMakeFiles/polybar-msg.dir/flags.make
bin/CMakeFiles/polybar-msg.dir/ipc.cpp.o: ../src/ipc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/src/polybar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/polybar-msg.dir/ipc.cpp.o"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/polybar-msg.dir/ipc.cpp.o -c /home/james/src/polybar/src/ipc.cpp

bin/CMakeFiles/polybar-msg.dir/ipc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/polybar-msg.dir/ipc.cpp.i"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/src/polybar/src/ipc.cpp > CMakeFiles/polybar-msg.dir/ipc.cpp.i

bin/CMakeFiles/polybar-msg.dir/ipc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/polybar-msg.dir/ipc.cpp.s"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/src/polybar/src/ipc.cpp -o CMakeFiles/polybar-msg.dir/ipc.cpp.s

bin/CMakeFiles/polybar-msg.dir/utils/env.cpp.o: bin/CMakeFiles/polybar-msg.dir/flags.make
bin/CMakeFiles/polybar-msg.dir/utils/env.cpp.o: ../src/utils/env.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/src/polybar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object bin/CMakeFiles/polybar-msg.dir/utils/env.cpp.o"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/polybar-msg.dir/utils/env.cpp.o -c /home/james/src/polybar/src/utils/env.cpp

bin/CMakeFiles/polybar-msg.dir/utils/env.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/polybar-msg.dir/utils/env.cpp.i"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/src/polybar/src/utils/env.cpp > CMakeFiles/polybar-msg.dir/utils/env.cpp.i

bin/CMakeFiles/polybar-msg.dir/utils/env.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/polybar-msg.dir/utils/env.cpp.s"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/src/polybar/src/utils/env.cpp -o CMakeFiles/polybar-msg.dir/utils/env.cpp.s

bin/CMakeFiles/polybar-msg.dir/utils/file.cpp.o: bin/CMakeFiles/polybar-msg.dir/flags.make
bin/CMakeFiles/polybar-msg.dir/utils/file.cpp.o: ../src/utils/file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/src/polybar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object bin/CMakeFiles/polybar-msg.dir/utils/file.cpp.o"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/polybar-msg.dir/utils/file.cpp.o -c /home/james/src/polybar/src/utils/file.cpp

bin/CMakeFiles/polybar-msg.dir/utils/file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/polybar-msg.dir/utils/file.cpp.i"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/src/polybar/src/utils/file.cpp > CMakeFiles/polybar-msg.dir/utils/file.cpp.i

bin/CMakeFiles/polybar-msg.dir/utils/file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/polybar-msg.dir/utils/file.cpp.s"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/src/polybar/src/utils/file.cpp -o CMakeFiles/polybar-msg.dir/utils/file.cpp.s

bin/CMakeFiles/polybar-msg.dir/utils/string.cpp.o: bin/CMakeFiles/polybar-msg.dir/flags.make
bin/CMakeFiles/polybar-msg.dir/utils/string.cpp.o: ../src/utils/string.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/james/src/polybar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object bin/CMakeFiles/polybar-msg.dir/utils/string.cpp.o"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/polybar-msg.dir/utils/string.cpp.o -c /home/james/src/polybar/src/utils/string.cpp

bin/CMakeFiles/polybar-msg.dir/utils/string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/polybar-msg.dir/utils/string.cpp.i"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/james/src/polybar/src/utils/string.cpp > CMakeFiles/polybar-msg.dir/utils/string.cpp.i

bin/CMakeFiles/polybar-msg.dir/utils/string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/polybar-msg.dir/utils/string.cpp.s"
	cd /home/james/src/polybar/build/bin && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/james/src/polybar/src/utils/string.cpp -o CMakeFiles/polybar-msg.dir/utils/string.cpp.s

# Object files for target polybar-msg
polybar__msg_OBJECTS = \
"CMakeFiles/polybar-msg.dir/ipc.cpp.o" \
"CMakeFiles/polybar-msg.dir/utils/env.cpp.o" \
"CMakeFiles/polybar-msg.dir/utils/file.cpp.o" \
"CMakeFiles/polybar-msg.dir/utils/string.cpp.o"

# External object files for target polybar-msg
polybar__msg_EXTERNAL_OBJECTS =

bin/polybar-msg: bin/CMakeFiles/polybar-msg.dir/ipc.cpp.o
bin/polybar-msg: bin/CMakeFiles/polybar-msg.dir/utils/env.cpp.o
bin/polybar-msg: bin/CMakeFiles/polybar-msg.dir/utils/file.cpp.o
bin/polybar-msg: bin/CMakeFiles/polybar-msg.dir/utils/string.cpp.o
bin/polybar-msg: bin/CMakeFiles/polybar-msg.dir/build.make
bin/polybar-msg: bin/CMakeFiles/polybar-msg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/james/src/polybar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable polybar-msg"
	cd /home/james/src/polybar/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/polybar-msg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/polybar-msg.dir/build: bin/polybar-msg

.PHONY : bin/CMakeFiles/polybar-msg.dir/build

bin/CMakeFiles/polybar-msg.dir/clean:
	cd /home/james/src/polybar/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/polybar-msg.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/polybar-msg.dir/clean

bin/CMakeFiles/polybar-msg.dir/depend:
	cd /home/james/src/polybar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/james/src/polybar /home/james/src/polybar/src /home/james/src/polybar/build /home/james/src/polybar/build/bin /home/james/src/polybar/build/bin/CMakeFiles/polybar-msg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/polybar-msg.dir/depend

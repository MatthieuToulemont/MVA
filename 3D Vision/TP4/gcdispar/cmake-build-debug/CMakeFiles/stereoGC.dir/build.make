# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /snap/clion/44/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/44/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/stereoGC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stereoGC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stereoGC.dir/flags.make

CMakeFiles/stereoGC.dir/stereoGC.cpp.o: CMakeFiles/stereoGC.dir/flags.make
CMakeFiles/stereoGC.dir/stereoGC.cpp.o: ../stereoGC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stereoGC.dir/stereoGC.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stereoGC.dir/stereoGC.cpp.o -c "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/stereoGC.cpp"

CMakeFiles/stereoGC.dir/stereoGC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stereoGC.dir/stereoGC.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/stereoGC.cpp" > CMakeFiles/stereoGC.dir/stereoGC.cpp.i

CMakeFiles/stereoGC.dir/stereoGC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stereoGC.dir/stereoGC.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/stereoGC.cpp" -o CMakeFiles/stereoGC.dir/stereoGC.cpp.s

CMakeFiles/stereoGC.dir/maxflow/graph.cpp.o: CMakeFiles/stereoGC.dir/flags.make
CMakeFiles/stereoGC.dir/maxflow/graph.cpp.o: ../maxflow/graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/stereoGC.dir/maxflow/graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stereoGC.dir/maxflow/graph.cpp.o -c "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/maxflow/graph.cpp"

CMakeFiles/stereoGC.dir/maxflow/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stereoGC.dir/maxflow/graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/maxflow/graph.cpp" > CMakeFiles/stereoGC.dir/maxflow/graph.cpp.i

CMakeFiles/stereoGC.dir/maxflow/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stereoGC.dir/maxflow/graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/maxflow/graph.cpp" -o CMakeFiles/stereoGC.dir/maxflow/graph.cpp.s

# Object files for target stereoGC
stereoGC_OBJECTS = \
"CMakeFiles/stereoGC.dir/stereoGC.cpp.o" \
"CMakeFiles/stereoGC.dir/maxflow/graph.cpp.o"

# External object files for target stereoGC
stereoGC_EXTERNAL_OBJECTS =

stereoGC: CMakeFiles/stereoGC.dir/stereoGC.cpp.o
stereoGC: CMakeFiles/stereoGC.dir/maxflow/graph.cpp.o
stereoGC: CMakeFiles/stereoGC.dir/build.make
stereoGC: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.9.5
stereoGC: /usr/lib/x86_64-linux-gnu/libGL.so
stereoGC: /usr/lib/x86_64-linux-gnu/libGLU.so
stereoGC: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
stereoGC: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
stereoGC: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
stereoGC: CMakeFiles/stereoGC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable stereoGC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stereoGC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stereoGC.dir/build: stereoGC

.PHONY : CMakeFiles/stereoGC.dir/build

CMakeFiles/stereoGC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stereoGC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stereoGC.dir/clean

CMakeFiles/stereoGC.dir/depend:
	cd "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar" "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar" "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/cmake-build-debug" "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/cmake-build-debug" "/home/matthieu/Documents/MVA 2018/3D Vision/TP4/gcdispar/cmake-build-debug/CMakeFiles/stereoGC.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/stereoGC.dir/depend


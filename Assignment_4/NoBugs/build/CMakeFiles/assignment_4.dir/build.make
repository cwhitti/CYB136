# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/build

# Include any dependencies generated for this target.
include CMakeFiles/assignment_4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/assignment_4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/assignment_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assignment_4.dir/flags.make

CMakeFiles/assignment_4.dir/main.cpp.o: CMakeFiles/assignment_4.dir/flags.make
CMakeFiles/assignment_4.dir/main.cpp.o: /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/main.cpp
CMakeFiles/assignment_4.dir/main.cpp.o: CMakeFiles/assignment_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assignment_4.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_4.dir/main.cpp.o -MF CMakeFiles/assignment_4.dir/main.cpp.o.d -o CMakeFiles/assignment_4.dir/main.cpp.o -c /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/main.cpp

CMakeFiles/assignment_4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/assignment_4.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/main.cpp > CMakeFiles/assignment_4.dir/main.cpp.i

CMakeFiles/assignment_4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/assignment_4.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/main.cpp -o CMakeFiles/assignment_4.dir/main.cpp.s

CMakeFiles/assignment_4.dir/BSTClass.cpp.o: CMakeFiles/assignment_4.dir/flags.make
CMakeFiles/assignment_4.dir/BSTClass.cpp.o: /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/BSTClass.cpp
CMakeFiles/assignment_4.dir/BSTClass.cpp.o: CMakeFiles/assignment_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/assignment_4.dir/BSTClass.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_4.dir/BSTClass.cpp.o -MF CMakeFiles/assignment_4.dir/BSTClass.cpp.o.d -o CMakeFiles/assignment_4.dir/BSTClass.cpp.o -c /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/BSTClass.cpp

CMakeFiles/assignment_4.dir/BSTClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/assignment_4.dir/BSTClass.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/BSTClass.cpp > CMakeFiles/assignment_4.dir/BSTClass.cpp.i

CMakeFiles/assignment_4.dir/BSTClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/assignment_4.dir/BSTClass.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/BSTClass.cpp -o CMakeFiles/assignment_4.dir/BSTClass.cpp.s

CMakeFiles/assignment_4.dir/LogClass.cpp.o: CMakeFiles/assignment_4.dir/flags.make
CMakeFiles/assignment_4.dir/LogClass.cpp.o: /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/LogClass.cpp
CMakeFiles/assignment_4.dir/LogClass.cpp.o: CMakeFiles/assignment_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/assignment_4.dir/LogClass.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_4.dir/LogClass.cpp.o -MF CMakeFiles/assignment_4.dir/LogClass.cpp.o.d -o CMakeFiles/assignment_4.dir/LogClass.cpp.o -c /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/LogClass.cpp

CMakeFiles/assignment_4.dir/LogClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/assignment_4.dir/LogClass.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/LogClass.cpp > CMakeFiles/assignment_4.dir/LogClass.cpp.i

CMakeFiles/assignment_4.dir/LogClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/assignment_4.dir/LogClass.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/LogClass.cpp -o CMakeFiles/assignment_4.dir/LogClass.cpp.s

CMakeFiles/assignment_4.dir/supportingFunctions.cpp.o: CMakeFiles/assignment_4.dir/flags.make
CMakeFiles/assignment_4.dir/supportingFunctions.cpp.o: /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/supportingFunctions.cpp
CMakeFiles/assignment_4.dir/supportingFunctions.cpp.o: CMakeFiles/assignment_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/assignment_4.dir/supportingFunctions.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_4.dir/supportingFunctions.cpp.o -MF CMakeFiles/assignment_4.dir/supportingFunctions.cpp.o.d -o CMakeFiles/assignment_4.dir/supportingFunctions.cpp.o -c /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/supportingFunctions.cpp

CMakeFiles/assignment_4.dir/supportingFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/assignment_4.dir/supportingFunctions.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/supportingFunctions.cpp > CMakeFiles/assignment_4.dir/supportingFunctions.cpp.i

CMakeFiles/assignment_4.dir/supportingFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/assignment_4.dir/supportingFunctions.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/supportingFunctions.cpp -o CMakeFiles/assignment_4.dir/supportingFunctions.cpp.s

# Object files for target assignment_4
assignment_4_OBJECTS = \
"CMakeFiles/assignment_4.dir/main.cpp.o" \
"CMakeFiles/assignment_4.dir/BSTClass.cpp.o" \
"CMakeFiles/assignment_4.dir/LogClass.cpp.o" \
"CMakeFiles/assignment_4.dir/supportingFunctions.cpp.o"

# External object files for target assignment_4
assignment_4_EXTERNAL_OBJECTS =

assignment_4: CMakeFiles/assignment_4.dir/main.cpp.o
assignment_4: CMakeFiles/assignment_4.dir/BSTClass.cpp.o
assignment_4: CMakeFiles/assignment_4.dir/LogClass.cpp.o
assignment_4: CMakeFiles/assignment_4.dir/supportingFunctions.cpp.o
assignment_4: CMakeFiles/assignment_4.dir/build.make
assignment_4: spdlog/libspdlog.a
assignment_4: CMakeFiles/assignment_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable assignment_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assignment_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assignment_4.dir/build: assignment_4
.PHONY : CMakeFiles/assignment_4.dir/build

CMakeFiles/assignment_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assignment_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assignment_4.dir/clean

CMakeFiles/assignment_4.dir/depend:
	cd /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/build /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/build /Users/claire/Documents/GitHub/CYB136/Assignment_4/NoBugs/build/CMakeFiles/assignment_4.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/assignment_4.dir/depend

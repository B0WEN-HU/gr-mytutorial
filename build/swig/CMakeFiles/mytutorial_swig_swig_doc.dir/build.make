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
CMAKE_SOURCE_DIR = /home/bowen/Documents/GR_learn/gr-mytutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bowen/Documents/GR_learn/gr-mytutorial/build

# Utility rule file for mytutorial_swig_swig_doc.

# Include the progress variables for this target.
include swig/CMakeFiles/mytutorial_swig_swig_doc.dir/progress.make

swig/CMakeFiles/mytutorial_swig_swig_doc: swig/mytutorial_swig_doc.i


swig/mytutorial_swig_doc.i: swig/mytutorial_swig_doc_swig_docs/xml/index.xml
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/bowen/Documents/GR_learn/gr-mytutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating python docstrings for mytutorial_swig_doc"
	cd /home/bowen/Documents/GR_learn/gr-mytutorial/docs/doxygen && /usr/bin/python2 -B /home/bowen/Documents/GR_learn/gr-mytutorial/docs/doxygen/swig_doc.py /home/bowen/Documents/GR_learn/gr-mytutorial/build/swig/mytutorial_swig_doc_swig_docs/xml /home/bowen/Documents/GR_learn/gr-mytutorial/build/swig/mytutorial_swig_doc.i

swig/mytutorial_swig_doc_swig_docs/xml/index.xml: swig/_mytutorial_swig_doc_tag
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/bowen/Documents/GR_learn/gr-mytutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating doxygen xml for mytutorial_swig_doc docs"
	cd /home/bowen/Documents/GR_learn/gr-mytutorial/build/swig && ./_mytutorial_swig_doc_tag
	cd /home/bowen/Documents/GR_learn/gr-mytutorial/build/swig && /usr/bin/doxygen /home/bowen/Documents/GR_learn/gr-mytutorial/build/swig/mytutorial_swig_doc_swig_docs/Doxyfile

mytutorial_swig_swig_doc: swig/CMakeFiles/mytutorial_swig_swig_doc
mytutorial_swig_swig_doc: swig/mytutorial_swig_doc.i
mytutorial_swig_swig_doc: swig/mytutorial_swig_doc_swig_docs/xml/index.xml
mytutorial_swig_swig_doc: swig/CMakeFiles/mytutorial_swig_swig_doc.dir/build.make

.PHONY : mytutorial_swig_swig_doc

# Rule to build all files generated by this target.
swig/CMakeFiles/mytutorial_swig_swig_doc.dir/build: mytutorial_swig_swig_doc

.PHONY : swig/CMakeFiles/mytutorial_swig_swig_doc.dir/build

swig/CMakeFiles/mytutorial_swig_swig_doc.dir/clean:
	cd /home/bowen/Documents/GR_learn/gr-mytutorial/build/swig && $(CMAKE_COMMAND) -P CMakeFiles/mytutorial_swig_swig_doc.dir/cmake_clean.cmake
.PHONY : swig/CMakeFiles/mytutorial_swig_swig_doc.dir/clean

swig/CMakeFiles/mytutorial_swig_swig_doc.dir/depend:
	cd /home/bowen/Documents/GR_learn/gr-mytutorial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bowen/Documents/GR_learn/gr-mytutorial /home/bowen/Documents/GR_learn/gr-mytutorial/swig /home/bowen/Documents/GR_learn/gr-mytutorial/build /home/bowen/Documents/GR_learn/gr-mytutorial/build/swig /home/bowen/Documents/GR_learn/gr-mytutorial/build/swig/CMakeFiles/mytutorial_swig_swig_doc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : swig/CMakeFiles/mytutorial_swig_swig_doc.dir/depend


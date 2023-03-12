# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kanken/code/ARHS-Thermx/Plugins/Thermx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanken/code/ARHS-Thermx/Plugins/Thermx

# Include any dependencies generated for this target.
include CMakeFiles/thermixLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/thermixLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/thermixLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thermixLib.dir/flags.make

CMakeFiles/thermixLib.dir/ThermxController.cpp.o: CMakeFiles/thermixLib.dir/flags.make
CMakeFiles/thermixLib.dir/ThermxController.cpp.o: ThermxController.cpp
CMakeFiles/thermixLib.dir/ThermxController.cpp.o: CMakeFiles/thermixLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/ARHS-Thermx/Plugins/Thermx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thermixLib.dir/ThermxController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/thermixLib.dir/ThermxController.cpp.o -MF CMakeFiles/thermixLib.dir/ThermxController.cpp.o.d -o CMakeFiles/thermixLib.dir/ThermxController.cpp.o -c /home/kanken/code/ARHS-Thermx/Plugins/Thermx/ThermxController.cpp

CMakeFiles/thermixLib.dir/ThermxController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thermixLib.dir/ThermxController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/ARHS-Thermx/Plugins/Thermx/ThermxController.cpp > CMakeFiles/thermixLib.dir/ThermxController.cpp.i

CMakeFiles/thermixLib.dir/ThermxController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thermixLib.dir/ThermxController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/ARHS-Thermx/Plugins/Thermx/ThermxController.cpp -o CMakeFiles/thermixLib.dir/ThermxController.cpp.s

CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.o: CMakeFiles/thermixLib.dir/flags.make
CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.o: ThermxRenderer.cpp
CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.o: CMakeFiles/thermixLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/ARHS-Thermx/Plugins/Thermx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.o -MF CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.o.d -o CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.o -c /home/kanken/code/ARHS-Thermx/Plugins/Thermx/ThermxRenderer.cpp

CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/ARHS-Thermx/Plugins/Thermx/ThermxRenderer.cpp > CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.i

CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/ARHS-Thermx/Plugins/Thermx/ThermxRenderer.cpp -o CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.s

# Object files for target thermixLib
thermixLib_OBJECTS = \
"CMakeFiles/thermixLib.dir/ThermxController.cpp.o" \
"CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.o"

# External object files for target thermixLib
thermixLib_EXTERNAL_OBJECTS =

libthermixLib.so: CMakeFiles/thermixLib.dir/ThermxController.cpp.o
libthermixLib.so: CMakeFiles/thermixLib.dir/ThermxRenderer.cpp.o
libthermixLib.so: CMakeFiles/thermixLib.dir/build.make
libthermixLib.so: /usr/local/lib/libopencv_gapi.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_stitching.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_aruco.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_barcode.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_bgsegm.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_bioinspired.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_ccalib.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_dnn_objdetect.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_dnn_superres.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_dpm.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_face.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_freetype.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_fuzzy.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_hfs.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_img_hash.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_intensity_transform.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_line_descriptor.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_mcc.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_quality.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_rapid.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_reg.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_rgbd.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_saliency.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_stereo.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_structured_light.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_superres.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_surface_matching.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_tracking.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_videostab.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_wechat_qrcode.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_xfeatures2d.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_xobjdetect.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_xphoto.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_shape.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_highgui.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_datasets.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_plot.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_text.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_ml.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_phase_unwrapping.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_optflow.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_ximgproc.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_video.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_videoio.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_objdetect.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_calib3d.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_dnn.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_features2d.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_flann.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_photo.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_imgproc.so.4.6.0
libthermixLib.so: /usr/local/lib/libopencv_core.so.4.6.0
libthermixLib.so: CMakeFiles/thermixLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/ARHS-Thermx/Plugins/Thermx/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libthermixLib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thermixLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thermixLib.dir/build: libthermixLib.so
.PHONY : CMakeFiles/thermixLib.dir/build

CMakeFiles/thermixLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thermixLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thermixLib.dir/clean

CMakeFiles/thermixLib.dir/depend:
	cd /home/kanken/code/ARHS-Thermx/Plugins/Thermx && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/ARHS-Thermx/Plugins/Thermx /home/kanken/code/ARHS-Thermx/Plugins/Thermx /home/kanken/code/ARHS-Thermx/Plugins/Thermx /home/kanken/code/ARHS-Thermx/Plugins/Thermx /home/kanken/code/ARHS-Thermx/Plugins/Thermx/CMakeFiles/thermixLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thermixLib.dir/depend


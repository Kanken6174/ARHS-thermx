PROJECT(thermx)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(thermx_src
    ThermxController.hpp
    ThermxController.cpp
    ThermxRenderer.hpp
    ThermxRenderer.cpp
    Factory.cpp
)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY /home/kanken/code/AHRS_core/src/plugins/)
#SET(GCC_COVERAGE_COMPILE_FLAGS "-fsanitize=undefined,address")
#SET(GCC_COVERAGE_LINK_FLAGS    "-fsanitize=undefined,address")

#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
#SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

find_package( OpenCV REQUIRED )
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

ADD_LIBRARY(thermix SHARED ${thermx_src})

target_link_libraries(thermix ${OpenCV_LIBS})
target_link_libraries(thermix ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
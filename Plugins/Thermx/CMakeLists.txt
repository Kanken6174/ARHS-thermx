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

find_package( OpenCV REQUIRED )
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

ADD_LIBRARY(thermix SHARED ${thermx_src})

target_link_libraries(thermix ${OpenCV_LIBS})
target_link_libraries(thermix ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
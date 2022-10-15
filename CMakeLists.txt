cmake_minimum_required(VERSION 3.22)
project(my_open_gl)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(libs/math_lib)
add_subdirectory(libs/glew-cmake-2.2.0)

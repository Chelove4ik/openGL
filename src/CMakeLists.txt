include_directories(${math_lib_SOURCE_DIR}/include/)
include_directories(${glew_SOURCE_DIR}/include/)
include_directories(D:/libs/SFML-2.5.1/include/)

add_executable(my_open_gl main.cpp)
target_link_libraries(my_open_gl math_lib)
target_link_libraries(my_open_gl libglew_static)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_PREFIX_PATH "D:/libs/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML COMPONENTS main graphics window system REQUIRED)
target_link_libraries(my_open_gl sfml-main sfml-graphics sfml-window sfml-system)

include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${math_lib_SOURCE_DIR}/include/)
include_directories(${glew_SOURCE_DIR}/include/)
include_directories(D:/libs/SFML-2.5.1/include/)

include_directories(utils)
include_directories(${PROJECT_SOURCE_DIR}/libs/imgui-1.88/)
include_directories(${PROJECT_SOURCE_DIR}/libs/imgui-sfml-2.5/)

add_executable(my_open_gl
        main.cpp
        utils/shaderLoader.cpp #utils/assimpParser.cpp
        ${PROJECT_SOURCE_DIR}/libs/imgui-1.88/imgui.cpp ${PROJECT_SOURCE_DIR}/libs/imgui-1.88/imgui_widgets.cpp ${PROJECT_SOURCE_DIR}/libs/imgui-1.88/imgui_draw.cpp ${PROJECT_SOURCE_DIR}/libs/imgui-1.88/imgui_tables.cpp
        ${PROJECT_SOURCE_DIR}/libs/imgui-sfml-2.5/imgui-SFML.cpp
        Triangle.cpp ../include/Triangle.h)

target_link_libraries(my_open_gl math_lib)
target_link_libraries(my_open_gl libglew_static)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_PREFIX_PATH "D:/libs/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML COMPONENTS main graphics window system REQUIRED)
target_link_libraries(my_open_gl sfml-main sfml-graphics sfml-window sfml-system)

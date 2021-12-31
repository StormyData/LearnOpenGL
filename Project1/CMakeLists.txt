# CMakeList.txt : CMake project for Project 1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory(src)

configure_file("version_number_test.h.in" "version_number_test.h")

# Add source to this project's executable.
add_executable (CMakeTarget "main.cpp" "main.h")

# TODO: Add tests and install targets if needed.


target_include_directories(CMakeTarget PUBLIC
                           "${PROJECT_BINARY_DIR}/Project1"
                           "D:/OpenGL/include"
                           "include"
                           )
target_link_libraries(CMakeTarget PUBLIC 
                            "D:/OpenGL/lib/glfw3.lib"
                            "opengl32.lib"
                            GLAD
                            SHADERS
                            OBJECTS
                            STB_IMAGE
                            )

#install(TARGETS CMakeTarget Destination bin)
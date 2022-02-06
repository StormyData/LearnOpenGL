cmake_minimum_required(VERSION 3.0)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(include/glad)
add_subdirectory(include/stb_image)
add_subdirectory(src)
add_subdirectory(shaders)



add_executable(LearnOpenGL main.cpp)

add_dependencies(LearnOpenGL shader-files)

find_package(glm REQUIRED)
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(LearnOpenGL
        GLAD
        SHADERS
        OBJECTS
        $<$<PLATFORM_ID:Linux>:glm>
	    glfw
        )
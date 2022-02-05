cmake_minimum_required(VERSION 3.8)

add_library(SHADERS "Shader.cpp" "Shader.h")
add_library(OBJECTS "Object.cpp" "Object.h")

target_include_directories(SHADERS
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PUBLIC ../include/glad
          )
target_include_directories(OBJECTS
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PUBLIC ../include/glad
          )
cmake_minimum_required (VERSION 3.8)

add_library(GLAD "glad.c")
add_library(SHADERS "Shader.cpp" "Shader.h")
add_library(OBJECTS "Object.cpp" "Object.h")
add_library(STB_IMAGE "stb_image.cpp" "stb_image.h")

target_include_directories(GLAD
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PUBLIC "../include"
          )
target_include_directories(SHADERS
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PUBLIC "../include"
          )
target_include_directories(OBJECTS
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PUBLIC "../include"
          )
target_include_directories(STB_IMAGE
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PUBLIC "../include"
          )
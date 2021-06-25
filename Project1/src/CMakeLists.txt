cmake_minimum_required (VERSION 3.8)

add_library(GLAD glad.c)

target_include_directories(GLAD
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PUBLIC "../include"
          )
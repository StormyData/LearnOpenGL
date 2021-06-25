# CMakeList.txt : CMake project for Project 1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

configure_file("version_number_test.h.in" "version_number_test.h")

# Add source to this project's executable.
add_executable (CMakeTarget "Project 1.cpp" "Project 1.h")

# TODO: Add tests and install targets if needed.



target_include_directories(CMakeTarget PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
add_library(STB_IMAGE "stb_image.cpp" "stb_image.h")

target_include_directories(STB_IMAGE
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )

add_custom_target(shader-files DEPENDS frag.glsl vert.glsl)

add_custom_command(
        TARGET shader-files POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/frag.glsl
        "${CMAKE_BINARY_DIR}/shaders")

add_custom_command(
        TARGET shader-files POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/vert.glsl
        "${CMAKE_BINARY_DIR}/shaders")


install(FILES frag.glsl DESTINATION shaders)
install(FILES vert.glsl DESTINATION shaders)
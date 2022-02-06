add_library(GLAD glad.c glad.h)

target_include_directories(GLAD
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE $<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/KHR>
        )

target_link_libraries(GLAD
        PUBLIC ${CMAKE_DL_LIBS}
        )
install(TARGETS GLAD DESTINATION lib)
install(FILES glad.h DESTINATION include)
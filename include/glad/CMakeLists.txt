add_library(GLAD glad.c glad.h)
if(CMAKE_SYSTEM MATCHES Windows)
    list(APPEND KHR "${CMAKE_CURRENT_SOURCE_DIR}/KHR")
endif()

target_include_directories(GLAD
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE ${KHR}
        )

target_link_libraries(GLAD
        PUBLIC ${CMAKE_DL_LIBS}
        )
install(TARGETS GLAD DESTINATION lib)
install(FILES glad.h DESTINATION include)
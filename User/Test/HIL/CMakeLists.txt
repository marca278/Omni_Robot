add_library(AppHilTests
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/tests.cpp
)

target_include_directories(AppHilTests PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

target_link_libraries(AppHilTests PUBLIC Omni_Robot_Init)
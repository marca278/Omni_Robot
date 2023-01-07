add_library(Omni_Application
#    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Factory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/OmniApp.cpp 
)

target_include_directories(Omni_Application PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

target_link_libraries(Omni_Application PUBLIC  Omni_Robot_Init AppHilTests)

add_library(Omni_Robot_Init
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Factory.cpp
)

target_include_directories(Omni_Robot_Init PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

target_link_libraries(Omni_Robot_Init PUBLIC OmniDrive HC_SR04 STM32G4xx_Cpp_Hal Cube_Core)
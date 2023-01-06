add_library(UserApplication
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Factory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/OmniApp.cpp 
)

target_include_directories(UserApplication PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

target_link_libraries(UserApplication PRIVATE Omni_Drive HC_SR04 STM32G4xx_Cpp_Hal Cube_Core)
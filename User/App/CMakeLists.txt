add_library(UserApplication
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Factory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/OmniApp.cpp 
)

target_include_directories(UserApplication PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)
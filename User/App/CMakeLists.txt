add_library(UserApplication
    Factory.cpp
    OmniApp.cpp 
)

target_include_directories(UserApplication PRIVATE
    &{CMAKE_CURRENT_SOURCE_DIR}/Inc
)
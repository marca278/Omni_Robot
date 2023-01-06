#THIS FILE IS AUTO GENERATED FROM THE TEMPLATE! DO NOT CHANGE!

cmake_minimum_required(VERSION 3.24)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/arm-none-eabi-gcc.cmake)

# project settings
project(omni C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

include(FetchContent)

#Uncomment for hardware floating point
add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

#Uncomment for software floating point
#add_compile_options(-mfloat-abi=soft)

add_compile_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)

add_compile_options(-Wall -Wextra -Wpedantic)

# uncomment to mitigate c++17 absolute addresses warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")

# Enable assembler files preprocessing
add_compile_options($<$<COMPILE_LANGUAGE:ASM>:-x$<SEMICOLON>assembler-with-cpp>)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-Og -g)
endif ()

add_definitions(-DDEBUG -DUSE_HAL_DRIVER -DSTM32G491xx)





set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32G491RETX_FLASH.ld)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_link_options(-T ${LINKER_SCRIPT})

if(DEFINED ENV{GITHUB_ACTION})
    message("From github enviroment")
    set(GIT_REPO_CPP_INTERFACE https://marca278:$ENV{GH_PAT}@github.com/marca278/Hal_Cpp_Interface.git)
    set(GIT_REPO_G4_HALL https://marca278:$ENV{GH_PAT}@github.com/marca278/STM32G4xx_Cpp_Hal.git)
    set(GIT_REPO_COMPONENT https://marca278:$ENV{GH_PAT}@github.com/marca278/Mcu_Components.git)
else()
    message("From local enviroment")
    set(GIT_REPO_CPP_INTERFACE https://github.com/marca278/Hal_Cpp_Interface.git)
    set(GIT_REPO_G4_HALL https://github.com/marca278/STM32G4xx_Cpp_Hal.git)
    set(GIT_REPO_COMPONENT https://github.com/marca278/Mcu_Components.git)
endif()

FetchContent_Declare(HAL_CPP_INTERFACE
    GIT_REPOSITORY ${GIT_REPO_CPP_INTERFACE}
    GIT_TAG        origin/main
    SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/User/Hal/Interface
)


FetchContent_Declare(STM32G4XX_CPP_HAL
    GIT_REPOSITORY ${GIT_REPO_G4_HALL}
    GIT_TAG        origin/main
    SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/User/Hal/Implementation
)

FetchContent_Declare(MCU_COMPONENTS
    GIT_REPOSITORY ${GIT_REPO_COMPONENT}
    GIT_TAG        origin/main
    SOURCE_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/User/Components
)

FetchContent_MakeAvailable(HAL_CPP_INTERFACE STM32G4XX_CPP_HAL MCU_COMPONENTS)

add_subdirectory(Drivers)
add_subdirectory(Core)
add_subdirectory(User)


add_executable(${PROJECT_NAME}.elf 
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Startup/startup_stm32g491retx.s
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/main.c
    ${LINKER_SCRIPT}
)
target_link_libraries(${PROJECT_NAME}.elf PRIVATE STM32G4xx_CubeLib Cube_Core)

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE} #Building ${BIN_FILE}"
)

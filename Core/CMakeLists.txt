add_library(Cube_Core
#    ${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup_stm32g491retx.s
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/dac.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/gpio.c
#    ${CMAKE_CURRENT_SOURCE_DIR}/Src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/opamp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/stm32g4xx_hal_msp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/stm32g4xx_it.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/syscalls.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/sysmem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/system_stm32g4xx.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/tim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/usart.c
)

target_include_directories(Cube_Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

target_link_libraries(Cube_Core PUBLIC STM32G4xx_CubeLib)



add_library(
    STM32G4xx_CubeLib
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_cortex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dac_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dac.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_exti.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ramfunc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_opamp_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_opamp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_tim_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_tim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_uart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal.c
    )

target_include_directories(
    STM32G4xx_CubeLib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}//STM32G4xx_HAL_Driver
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Inc 
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32G4xx_HAL_Driver/Inc/Legacy 
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/Device/ST/STM32G4xx/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/Include
    )

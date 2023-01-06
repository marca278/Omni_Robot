/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define TIM1_CH3_TRIGGER_Pin GPIO_PIN_2
#define TIM1_CH3_TRIGGER_GPIO_Port GPIOC
#define SetRightRearBack_Pin GPIO_PIN_3
#define SetRightRearBack_GPIO_Port GPIOC
#define TIM2_CH1_SRF_Pin GPIO_PIN_0
#define TIM2_CH1_SRF_GPIO_Port GPIOA
#define TIM2_CH2_SRR_Pin GPIO_PIN_1
#define TIM2_CH2_SRR_GPIO_Port GPIOA
#define LPUART1_TX_Pin GPIO_PIN_2
#define LPUART1_TX_GPIO_Port GPIOA
#define LPUART1_RX_Pin GPIO_PIN_3
#define LPUART1_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define Servo1_Pin GPIO_PIN_6
#define Servo1_GPIO_Port GPIOA
#define SetRightRearForward_Pin GPIO_PIN_0
#define SetRightRearForward_GPIO_Port GPIOB
#define TIM2_CH3_SLF_Pin GPIO_PIN_10
#define TIM2_CH3_SLF_GPIO_Port GPIOB
#define SetLeftFrontForward_Pin GPIO_PIN_8
#define SetLeftFrontForward_GPIO_Port GPIOA
#define TIM2_CH4_SLR_Pin GPIO_PIN_10
#define TIM2_CH4_SLR_GPIO_Port GPIOA
#define TIM1_CH4_ECHO_Pin GPIO_PIN_11
#define TIM1_CH4_ECHO_GPIO_Port GPIOA
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
#define SetRightFrontForward_Pin GPIO_PIN_10
#define SetRightFrontForward_GPIO_Port GPIOC
#define SetRightFrontBack_Pin GPIO_PIN_11
#define SetRightFrontBack_GPIO_Port GPIOC
#define T_SWO_Pin GPIO_PIN_3
#define T_SWO_GPIO_Port GPIOB
#define SetLeftFrontBack_Pin GPIO_PIN_4
#define SetLeftFrontBack_GPIO_Port GPIOB
#define SetLeftRearForward_Pin GPIO_PIN_8
#define SetLeftRearForward_GPIO_Port GPIOB
#define SetLeftRearBack_Pin GPIO_PIN_9
#define SetLeftRearBack_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

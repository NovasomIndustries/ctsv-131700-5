/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "surgy_main.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define FLAG_Pin GPIO_PIN_7
#define FLAG_GPIO_Port GPIOB
#define POWER_ON_Pin GPIO_PIN_14
#define POWER_ON_GPIO_Port GPIOC
#define LCD_DC_Pin GPIO_PIN_15
#define LCD_DC_GPIO_Port GPIOC
#define ON_Pin GPIO_PIN_0
#define ON_GPIO_Port GPIOA
#define ON_EXTI_IRQn EXTI0_1_IRQn
#define ADC1_IN1_POWER_MONITOR_Pin GPIO_PIN_1
#define ADC1_IN1_POWER_MONITOR_GPIO_Port GPIOA
#define SPEED_PLUS_Pin GPIO_PIN_2
#define SPEED_PLUS_GPIO_Port GPIOA
#define SPEED_PLUS_EXTI_IRQn EXTI2_3_IRQn
#define ADC1_IN3_MTFEEDBACK_Pin GPIO_PIN_3
#define ADC1_IN3_MTFEEDBACK_GPIO_Port GPIOA
#define SPEED_MINUS_Pin GPIO_PIN_4
#define SPEED_MINUS_GPIO_Port GPIOA
#define SPEED_MINUS_EXTI_IRQn EXTI4_15_IRQn
#define MOTOR_TIM16_CH1_Pin GPIO_PIN_6
#define MOTOR_TIM16_CH1_GPIO_Port GPIOA
#define BKL_TIM3_CH3_Pin GPIO_PIN_0
#define BKL_TIM3_CH3_GPIO_Port GPIOB
#define LCD_RESET_Pin GPIO_PIN_11
#define LCD_RESET_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_12
#define LCD_CS_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define TOUCH_DET_4_Pin GPIO_PIN_13
#define TOUCH_DET_4_GPIO_Port GPIOC
#define TOUCH_DET_3_Pin GPIO_PIN_14
#define TOUCH_DET_3_GPIO_Port GPIOC
#define TOUCH_DET_2_Pin GPIO_PIN_15
#define TOUCH_DET_2_GPIO_Port GPIOC
#define TOUCH_DET_1_Pin GPIO_PIN_0
#define TOUCH_DET_1_GPIO_Port GPIOA
#define BODY_DET_Pin GPIO_PIN_1
#define BODY_DET_GPIO_Port GPIOA
#define LED_DOUT_Pin GPIO_PIN_3
#define LED_DOUT_GPIO_Port GPIOA
#define MUTE_EN_Pin GPIO_PIN_4
#define MUTE_EN_GPIO_Port GPIOA
#define SPK_EN1_Pin GPIO_PIN_5
#define SPK_EN1_GPIO_Port GPIOA
#define BLED_C_Pin GPIO_PIN_6
#define BLED_C_GPIO_Port GPIOA
#define RLED_C_Pin GPIO_PIN_7
#define RLED_C_GPIO_Port GPIOA
#define GLED_C_Pin GPIO_PIN_0
#define GLED_C_GPIO_Port GPIOB
#define TOUCH_DET_7_Pin GPIO_PIN_1
#define TOUCH_DET_7_GPIO_Port GPIOB
#define SPK_EN_Pin GPIO_PIN_2
#define SPK_EN_GPIO_Port GPIOB
#define SW0_Pin GPIO_PIN_10
#define SW0_GPIO_Port GPIOB
#define SW1_Pin GPIO_PIN_11
#define SW1_GPIO_Port GPIOB
#define TOUCH_DET_Pin GPIO_PIN_12
#define TOUCH_DET_GPIO_Port GPIOB
#define PWR_LED_Pin GPIO_PIN_13
#define PWR_LED_GPIO_Port GPIOB
#define TOUCH_DET_8_Pin GPIO_PIN_14
#define TOUCH_DET_8_GPIO_Port GPIOB
#define TOUCH_DET_9_Pin GPIO_PIN_15
#define TOUCH_DET_9_GPIO_Port GPIOB
#define TOUCH_DET_10_Pin GPIO_PIN_8
#define TOUCH_DET_10_GPIO_Port GPIOA
#define TOUCH_DET_11_Pin GPIO_PIN_11
#define TOUCH_DET_11_GPIO_Port GPIOA
#define TOUCH_DET_12_Pin GPIO_PIN_12
#define TOUCH_DET_12_GPIO_Port GPIOA
#define BOTTOM_LED_EN_Pin GPIO_PIN_3
#define BOTTOM_LED_EN_GPIO_Port GPIOB
#define FS_EN_Pin GPIO_PIN_4
#define FS_EN_GPIO_Port GPIOB
#define TOUCH_DET_6_Pin GPIO_PIN_8
#define TOUCH_DET_6_GPIO_Port GPIOB
#define TOUCH_DET_5_Pin GPIO_PIN_9
#define TOUCH_DET_5_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

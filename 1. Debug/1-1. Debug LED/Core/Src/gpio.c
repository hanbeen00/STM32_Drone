/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{
	//.ioc 에서 설정했던 내용들 코드로 변환 후 생성
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  //GPIO 포트 H,C 클럭 활성화
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);

  /**/
  //GPIO 핀 출력 초기화
  LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_0|LL_GPIO_PIN_1|LL_GPIO_PIN_2);

  /**/
  GPIO_InitStruct.Pin = LL_GPIO_PIN_0|LL_GPIO_PIN_1|LL_GPIO_PIN_2;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;

  //GPIO의 물리적인 전압 변화 속도
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;

  //핀의 출력 형태
  //Push-Pull은 출력이 HIGH일 때 Vcc, LOW일 때 GND에 연결되는 구조
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;

  //내부 풀업/풀다운 저항 사용 안 함 (출력 핀이므로 OK)
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

/* USER CODE BEGIN 2 */
/* USER CODE END 2 */

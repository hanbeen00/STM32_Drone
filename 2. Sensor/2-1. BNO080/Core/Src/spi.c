/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    spi.c
  * @brief   This file provides code for the configuration
  *          of the SPI instances.
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
#include "spi.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* SPI2 init function */
void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

	//LL_SPI_InitTypeDef와 LL_GPIO_InitTypeDef는 각각 SPI와 GPIO 설정 구조체
  LL_SPI_InitTypeDef SPI_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  //SPI2에 대한 클럭을 활성화, SPI2를 사용하기 전에 클럭을 활성화해야함
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);
  //GPIOB에 대한 클럭을 활성화, SPI2의 핀들이 GPIOB에 있기 때문에 이 클럭도 활성화해야함
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
  /**SPI2 GPIO Configuration
  PB13   ------> SPI2_SCK
  PB14   ------> SPI2_MISO
  PB15   ------> SPI2_MOSI
  */

  //PB13, PB14, PB15 핀을 SPI2에 사용. 이 핀들은 각각 SCK, MISO, MOSI에 해당
  //대체 기능 (Alternate Function) 모드로 설정하여, 해당 핀들이 SPI2의 SCK, MISO, MOSI로 사용될 수 있도록 설정
  //핀 속도를 **매우 빠름 (Very High)**으로 설정하여 높은 속도에서 동작할 수 있게 함
  //푸시풀 출력 (Push-Pull) 방식으로 설정하여 양방향 통신을 가능하게 함
  //풀업/풀다운 저항 없음으로 설정하여 외부 저항이 없도록 설정
  //이 핀들은 GPIO 대체 기능 5 (SPI2에 대한 설정)을 사용하도록 설정함

  GPIO_InitStruct.Pin = LL_GPIO_PIN_13|LL_GPIO_PIN_14|LL_GPIO_PIN_15;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  //전체 듀플렉스 (Full-Duplex) 모드로 설정하여 송수신을 동시에 할 수 있게 합니다.
  //SPI2를 마스터 모드로 설정합니다. 이 모드는 SPI 버스를 제어하는 역할을 합니다.
  //8비트 데이터를 전송하도록 설정합니다.
  //**클럭 극성 (Clock Polarity)**을 HIGH로 설정하여 클럭 신호가 로우에서 하이로 변할 때 데이터가 유효한 방식입니다.
  //**클럭 위상 (Clock Phase)**을 2엣지로 설정하여 클럭 신호의 두 번째 엣지에서 데이터를 샘플링합니다.
  //소프트웨어 NSS 모드로 설정하여 Chip Select 신호를 소프트웨어로 관리합니다.
  //SPI Baud Rate를 16으로 분주 (DIV16) 하여 통신 속도를 설정합니다.
  //**MSB (Most Significant Bit)**가 먼저 전송되도록 설정합니다.
  //CRC 계산을 비활성화합니다. 오류 검출을 위해 CRC를 사용할 수 있지만, 여기서는 사용하지 않도록 설정합니다.
  //CRC 다항식을 10으로 설정하지만, CRC를 사용하지 않으므로 영향이 없습니다.

  SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
  SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
  SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
  SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_HIGH;
  SPI_InitStruct.ClockPhase = LL_SPI_PHASE_2EDGE;
  SPI_InitStruct.NSS = LL_SPI_NSS_SOFT;
  SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV16;
  SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
  SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
  SPI_InitStruct.CRCPoly = 10;
  LL_SPI_Init(SPI2, &SPI_InitStruct);

  //Motorola 프로토콜은 일반적으로 클럭 극성과 클럭 위상에 따라 데이터를 전송하는 방식
  LL_SPI_SetStandard(SPI2, LL_SPI_PROTOCOL_MOTOROLA);
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

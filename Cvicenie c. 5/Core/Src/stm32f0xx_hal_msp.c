/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : stm32f0xx_hal_msp.c
  * Description        : This file provides code for the MSP Initialization 
  *                      and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
extern DMA_HandleTypeDef hdma_usart2_rx;

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */
 
/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
<<<<<<< HEAD
<<<<<<< HEAD
* @brief UART MSP Initialization
* This function configures the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(huart->Instance==USART2)
=======
=======
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
* @brief USART MSP Initialization
* This function configures the hardware resources used in this example
* @param husart: USART handle pointer
* @retval None
*/
void HAL_USART_MspInit(USART_HandleTypeDef* husart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(husart->Instance==USART2)
<<<<<<< HEAD
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
=======
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration    
    PA2     ------> USART2_TX
<<<<<<< HEAD
<<<<<<< HEAD
    PA3     ------> USART2_RX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
=======
=======
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
    PA3     ------> USART2_RX
    PA4     ------> USART2_CK 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;
<<<<<<< HEAD
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
=======
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF1_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 DMA Init */
    /* USART2_RX Init */
    hdma_usart2_rx.Instance = DMA1_Channel5;
    hdma_usart2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_rx.Init.Mode = DMA_NORMAL;
    hdma_usart2_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_usart2_rx) != HAL_OK)
    {
      Error_Handler();
    }

<<<<<<< HEAD
<<<<<<< HEAD
    __HAL_LINKDMA(huart,hdmarx,hdma_usart2_rx);
=======
    __HAL_LINKDMA(husart,hdmarx,hdma_usart2_rx);
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
=======
    __HAL_LINKDMA(husart,hdmarx,hdma_usart2_rx);
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e

  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }

}

/**
<<<<<<< HEAD
<<<<<<< HEAD
* @brief UART MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
  if(huart->Instance==USART2)
=======
=======
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
* @brief USART MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param husart: USART handle pointer
* @retval None
*/
void HAL_USART_MspDeInit(USART_HandleTypeDef* husart)
{
  if(husart->Instance==USART2)
<<<<<<< HEAD
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
=======
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();
  
    /**USART2 GPIO Configuration    
    PA2     ------> USART2_TX
<<<<<<< HEAD
<<<<<<< HEAD
    PA3     ------> USART2_RX 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* USART2 DMA DeInit */
    HAL_DMA_DeInit(huart->hdmarx);
=======
=======
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
    PA3     ------> USART2_RX
    PA4     ------> USART2_CK 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);

    /* USART2 DMA DeInit */
    HAL_DMA_DeInit(husart->hdmarx);
<<<<<<< HEAD
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
=======
>>>>>>> 04b5605d44fdb554e5a9673c8170875716a55c9e
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

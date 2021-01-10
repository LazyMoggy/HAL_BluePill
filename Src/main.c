/**
  ****************************************************************************
  * @file    main.c
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Main File - Blinky
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */

#include "hal.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#include "stm32f10x.h"

#define LED_ON() 	GPIO_ResetBits(GPIOC, GPIO_Pin_13)
#define LED_OFF()	GPIO_SetBits(GPIOC, GPIO_Pin_13)


int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	HAL_Init();

	for(;;)
	{
		HAL_IOSet(LED, HIO_LOW);
		//LED_ON();
		HAL_DelayS(1);
		HAL_IOSet(LED, HIO_HIGH);
	    //LED_OFF();
		HAL_DelayS(1);
	}
}


// EOF ************************************************************************

/**
  ****************************************************************************
  * @file    dev_gpio.h (STM32F103C8T6)
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Device Clock Driver - Header
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */


#ifndef DEV_GPIO_H
#define DEV_GPIO_H

#include "stm32f10x.h"

typedef enum
{
	PC13
}gpioChanIdx_t;

typedef enum
{
	IO_OUT,
	IO_IN
}gpioConfigIdx_t;

typedef enum
{
	GPIO_LOW,
	GPIO_HIGH
}gpioLvl_t;

typedef struct
{
	gpioChanIdx_t ch;
	gpioConfigIdx_t conf;
}defaultIoConf_t;

void InitGpio(gpioChanIdx_t chIdx, gpioConfigIdx_t confIdx);
void SetGpio(gpioChanIdx_t chIdx, gpioLvl_t);
gpioLvl_t GetGpio(gpioChanIdx_t chIdx);

#endif


// EOF ************************************************************************

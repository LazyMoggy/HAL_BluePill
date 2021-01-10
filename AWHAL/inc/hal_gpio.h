/**
  ****************************************************************************
  * @file    hal_gpio.h
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Micro-controller Hardware Abstraction Layer - GPIO
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */

#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <dev_gpio.h>

/* Add Level alias here */
#define HIO_LOW 	GPIO_LOW
#define HIO_HIGH	GPIO_HIGH

/* Add IO alias here */
#define LED 		PC13

/* Add Mode alias here */
#define HIO_OUT 	IO_OUT
#define HIO_IN		IO_IN

/* HAL Fn's */
#define HAL_IOSet(ch, lvl)			SetGpio(ch, lvl);
#define HAL_IOGet(ch) 	   			GetGpio(ch);
#define HAL_IOModeSet(ch, mode)		InitGpio(ch, mode);


void HAL_InitGpio(void);

#endif


// EOF ************************************************************************

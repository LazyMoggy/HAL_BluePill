/**
  ****************************************************************************
  * @file    hal.h
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Micro-controller Hardware Abstraction Layer
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */

#ifndef AWHAL_H
#define AWHAL_H

/* Commend out USE defines if HAL Function not wanted */

#define USE_HAL_CLK
#define USE_HAL_GPIO
// #define USE_HAL_SPI
// #define USE_HAL_I2C
// #define USE_HAL_ADC
// #define USE_HAL_DAC

/* Conditional includes for HAL Functions */

#ifdef USE_HAL_CLK
#include "hal_clk.h"
#endif

#ifdef USE_HAL_GPIO
#include "hal_gpio.h"
#endif

void HAL_Init(void);


#endif


// EOF ************************************************************************

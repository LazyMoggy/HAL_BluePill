/**
  ****************************************************************************
  * @file    hal.c
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Micro-controller Hardware Abstraction Layer
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */

#include <hal.h>

void HAL_Init()
{
#ifdef USE_HAL_CLK
	HAL_InitClks();
#endif

#ifdef USE_HAL_GPIO
	HAL_InitGpio();
#endif
}

// EOF ************************************************************************

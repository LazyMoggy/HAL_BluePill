/**
  ****************************************************************************
  * @file    hal_clk.c
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Micro-controller Hardware Abstraction Layer - Clocks
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */

#include <hal_clk.h>

static volatile uint32_t DelayCounter;

void HAL_InitClks(void)
{
	HAL_SysClkInit();
	HAL_UsTickInit();
}

void HAL_UsTick()
{
	if(DelayCounter)
	{
		DelayCounter--;
	}
}

void HAL_DelayUs(uint32_t us)
{
	HAL_UsTickEn(1);
	DelayCounter = us;
	while(DelayCounter);
	HAL_UsTickEn(0);
	return;
}

void HAL_DelayMs(uint32_t ms)
{
	HAL_DelayUs(ms*1000);
}

void HAL_DelayS(uint32_t s)
{
	HAL_DelayMs(s*1000);
}

// EOF ************************************************************************


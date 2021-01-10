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


#ifndef HAL_CLK_H
#define HAL_CLK_H

#include <dev_clocks.h>
#include <stdint.h>

/* HAL Function Defines - Links HAL fn's to device fn's */
#define HAL_SysClkInit() InitSysOsc()
#define HAL_UsTickInit() InitSysTick()
#define HAL_UsTickEn(en) SysTickEn(en)
#define HAL_UsTick() SysTick_Handler()


/* Function Prototypes */
void HAL_InitClks(void);
/* HAL Delay Function */
void HAL_DelayUs(uint32_t us);
void HAL_DelayMs(uint32_t ms);
void HAL_DelayS(uint32_t s);

#endif

// EOF ************************************************************************


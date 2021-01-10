/**
  ****************************************************************************
  * @file    dev_clocks.h (STM32F103C8T6)
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Device Clock Driver - Header
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */


#ifndef DEV_CLOCKS_H
#define DEV_CLOCKS_H

#include <stdbool.h>

void InitSysOsc(void);
void InitSysTick(void);
void SysTickEn(bool en);

#endif

// EOF ************************************************************************

/**
  ****************************************************************************
  * @file    hal_gpio.c
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Micro-controller Hardware Abstraction Layer - GPIO
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */

#include "hal_gpio.h"
#include "macros.h"

typedef struct
{
	uint32_t chan;
	uint32_t mode;
}HIO_Default_t;

/*static const HIO_Default_t HIO_Defaults[] =
{
		{LED, HIO_OUT}
};*/

void HAL_InitGpio(void)
{
/*	for(uint32_t idx; idx<ARYLEN(HIO_Defaults); idx++)
	{
		HIO_Default_t conf = HIO_Defaults[idx];
		InitGpio(conf.chan, conf.mode);
	}*/

	HAL_IOModeSet(LED, HIO_OUT);

	return;
}

// EOF ************************************************************************

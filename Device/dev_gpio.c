/**
  ****************************************************************************
  * @file    dev_gpio.c (STM32F103C8T6)
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Device GPIO Driver
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */

#include "dev_gpio.h"
#include "stm32f10x.h"
#include "macros.h"

#define GPIO_Pin_0                 ((uint16_t)0x0001)  /*!< Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0002)  /*!< Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0004)  /*!< Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0008)  /*!< Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0010)  /*!< Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0020)  /*!< Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0040)  /*!< Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /*!< Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /*!< Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /*!< Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /*!< Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /*!< Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /*!< Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /*!< Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /*!< Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /*!< Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /*!< All pins selected */

typedef enum
{ GPIO_Mode_AIN = 0x0,
  GPIO_Mode_IN_FLOATING = 0x04,
  GPIO_Mode_IPD = 0x28,
  GPIO_Mode_IPU = 0x48,
  GPIO_Mode_Out_OD = 0x14,
  GPIO_Mode_Out_PP = 0x10,
  GPIO_Mode_AF_OD = 0x1C,
  GPIO_Mode_AF_PP = 0x18
}gpioMode_t;

typedef enum
{
	GPIO_Speed_Input = 0x0,
	GPIO_Speed_10MHz = 0x1,
	GPIO_Speed_2MHz  = 0x2,
	GPIO_Speed_50MHz = 0x3

}gpioSpeed_t;

typedef struct
{
	GPIO_TypeDef * GPIOx;
	uint16_t GPIO_Pin;
}gpioChan_t;

typedef struct
{
	uint8_t gpioMode;
	uint8_t gpioSpeed;
	uint8_t gpioLvl_t;
}gpioConfig_t;


static const gpioChan_t gpioChannels[] =
{
		{GPIOC, GPIO_Pin_13}
};

static const gpioConfig_t gpioConfigs[] =
{
		{GPIO_Mode_Out_PP, 	    GPIO_Speed_50MHz, GPIO_LOW}, 	//0
		{GPIO_Mode_IN_FLOATING,	GPIO_Speed_Input, GPIO_LOW} 	//1
};

void InitGpio(gpioChanIdx_t chIdx, gpioConfigIdx_t confIdx)
{
	volatile uint32_t *pCrx;

	gpioConfig_t conf = gpioConfigs[confIdx];
	gpioChan_t ch = gpioChannels[chIdx];
	uint16_t gpioShifted;

	if((ch.GPIO_Pin & ((uint32_t)0x00FF)) != 0x00)
	{
		pCrx = &(ch.GPIOx->CRL);
		gpioShifted = ch.GPIO_Pin;
	}
	else
	{
		pCrx = &(ch.GPIOx->CRH);
		gpioShifted = ch.GPIO_Pin >> 8;
	}

	uint8_t crxIdx = 0;
	for(uint8_t gpioIdx = 0; gpioIdx<8; gpioIdx++)
	{
		if(gpioShifted & (1u<<gpioIdx))
		{
			break;
		}
		crxIdx +=4;
	}

	uint8_t setVal = (((conf.gpioMode & 0x0F) | conf.gpioSpeed) & 0xF);
	SETBITS(*pCrx, crxIdx, 0xF, setVal);


}

void SetGpio(gpioChanIdx_t chIdx, gpioLvl_t lvl)
{
	gpioChan_t ch = gpioChannels[chIdx];
	ch.GPIOx->BSRR = ch.GPIO_Pin << (16U*(lvl == GPIO_HIGH));
}

gpioLvl_t GetGpio(gpioChanIdx_t chIdx)
{
	gpioChan_t ch = gpioChannels[chIdx];
	return (gpioLvl_t) GETBIT(ch.GPIOx->IDR, ch.GPIO_Pin);

}

// EOF ************************************************************************

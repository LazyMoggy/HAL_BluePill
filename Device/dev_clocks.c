/**
  ****************************************************************************
  * @file    dev_clocks.c (STM32F103C8T6)
  * @author  AW
  * @version V1.0
  * @date    23 DEC 2020
  * @brief   Device Clock Driver
  * @section COPYRIGHT (C) Andrew West 2020 - All Rights Reserved
  ****************************************************************************
  */

#include <macros.h>
#include "dev_clocks.h"
#include "stm32f10x.h"

void InitSysOsc(void)
{

	RCC->CR |= (1 << 16);            // Enable HSE
	while(!(RCC->CR & (1 << 17)));   // Wait till HSE ready

	RCC->CFGR |= 1;                  // Swich to HSE temporarly
	RCC->CR   &= ~1;				 // Disable HSI

	RCC->CFGR |= (0b111 << 18);      // Set PLL multiplication to 9
	RCC->CFGR |= (1 << 16);          // HSE as PLL->SRC

	FLASH->ACR = 0b10010;            // Enable flash prefetch
	while(!(FLASH->ACR & (1 << 5)));  // Wait for prefetch enable

	RCC->CR |= (1 << 24);            // Enable PLL
	while(!(RCC->CR & (1 << 25)));   // Wait till PLL ready

	RCC->CFGR = (RCC->CFGR | 0b10) & ~1; // Set PLL as Clock source
	while(!(RCC->CFGR & (1 << 3)));  // Wait till PLL is CLK SRC

	SystemCoreClockUpdate();

	return;
}

void InitSysTick(void)
{
	SysTick_Config(SystemCoreClock / 1000000);
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
	return;
}

void SysTickEn(bool en)
{
	SETBIT(SysTick->CTRL, SysTick_CTRL_ENABLE_Pos, en);
	return;
}


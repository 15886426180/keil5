#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define LED1_TOGGLE			GPIOE->BSRR^=GPIO_Pin_5			//状态反转
#define LED1_OFF							GPIO_SetBits(GPIOE,GPIO_Pin_5)
#define LED1_ON							GPIO_ResetBits(GPIOE,GPIO_Pin_5)

#define LED2_TOGGLE			GPIOB->BSRR^=GPIO_Pin_5			//状态反转
#define LED2_OFF							GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define LED2_ON							GPIO_ResetBits(GPIOB,GPIO_Pin_5)

#endif 


#ifndef __BELL_H
#define __BELL_H
#include "stm32f10x.h"

#define BEEP_ON GPIO_SetBits(GPIOB,GPIO_Pin_8)
#define BEEP_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_8)
#define BEEP_TOGGLE GPIOB->ODR^=GPIO_Pin_8

#endif



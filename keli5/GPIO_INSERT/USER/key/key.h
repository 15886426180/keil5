#ifndef __KEY_H
#define __KEY_H
#include "stm32f10x.h"

#define KEY_DN 0
#define KEY_UP 1
#define KEY0_STA GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define KEY1_STA GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)


#endif


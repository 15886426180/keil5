

#include "key.h"
#include "bell.h"
#include "led.h"



void Bell_Cfg(void)
{
GPIO_InitTypeDef bell_gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	//蜂鸣器I/O配置
	bell_gpio.GPIO_Pin=GPIO_Pin_8;
	bell_gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	bell_gpio.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&bell_gpio);
	//配置完成后关闭蜂鸣器
	BEEP_OFF;
}


void Key_Cfg(void)
{
	GPIO_InitTypeDef key_gpio;
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
//案件I/O配置
key_gpio.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4;
key_gpio.GPIO_Mode=GPIO_Mode_IPU;		//上拉输入
	GPIO_Init(GPIOE,&key_gpio);
}




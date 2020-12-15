#include "led.h"   
void LED_Cfg(void)
{
    GPIO_InitTypeDef led_gpio;
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  // 使能端口B的时钟 
	
	
		led_gpio.GPIO_Pin   = GPIO_Pin_13;	
    led_gpio.GPIO_Mode  = GPIO_Mode_Out_PP;     // 通用推挽输出
    led_gpio.GPIO_Speed = GPIO_Speed_2MHz;      // 2MHz
    GPIO_Init(GPIOB, &led_gpio);
	


}


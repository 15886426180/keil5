#include "led.h"
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
/**************************************************************************
函数功能：LED接口初始化
入口参数：无 
返回  值：无
**************************************************************************/
void LED_Init(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		//使能端口时钟 GPIO B
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
		//端口配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	
		//推挽输出
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		//50Hz
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		//初始化
		GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/**************************************************************************
函数功能：LED闪烁
入口参数：闪烁频率 
返回  值：无
**************************************************************************/
void Led_Flash(u16 time)
{
	  static int temp;
	  if(0 == time) 
		{
			LED = 0;
		}
	  else if(++temp == time)
		{
			LED =~ LED;
			temp = 0;
		}
}

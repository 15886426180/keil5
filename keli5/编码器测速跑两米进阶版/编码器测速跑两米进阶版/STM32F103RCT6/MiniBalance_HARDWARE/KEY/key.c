#include "key.h"
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
/**************************************************************************
函数功能：按键初始化
入口参数：无
返回  值：无 
**************************************************************************/
void KEY_Init(void)
{
		
		GPIO_InitTypeDef GPIO_InitStructure;
	
		//使能端口时钟GPIO B
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
		
		//端口配置
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
		//上拉输入
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         
		//初始化
		GPIO_Init(GPIOB, &GPIO_InitStructure);					      
} 


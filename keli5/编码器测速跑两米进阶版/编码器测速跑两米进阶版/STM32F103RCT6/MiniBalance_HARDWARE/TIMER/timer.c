#include "timer.h"
/**
  * @brief  基本定时器TIM6作为计数模式初始化
  * @param  prescaler 	   时钟预分频
  *		    period	       定时器重装载寄存器的值(arr)
  *		    定时器定时频率:系统时钟频率/预分频/重装载值
  * @retval None
  */
	

	
void TIM6_CounterMode(void)
{
	NVIC_InitTypeDef           NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   
	/* 配置时基结构体 */
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	//使能定时器时钟
  
	TIM_TimeBaseStructure.TIM_Prescaler = 100-1;  //溢出时间10ms
	//配置定时器时钟分频
	TIM_TimeBaseStructure.TIM_Period = 7200-1;         
	//配置自动重装载寄存器的值
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
	//初始化TIM6时间基数单位

	TIM_ClearFlag(TIM6, TIM_FLAG_Update);
	//清除更新中断，防止一打开中断立马产生中断
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
	//打开定时器更新中断

	NVIC_InitStructure.NVIC_IRQChannel=TIM6_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM6, ENABLE);
	//使能定时器
}




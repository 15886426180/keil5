#include "motor.h"
void MiniBalance_PWM_Init(u16 arr,u16 psc)
{		 		
		GPIO_InitTypeDef GPIO_InitStructure;
		TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;
		
		//使能TIM8外设时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
		//使能GPIO C
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);  
		
		//TIM_CH1 -> TIM_CH4
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
		//复用推挽输出
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		//设置频率50Hz
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		//初始化GPIO_InitStructure
		GPIO_Init(GPIOC, &GPIO_InitStructure);
		
		//设置在下一个更新事件装入活动的自动重装载寄存器周期的值
		TIM_TimeBaseStructure.TIM_Period = arr;
		//设置用来作为TIMx时钟频率除数的预分频值  不分频		
		TIM_TimeBaseStructure.TIM_Prescaler = psc;
		//设置时钟分割:TDTS = Tck_tim
		TIM_TimeBaseStructure.TIM_ClockDivision = 0;
		//TIM向上计数模式
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		//根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
		TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure); 
		
		//选择定时器模式:TIM脉冲宽度调制模式1
		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
		//比较输出使能
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		//设置待装入捕获比较寄存器的脉冲值
		TIM_OCInitStructure.TIM_Pulse = 0;
		//输出极性:TIM输出比较极性高
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     
		
		TIM_OC1Init(TIM8, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
		TIM_OC2Init(TIM8, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
		TIM_OC3Init(TIM8, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
		TIM_OC4Init(TIM8, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
		
		TIM_CtrlPWMOutputs(TIM8,ENABLE);	  //MOE 主输出使能	

		TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);  //CH1预装载使能	
		TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable);  //CH1预装载使能	
		TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);  //CH1预装载使能		
		TIM_OC4PreloadConfig(TIM8, TIM_OCPreload_Enable);  //CH4预装载使能	 
		
		TIM_ARRPreloadConfig(TIM8, ENABLE); //使能TIMx在ARR上的预装载寄存器
		
		TIM_Cmd(TIM8, ENABLE);  //使能TIM
 
} 

/**************************************************************************
函数功能：赋值给PWM寄存器
入口参数：PWM
返回  值：无
**************************************************************************/
void Set_Pwm(int motor_a, int motor_b)
{
	  	if(motor_a > 0)
			{
					PWMA1 = 7200;
					PWMA2 = 7200 - motor_a;
			}
			else
			{
					PWMA2 = 7200;
					PWMA1 = 7200 + motor_a;
			}	
		  if(motor_b > 0)
			{				
					PWMB1 = 7200;
					PWMB2 = 7200 - motor_b;
			}
			else
			{				
					PWMB2 = 7200;
					PWMB1 = 7200 + motor_b;
			}
}


/**************************************************************************
函数功能：限制PWM赋值 
入口参数：幅值
返回  值：无
**************************************************************************/
void Xianfu_Pwm(int amplitude)
{	
		//限制最小值
               if(Motor_Left < -amplitude)
		{
				Motor_Left = -amplitude;	
		}
		
		//限制最大值
		if(Motor_Left > amplitude)
		{
				Motor_Left = amplitude;	  
	        }
		
		//限制最小值	
		if(Motor_Right < -amplitude)
		{
				Motor_Right = -amplitude;
		}
		
		//限制最大值
		if(Motor_Right > amplitude)
		{
				Motor_Right = amplitude;			
		}
}



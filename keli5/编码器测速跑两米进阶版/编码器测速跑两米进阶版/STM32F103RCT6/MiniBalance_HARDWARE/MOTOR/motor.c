#include "motor.h"
  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/
**************************************************************************/

void MiniBalance_PWM_Init(u16 arr,u16 psc)
{		 		
		GPIO_InitTypeDef GPIO_InitStructure;
		TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;
		
		//ʹ��TIM8����ʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
		//ʹ��GPIO C
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);  
		
		//TIM_CH1 -> TIM_CH4
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7
																	|GPIO_Pin_8|GPIO_Pin_9;
		//�����������
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		//����Ƶ��50Hz
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		//��ʼ��GPIO_InitStructure
		GPIO_Init(GPIOC, &GPIO_InitStructure);
		
		//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
		TIM_TimeBaseStructure.TIM_Period = arr;
		//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ		
		TIM_TimeBaseStructure.TIM_Prescaler = psc;
		//����ʱ�ӷָ�:TDTS = Tck_tim
		TIM_TimeBaseStructure.TIM_ClockDivision = 0;
		//TIM���ϼ���ģʽ
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		//����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
		TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure); 
		
		//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
		//�Ƚ����ʹ��
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		//���ô�װ�벶��ȽϼĴ���������ֵ
		TIM_OCInitStructure.TIM_Pulse = 0;
		//�������:TIM����Ƚϼ��Ը�
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     
		
		TIM_OC1Init(TIM8, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
		TIM_OC2Init(TIM8, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
		TIM_OC3Init(TIM8, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
		TIM_OC4Init(TIM8, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
		
		TIM_CtrlPWMOutputs(TIM8,ENABLE);	//MOE �����ʹ��	

		TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��	
		TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��	
		TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��		
		TIM_OC4PreloadConfig(TIM8, TIM_OCPreload_Enable);  //CH4Ԥװ��ʹ��	 
		
		TIM_ARRPreloadConfig(TIM8, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
		
		TIM_Cmd(TIM8, ENABLE);  //ʹ��TIM
 
} 

/**************************************************************************
�������ܣ���ֵ��PWM�Ĵ���
��ڲ�����PWM
����  ֵ����
**************************************************************************/
void Set_Pwm(int motor_a,int motor_b)
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
		  if(motor_b>0)
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
�������ܣ�����PWM��ֵ 
��ڲ�������ֵ
����  ֵ����
**************************************************************************/
void Xianfu_Pwm(int amplitude)
{	
		//������Сֵ
    if(Motor_Left < -amplitude)
		{
			Motor_Left = -amplitude;	
		}
		
		//�������ֵ
		if(Motor_Left > amplitude)
		{
			Motor_Left = amplitude;	  
	  }
		
		//������Сֵ	
		if(Motor_Right < -amplitude)
		{
			Motor_Right = -amplitude;
		}
		
		//�������ֵ
		if(Motor_Right > amplitude)
		{
			Motor_Right = amplitude;			
		}
}


void Servo_PWM_Init(u16 arr,u16 psc)	
{	 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);// 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);  //ʹ��GPIO����ʱ��ʹ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; // TIM1_CH1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;                            //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //�������:TIM����Ƚϼ��Ը�
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
  TIM_CtrlPWMOutputs(TIM1,ENABLE);	//MOE �����ʹ��	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH4Ԥװ��ʹ��	 	
	TIM_ARRPreloadConfig(TIM1, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���	
	TIM_Cmd(TIM1, ENABLE);  //ʹ��TIM	
}


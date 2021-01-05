#include "timer.h"
/**
  * @brief  ������ʱ��TIM6��Ϊ����ģʽ��ʼ��
  * @param  prescaler 	   ʱ��Ԥ��Ƶ
  *		    period	       ��ʱ����װ�ؼĴ�����ֵ(arr)
  *		    ��ʱ����ʱƵ��:ϵͳʱ��Ƶ��/Ԥ��Ƶ/��װ��ֵ
  * @retval None
  */
	

	
void TIM6_CounterMode(void)
{
	NVIC_InitTypeDef           NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   
	/* ����ʱ���ṹ�� */
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	//ʹ�ܶ�ʱ��ʱ��
  
	TIM_TimeBaseStructure.TIM_Prescaler = 100-1;  //���ʱ��10ms
	//���ö�ʱ��ʱ�ӷ�Ƶ
	TIM_TimeBaseStructure.TIM_Period = 7200-1;         
	//�����Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
	//��ʼ��TIM6ʱ�������λ

	TIM_ClearFlag(TIM6, TIM_FLAG_Update);
	//��������жϣ���ֹһ���ж���������ж�
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
	//�򿪶�ʱ�������ж�

	NVIC_InitStructure.NVIC_IRQChannel=TIM6_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM6, ENABLE);
	//ʹ�ܶ�ʱ��
}




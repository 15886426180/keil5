#include "key.h"
  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/
**************************************************************************/
/**************************************************************************
�������ܣ�������ʼ��
��ڲ�������
����  ֵ���� 
**************************************************************************/
void KEY_Init(void)
{
		
		GPIO_InitTypeDef GPIO_InitStructure;
	
		//ʹ�ܶ˿�ʱ��GPIO B
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
		
		//�˿�����
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
		//��������
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         
		//��ʼ��
		GPIO_Init(GPIOB, &GPIO_InitStructure);					      
} 


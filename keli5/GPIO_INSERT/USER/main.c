
	#include "key.h"
	#include "bell.h"
	#include "led.h"
	#include "bell.h"		//BEEP
	#include "misc.h"

	#include "stm32f10x.h"

	void LED_Cfg(void);

	void Delay_ms(uint16_t u16_Time_ms);

	void Key_Cfg(void);

//	void Bell_Cfg(void);

void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);




	int main(void)
	{

	 SystemInit();
		LED_Cfg();    	 //�����Ӻ���ʵ��GPIO�ĳ�ʼ��
//	 Bell_Cfg();
	Key_Cfg();
	 
	while(1)
	{

		 LED1_ON;
				Delay_ms(1000);
		LED1_OFF;
			 Delay_ms(1000);
//		
//	//	����Key1��Key3
//		if((KEY0_STA== KEY_DN)||(KEY1_STA== KEY_DN))
//			//����Ƿ��а�������
//		{
//		Delay_ms(1);
//			
//			if(KEY0_STA== KEY_DN)
//			{
//			while (KEY0_STA==KEY_DN);
//				LED1_ON;
//				if (KEY0_STA==KEY_DN)
//			{
//				LED1_TOGGLE;
////				BEEP_TOGGLE;
//			}
//			if (KEY0_STA==KEY_DN)
//			{
//				LED1_TOGGLE;
////				BEEP_OFF;
//			}
//			}
//			
//			else if(KEY1_STA==KEY_DN)
//			{
//				while (KEY0_STA==KEY_DN);
//					LED1_ON;
//				if (KEY1_STA==KEY_DN)
//			{
//				LED2_TOGGLE;
////				BEEP_TOGGLE;
//			}
//			if (KEY0_STA==KEY_UP)
//			{
//				LED1_TOGGLE;
////				BEEP_OFF;
//			}
//			}		
//		}

			//�ж�
		
		
		
			}
		}




	void Delay_ms(uint16_t u16_Time_ms)
	{
	uint16_t i,j;
	for (i=0;i<u16_Time_ms;i++)
	{
	for (j=0;j<8192;j++);
	}
	}
























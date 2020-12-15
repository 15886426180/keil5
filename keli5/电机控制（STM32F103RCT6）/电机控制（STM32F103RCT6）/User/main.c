#include "stm32f10x.h"
#include "sys.h"


//���PWM����
long int Motor_Left = 0;
long int Motor_Right = 0;
//��ѹ����
int times = 0;	                      

int main(void)
{		
		//=====��ʼ��PWM 10KHZ������������� 
		MiniBalance_PWM_Init(7199,0);
	
		// ������ʼ������
		KEY_Init();
		
		Xianfu_Pwm(7000);
		while(1)
		{
			//����Ƿ��а�������
			if (KEY==0)                    
			{
				times++;
				//�������ֵ����ת	
				if (KEY == KEY_DN && times == 1)  
				{	 
						//�ȴ������ͷ�
						while(KEY == KEY_DN)         
						Motor_Left = -2000;
						Motor_Right = 0;        
				}				
				
				//���������ֵ����ת
				else if(KEY == KEY_DN && times == 2)
				{
						while(KEY == KEY_DN)
						Motor_Left = -2000;
						Motor_Right = -2000;          
				}
					
				//���������ֵ����ת
				else if(KEY == KEY_DN && times == 3)
				{
						while (KEY == KEY_DN)
						Motor_Left = 2000;
						Motor_Right = 2000;
				}                             
			
				//���������ֵ��ֹͣ
				else if(KEY == KEY_DN && times == 4)
				{
						while (KEY == KEY_DN)
						Motor_Left = 0;
						Motor_Right = 0;
						times = 0;
				}				                      
		}
		//���PWM��ֵ
		Set_Pwm(Motor_Left,Motor_Right);
	}
}
 
 
	

	
	

	
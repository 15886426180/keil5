#include "stm32f10x.h"
#include "sys.h"

#define SERVO_INIT 1500

//���PWM����
long int Motor_Left = 0;
long int Motor_Right = 0;

//���������������
int Encoder_Left = 0;
int Encoder_Right = 0;
                      

int main(void)
{		
	  //=====��SWD�ӿ� �������������SWD�ӿڵ��ԣ��򿪺���ܶ�ȡTIM2��Ӧ�ı�������ֵ
	  JTAG_Set(SWD_ENABLE);
		//=====��ʼ��PWM 10KHZ������������� 
		MiniBalance_PWM_Init(7199,0);
	 
	  //=====TIM2�������ӿ�
	  Encoder_Init_TIM2();            
	  //=====TIM4�������ӿ�
		Encoder_Init_TIM4();         
	
		// ������ʼ������
		KEY_Init();
	  
	  //��ʼ��PWM50HZ(20ms)�������
	  Servo_PWM_Init(19999,71);
	  
		while(1)
		{		
			//����Ƿ��а�������
			if (KEY == 0)                    
			{
				//�������ֵ����ת	
				if (KEY == KEY_DN)  
				{	 
						//�ȴ������ͷ�
						while(KEY == KEY_DN)
						{							
							Motor_Left = -2500;
							Motor_Right = -2500; 
							TIM1->CCR1= SERVO_INIT ;//���ƶ���ص��м�λ��					
            }							
				}				 
		  }
		//���PWM��ֵ
		Set_Pwm(Motor_Left,Motor_Right);

		//��ȡ��������ֵ
		Encoder_Left = Read_Encoder(2);
		Encoder_Right = -Read_Encoder(4);
		
		//�����׺��ٶ�Ϊ0 һȦ390������
		if(Encoder_Left == 15600)
		{ 
				Motor_Left = 0;
				Motor_Right = 0;
				Set_Pwm(Motor_Left,Motor_Right);
		}		
			
	}
}
 
 
	

	
	

	
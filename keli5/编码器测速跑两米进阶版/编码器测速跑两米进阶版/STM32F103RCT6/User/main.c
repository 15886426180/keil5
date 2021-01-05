#include "stm32f10x.h"
#include "sys.h"

#define SERVO_INIT 1500

//电机PWM变量
long int Motor_Left = 0;
long int Motor_Right = 0;

//编码器的脉冲计数
int Encoder_Left = 0;
int Encoder_Right = 0;
                      

int main(void)
{		
	  //=====打开SWD接口 可以利用主板的SWD接口调试，打开后才能读取TIM2对应的编码器数值
	  JTAG_Set(SWD_ENABLE);
		//=====初始化PWM 10KHZ，用于驱动电机 
		MiniBalance_PWM_Init(7199,0);
	 
	  //=====TIM2编码器接口
	  Encoder_Init_TIM2();            
	  //=====TIM4编码器接口
		Encoder_Init_TIM4();         
	
		// 按键初始化配置
		KEY_Init();
	  
	  //初始化PWM50HZ(20ms)驱动舵机
	  Servo_PWM_Init(19999,71);
	  
		while(1)
		{		
			//检测是否有按键按下
			if (KEY == 0)                    
			{
				//控制左轮电机正转	
				if (KEY == KEY_DN)  
				{	 
						//等待按键释放
						while(KEY == KEY_DN)
						{							
							Motor_Left = -2500;
							Motor_Right = -2500; 
							TIM1->CCR1= SERVO_INIT ;//控制舵机回到中间位置					
            }							
				}				 
		  }
		//电机PWM赋值
		Set_Pwm(Motor_Left,Motor_Right);

		//读取编码器数值
		Encoder_Left = Read_Encoder(2);
		Encoder_Right = -Read_Encoder(4);
		
		//跑两米后，速度为0 一圈390个脉冲
		if(Encoder_Left == 15600)
		{ 
				Motor_Left = 0;
				Motor_Right = 0;
				Set_Pwm(Motor_Left,Motor_Right);
		}		
			
	}
}
 
 
	

	
	

	
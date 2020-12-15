#include "stm32f10x.h"
#include "sys.h"

//电机PWM变量
long int Motor_Left = 0;
long int Motor_Right = 0;
//按压次数
int times = 0;	                      

int main(void)
{		
		//=====初始化PWM 10KHZ，用于驱动电机 
		MiniBalance_PWM_Init(7199,0);
	
		// 按键初始化配置
		KEY_Init();
		
		Xianfu_Pwm(7000);
		while(1)
		{
			//检测是否有按键按下
			if (KEY==0)                    
			{
				times++;
				//控制左轮电机正转	
				if (KEY == KEY_DN && times == 1)  
				{	 
						//等待按键释放
						while(KEY == KEY_DN)         
						Motor_Left = -2000;
						Motor_Right = 0;        
				}				
				
				//控制左右轮电机正转
				else if(KEY == KEY_DN && times == 2)
				{
						while(KEY == KEY_DN)
						Motor_Left = -2000;
						Motor_Right = -2000;          
				}
					
				//控制左右轮电机反转
				else if(KEY == KEY_DN && times == 3)
				{
						while (KEY == KEY_DN)
						Motor_Left = 2000;
						Motor_Right = 2000;
				}                             
			
				//控制左右轮电机停止
				else if(KEY == KEY_DN && times == 4)
				{
						while (KEY == KEY_DN)
						Motor_Left = 0;
						Motor_Right = 0;
						times = 0;
				}				                      
		}
		//电机PWM赋值
		Set_Pwm(Motor_Left,Motor_Right);
	}
}
 
 
	

	
	

	

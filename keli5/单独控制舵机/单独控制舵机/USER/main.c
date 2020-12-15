#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"


#define SERVO_INIT 1500
#define K 622.8f
/************************+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*************************************************
函数功能：小车数学模型
入口参数：速度和转角
返回值：无
*************************************************************************/
int delay_time = 2000;
float Servo = 0;
void Kinematic_Analysis(float velocity,float angle)
{
	Servo=SERVO_INIT-angle*K;
}	
 int main(void)
 {		
	delay_init();
  Servo_PWM_Init(19999,71);	    //初始化PWM50HZ(20ms)驱动舵机 
	while(1)
	{
		Kinematic_Analysis(30,-0.3);  //计算舵机向右转25°CCR1的值
		TIM1->CCR1= Servo;          //控制舵机转动
//		TIM_SetCompare1(TIM1,Servo);          //控制舵机转动
		delay_ms(delay_time);       //延时，延时时间需要实际调试
		TIM1->CCR1= SERVO_INIT;     //舵机复位
		delay_ms(delay_time);       //延时，延时时间需要实际调试
//		TIM_SetCompare1(TIM1,SERVO_INIT);
		Kinematic_Analysis(30,0.75); //计算舵机向左转45°CCR1的值
		TIM1->CCR1= Servo;          //控制舵机转动
//		TIM_SetCompare1(TIM1,Servo);
		delay_ms(delay_time);
		TIM1->CCR1= SERVO_INIT;     //舵机复位
		delay_ms(delay_time);       //延时，延时时间需要实际调试

	}

	 
	 
	 
 }

 

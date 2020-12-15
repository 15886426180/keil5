#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"


#define SERVO_INIT 1500
#define K 622.8f
/************************+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*************************************************
�������ܣ�С����ѧģ��
��ڲ������ٶȺ�ת��
����ֵ����
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
  Servo_PWM_Init(19999,71);	    //��ʼ��PWM50HZ(20ms)������� 
	while(1)
	{
		Kinematic_Analysis(30,-0.3);  //����������ת25��CCR1��ֵ
		TIM1->CCR1= Servo;          //���ƶ��ת��
//		TIM_SetCompare1(TIM1,Servo);          //���ƶ��ת��
		delay_ms(delay_time);       //��ʱ����ʱʱ����Ҫʵ�ʵ���
		TIM1->CCR1= SERVO_INIT;     //�����λ
		delay_ms(delay_time);       //��ʱ����ʱʱ����Ҫʵ�ʵ���
//		TIM_SetCompare1(TIM1,SERVO_INIT);
		Kinematic_Analysis(30,0.75); //����������ת45��CCR1��ֵ
		TIM1->CCR1= Servo;          //���ƶ��ת��
//		TIM_SetCompare1(TIM1,Servo);
		delay_ms(delay_time);
		TIM1->CCR1= SERVO_INIT;     //�����λ
		delay_ms(delay_time);       //��ʱ����ʱʱ����Ҫʵ�ʵ���

	}

	 
	 
	 
 }

 

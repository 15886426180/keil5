#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/4
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//********************************************************************************

//void TIM3_Int_Init(u16 arr,u16 psc);
//void TIM3_PWM_Init(u16 arr,u16 psc);

//void TIM_GPIO_Config(void);
//void Advance_TIM_Config(void);
//void TIM_Init(void);

#define SERVO  TIM1->CCR1
void Kinematic_Analysis(float angle);
void Servo_PWM_Init(u16 arr,u16 psc);
#endif

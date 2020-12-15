  
/* Includes ------------------------------------------------------------------*/
#include "led.h"   
#include "stm32f10x.h"
/**
  * @brief  LED ����.
  *     I/O: LED1 - PA0
  *          LED2 - PA1
  *          LED3 - PA2
  *          LED4 - PA3
  *          LED5 - PA4
  *          LED6 - PA5
  *          LED7 - PA6
  *          LED8 - PA7
  * @param  ��.
  * @retval ��.
  */
void LED_Cfg(void)  //�Ӻ�������
{
    GPIO_InitTypeDef led_gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	// ʹ�ܶ˿�A��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
    /* LED I/O���� */    
    led_gpio.GPIO_Pin   = GPIO_Pin_5 | GPIO_Pin_5;
    led_gpio.GPIO_Mode  = GPIO_Mode_Out_PP;     // ͨ���������
    led_gpio.GPIO_Speed = GPIO_Speed_2MHz;      // 2MHz
    GPIO_Init(GPIOE, &led_gpio);
	 GPIO_Init(GPIOB, &led_gpio);

    /* ������ɺ�ر�����LED */
    LED1_OFF;
    LED2_OFF;

}

/******************************** END OF FILE *********************************/



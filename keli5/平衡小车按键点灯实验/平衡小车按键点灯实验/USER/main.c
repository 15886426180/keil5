#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"
int main(void)
{
    delay_init();
	  LED_Cfg();              // LED��ʼ������
    Key_Cfg();              // ������ʼ������
    
    while (1)
    {
        /* ����Key1 */
       		 if (KEY1_STA == KEY_DN)   // ����Ƿ��а�������
        {
            delay_ms(1);                      // ��ʱ����
            
            if (KEY1_STA == KEY_DN)           // ȷ���Ƿ񰴼�Key1����
            {	 
                while (KEY1_STA == KEY_DN);   // �ȴ������ͷ�
                LEDB_TOGGLE;

            }
        }
			}
}

#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"
int main(void)
{
    delay_init();
	  LED_Cfg();              // LED初始化配置
    Key_Cfg();              // 按键初始化配置
    
    while (1)
    {
        /* 按键Key1 */
       		 if (KEY1_STA == KEY_DN)   // 检测是否有按键按下
        {
            delay_ms(1);                      // 延时消抖
            
            if (KEY1_STA == KEY_DN)           // 确认是否按键Key1按下
            {	 
                while (KEY1_STA == KEY_DN);   // 等待按键释放
                LEDB_TOGGLE;

            }
        }
			}
}

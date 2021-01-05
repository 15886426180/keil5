#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"

/* 按键状态 */
#define KEY_DN  0       // 按键按下
#define KEY_UP  1       // 按键松开
#define KEY PBin(14)  // 读按键Key1状态

void KEY_Init(void);          //按键初始化
#endif  

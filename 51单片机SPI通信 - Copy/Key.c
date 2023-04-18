#include <REGX52.H>
#include "Delay.h"

unsigned char Key_KeyNumber;
unsigned char Key(void)
{
	unsigned char temp=0;
	temp=Key_KeyNumber;
	Key_KeyNumber=0;
	return temp;
}

/**
  * @brief  获取独立按键键码
  * @param  无
  * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
  */
unsigned char Key_N()
{
	unsigned char KeyNumber=0;
	
	if(P3_1==0){KeyNumber=1;}
	if(P3_0==0){KeyNumber=2;}
	if(P3_2==0){KeyNumber=3;}
	if(P3_3==0){KeyNumber=4;}
	
	return KeyNumber;
}

void Key_Loop()
{
	static unsigned char NowState,LastState;
	LastState=NowState;
	NowState=Key_N();
	if(LastState==1&&NowState==0)
	{
		Key_KeyNumber=1;
	}
	if(LastState==2&&NowState==0)
	{
		Key_KeyNumber=2;
	}
	if(LastState==3&&NowState==0)
	{
		Key_KeyNumber=3;
	}
	if(LastState==4&&NowState==0)
	{
		Key_KeyNumber=4;
	}
}
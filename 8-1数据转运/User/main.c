#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

//const uint8_t aa=0x66;//const数据存储在FLASH中

//int main()
//{
//	
//	OLED_Init();
//	OLED_ShowHexNum(1,1,aa,2);
//	OLED_ShowHexNum(2,1,(uint32_t)&ADC1->DR,8);
//	while(1)
//	{
//	 
//	}
//}

uint8_t DataA[]={0x01,0x02,0x03,0x04};
uint8_t DataB[]={0};
int main()
{
	OLED_Init();
	
	while(1)
	{
		
	}
	
}
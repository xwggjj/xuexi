#include "stm32f10x.h"                  // Device header

int main()
{	
	GPIO_InitTypeDef a;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	a.GPIO_Mode=GPIO_Mode_Out_PP;
	a.GPIO_Pin=GPIO_Pin_0;
	a.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&a);
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	while(1)
	{
		
	}
}

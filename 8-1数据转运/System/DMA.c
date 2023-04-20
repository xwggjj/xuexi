#include "stm32f10x.h"                  // Device header

void MyDMA_Init(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_InitTypeDef DMA_InitStruct;
	DMA_InitStruct.DMA_MemoryBaseAddr
	DMA_InitStruct.DMA_PeripheralDataSize
	DMA_InitStruct.DMA_MemoryInc
	DMA_InitStruct.DMA_MemoryDataSize
	DMA_InitStruct.DMA_PeripheralInc
	DMA_InitStruct.DMA_Priority
	DMA_InitStruct.DMA_BufferSize
	DMA_InitStruct.DMA_DIR
	DMA_InitStruct.DMA_M2M
	DMA_InitStruct.DMA_Mode
	DMA_InitStruct.DMA_PeripheralBaseAddr
	DMA_Init(DMAy_Channel1,&DMA_InitStruct);
	
}
#ifndef MYTIMER_H
#define MYTIMER_H

#include "stm32f10x.h"

typedef struct{
	TIM_TypeDef * Timer;
	unsigned short ARR;
	unsigned short PSC;
}MyTimer_Struct_TypeDef;


void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Timer);
void MyTimer_ActiveIT(TIM_TypeDef * Timer, char Prio , void (*IT_function) (void));
#define MyTimer_Base_start(Timer)(Timer->CR1 |= DMA_CCR1_EN);
#define MyTimer_Base_Stop(Timer)(Timer->CR1 &= ~(DMA_CCR1_EN));

#endif

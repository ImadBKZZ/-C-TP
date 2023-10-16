
#include "stm32f10x.h"
#include "MyTimer.h"


void (*TIM2Handle_Fct_Ptr) (void);

void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Timer){
	if (Timer->Timer == TIM2){
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	else if ( Timer->Timer == TIM3){
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
		
	Timer->Timer->PSC = Timer->PSC - 1;
	Timer->Timer->ARR = Timer->ARR - 1;
	
}


void MyTimer_ActiveIT(TIM_TypeDef * Timer, char Prio , void (*IT_function) (void)){
	
	if (Timer == TIM1){
		NVIC_SetPriority(TIM1_UP_IRQn,Prio);
		NVIC_EnableIRQ(TIM1_UP_IRQn);
	}
	else if (Timer == TIM2){
		NVIC_SetPriority(TIM2_IRQn,Prio);
		NVIC_EnableIRQ(TIM2_IRQn);
		TIM2Handle_Fct_Ptr = IT_function;
	}
	else if (Timer == TIM3){
		NVIC_SetPriority(TIM3_IRQn,Prio);
		NVIC_EnableIRQ(TIM3_IRQn);
	}
	else if (Timer == TIM4){
		NVIC_SetPriority(TIM4_IRQn,Prio);
		NVIC_EnableIRQ(TIM4_IRQn);
	}
	
	Timer->DIER |= TIM_DIER_UIE;

}


void TIM2_IRQHandler(void){
	TIM2->SR &= ~(TIM_SR_UIF); 
}

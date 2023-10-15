

#include "stm32f10x.h"
#include "MyGPIO.h"


int main(void){
	
	MyGPIO_Struct_typedef C13;
	MyGPIO_Struct_typedef A5;
	
	C13.GPIO = GPIOC;
	C13.GPIO_Pin = 13;
	C13.GPIO_Conf = In_Floating;
	
	A5.GPIO = GPIOA;
	A5.GPIO_Pin = 5;
	A5.GPIO_Conf = Out_Ppull;
	
	MyGPIO_Init(&C13);
	MyGPIO_Init(&A5);
	
	
	
	
	do{
		if((C13.GPIO->IDR & GPIO_IDR_IDR13) == GPIO_IDR_IDR13){
			A5.GPIO->ODR &= ~(GPIO_ODR_ODR5);
		}
		else{
			A5.GPIO->ODR |= (GPIO_ODR_ODR5);
		}
	}while(1);
	
}

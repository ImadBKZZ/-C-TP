#include <stdlib.h>

#include "stm32f10x.h"
#include "Driver_GPIO.h"


int main(void){

	


	

	do{
		MyGPIO_struct_TypeDef * C13;
		MyGPIO_struct_TypeDef * A5;
		
		
		C13->GPIO = GPIOC;
		C13->GPIO_pin = 13;
		C13->GPIO_conf = In_Floating;
		
		A5->GPIO = GPIOA;
		A5->GPIO_pin = 5;
		A5->GPIO_conf = Out_Ppull;
	
	
		MyGPIO_Init(C13);
		MyGPIO_Init(A5);
		break;
	}while(1);

}

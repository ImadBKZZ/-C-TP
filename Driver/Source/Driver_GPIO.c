#include <stdlib.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "Drive_GPIO.h"

//RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;


void MyGPIO_Init(MyGPIO_struct_TypeDef * GPIOStructPtr){
	
	
	 /*------------------Configuration Timer du GPIO---------------*/
	
	switch(GPIOStructPtr->GPIO){
	
		case GPIOA:
			RCC->APB2ENR = RCC_APB2ENR_IOPAEN;
		case GPIOB:
			RCC->APB2ENR = RCC_APB2ENR_IOPBEN;
		case GPIOC:
			RCC->APB2ENR = RCC_APB2ENR_IOPCEN;
		case GPIOD:
			RCC->APB2ENR = RCC_APB2ENR_IOPDEN;
	
	}		
	/*-------------------------------------------------------------*/
	
	
	
	
	/*---------------------Configuration registre CRL/CRH---------------*/
	
	char CurrentPin = GPIOStructPtr->GPIO_pin;
	char CurrentConf = GPIOStructPtr->GPIO_conf;
	char CurrentGPIO = GPIOStructPtr->GPIO;
	
	if (CurrentPin < 8){
		
		/*---------------------Configuratio Input/Output---------------*/
		GPIOStructPtr->GPIO->CRL &= ~(0xF << CurrentPin*4);
		
		switch(CurrentConf){
			
			case In_PullDown:
				
				GPIOStructPtr->GPIO->CRL |= (In_PullDown << CurrentPin*4);
				MyGPIO_Reset(CurrentGPIO, CurrentPin);
			
			case In_PullUp:
				GPIOStructPtr->GPIO->CRL |= (In_PullUp << CurrentPin*4);
				MyGPIO_Toggle(CurrentGPIO, CurrentPin);
			
			default :
				GPIOStructPtr->GPIO->CRL |= (CurrentConf << CurrentPin*4);
		}
	
	}
	else{
			GPIOStructPtr->GPIO->CRH &= ~(0xF << (CurrentPin%8)*4);
			switch(CurrentConf){
			
			case In_PullDown:
				
				GPIOStructPtr->GPIO->CRH |= (In_PullDown << (CurrentPin%8)*4);
				MyGPIO_Reset(CurrentGPIO, CurrentPin);
			
			case In_PullUp:

				GPIOStructPtr->GPIO->CRH |= (In_PullUp << (CurrentPin%8)*4);
				MyGPIO_Toggle(CurrentGPIO, CurrentPin);
			
			default :

				GPIOStructPtr->GPIO->CRH |= (CurrentConf << (CurrentPin%8)*4);
	}
	
}

int MyGPIO_Read(GPIO_TypeDef * GPIO , char GPIO_pin){

	return (GPIO->IDR >> GPIO_pin) & 0x1;

}

}

void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_pin){

	GPIO->ODR &= ~(1<<GPIO_pin);
}

void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_pin){

	GPIO->ODR ^= (0x1 << GPIO_pin);
}

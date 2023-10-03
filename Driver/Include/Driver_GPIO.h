#ifndef DRIVER_GPIO_H
#define DRIVER_GPIO_H

#include "stm32f10x.h"

typedef struct {
	GPIO_TypeDef * GPIO;
	char GPIO_pin ;
	char GPIO_conf ;
} MyGPIO_struct_TypeDef;

#define In_Floating 0x04
#define In_PullDown 0x08
#define In_PullUp 0x18
#define In_Analog 0x00

#define Out_Ppull 0x02
#define Out_OD 0x06
#define AltOut_Ppull 0x0A
#define AltOut_OD 0x0E


void MyGPIO_Init(MyGPIO_struct_TypeDef * GPIOStructPtr);
int MyGPIO_Read(GPIO_TypeDef * GPIO , char GPIO_pin);
void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_pin);
void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_pin);

#endif

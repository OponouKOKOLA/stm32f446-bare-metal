/*
 * led_Toggle.c
 *
 *  Created on: 20 sept. 2026
 *      Author: kokolaoponouemmanuel
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f446.h"
#include "stm32f446re_gpio_driver.h"

void delay(void)
{

	for(volatile uint32_t i = 0; i < 500000/2; i++);
}

int main(void)
{

	GPIOx_Handler_t GpioLed = {0};

	GpioLed.pGPIOx = GPIOA;
	GpioLed.PinConf_t.GPIO_Pin_Number       = GPIO_Pin_Nber5;
	GpioLed.PinConf_t.GPIO_Pin_Mode         = GPIO_MODE_OUTPUT;
	GpioLed.PinConf_t.GPIO_Pin_Speed        = GPIO_SPEED_FAST;
	GpioLed.PinConf_t.GPIO_PinOptype_Number = GPIO_OP_TYPE_PP;
	GpioLed.PinConf_t.GPIO_PinPuPdControl   = GPIO_NOPUPD;

	GPIO_PeriClock_Control(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);



	GPIO_PeriClock_Control(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);


	// buton PC13

	GPIOx_Handler_t GpioBtn = {0};


	GpioBtn.pGPIOx = GPIOC;
	GpioBtn.PinConf_t.GPIO_Pin_Number       = GPIO_Pin_Nber13;
	GpioBtn.PinConf_t.GPIO_Pin_Mode         = GPIO_MODE_INPUT;
	GpioBtn.PinConf_t.GPIO_Pin_Speed        = GPIO_SPEED_FAST;
	GpioBtn.PinConf_t.GPIO_PinOptype_Number = GPIO_OP_TYPE_PP;
	GpioBtn.PinConf_t.GPIO_PinPuPdControl   = GPIO_NOPUPD;

	GPIO_PeriClock_Control(GPIOC, ENABLE);
	GPIO_Init(&GpioBtn);


	while(1)
	{
		if(GPIO_ReadFromInput_Pin(GPIOC,GPIO_Pin_Nber13)==0)
		{
			delay();
			GPIO_ToggleOutput_Pin(GPIOA,GPIO_Pin_Nber5);

		}
	}
}

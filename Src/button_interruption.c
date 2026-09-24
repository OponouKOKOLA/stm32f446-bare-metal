/*
 * button_interruption.c
 *
 *  Created on: 24 sept. 2026
 *      Author: kokolaoponouemmanuel
 */

#include <string.h>
#include "stm32f446.h"
#include "stm32f446re_gpio_driver.h"

#define HIGH 			1
#define LOW				0
#define button_press	LOW




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







	// bouton PC13

		GPIOx_Handler_t GpioBtn = {0};


		GpioBtn.pGPIOx = GPIOC;
		GpioBtn.PinConf_t.GPIO_Pin_Number       = GPIO_Pin_Nber13;
		GpioBtn.PinConf_t.GPIO_Pin_Mode         = GPIO_MODE_IT_FT;
		GpioBtn.PinConf_t.GPIO_Pin_Speed        = GPIO_SPEED_FAST;
		GpioBtn.PinConf_t.GPIO_PinOptype_Number = GPIO_OP_TYPE_PP;
		GpioBtn.PinConf_t.GPIO_PinPuPdControl   = GPIO_PIN_PD;

		GPIO_PeriClock_Control(GPIOC, ENABLE);
		GPIO_Init(&GpioBtn);
		GPIO_WriteToOutput_Pin(GPIOA, GPIO_Pin_Nber5, GPIO_PIN_RESET);

		// IRQ Configuration
		GPIO_IRQInterrupt(IRQ_Nber_EXTI15_10,ENABLE);

		while(1);

}
//Clean the Pending event
void EXTI15_10_IRQHandler(void)
{

	GPIO_IRQHandling(GPIO_Pin_Nber13);
	GPIO_ToggleOutput_Pin(GPIOA, GPIO_Pin_Nber5);
}

/*
 * stm32f446re_gpio_driver.c
 *
 *  Created on: 18 sept. 2026
 *      Author: kokolaoponouemmanuel
 */

#include "st32f446re_gpio_driver.h"

/******************************
 * @fn 			- GPIO_PeriClock_Control
 *
 * @brief		- Enable/Disable the peripheral clock of a given GPIOx port
 *
 * @param[in]	- pGPIOx : base address of the GPIO port
 * @param[in]	- EnorDI : ENABLE or DISABLE macros
 *
 * @return		- None
 */
void GPIO_PeriClock_Control(GPIO_Reg_Def_t *pGPIOx, uint8_t EnorDI)
{
	if(EnorDI == ENABLE)
	{
		if(pGPIOx == GPIOA)		{ GPIOA_PCLCK_EN(); }
		else if(pGPIOx == GPIOB){ GPIOB_PCLCK_EN(); }
		else if(pGPIOx == GPIOC){ GPIOC_PCLCK_EN(); }
		else if(pGPIOx == GPIOD){ GPIOD_PCLCK_EN(); }
		else if(pGPIOx == GPIOE){ GPIOE_PCLCK_EN(); }
		else if(pGPIOx == GPIOF){ GPIOF_PCLCK_EN(); }
		else if(pGPIOx == GPIOG){ GPIOG_PCLCK_EN(); }
		else if(pGPIOx == GPIOH){ GPIOH_PCLCK_EN(); }
	}
	else
	{
		if(pGPIOx == GPIOA)		{ GPIOA_PCLCK_DI(); }
		else if(pGPIOx == GPIOB){ GPIOB_PCLCK_DI(); }
		else if(pGPIOx == GPIOC){ GPIOC_PCLCK_DI(); }
		else if(pGPIOx == GPIOD){ GPIOD_PCLCK_DI(); }
		else if(pGPIOx == GPIOE){ GPIOE_PCLCK_DI(); }
		else if(pGPIOx == GPIOF){ GPIOF_PCLCK_DI(); }
		else if(pGPIOx == GPIOG){ GPIOG_PCLCK_DI(); }
		else if(pGPIOx == GPIOH){ GPIOH_PCLCK_DI(); }
	}
}

/******************************
 * @fn 			- GPIO_Init
 *
 * @brief		- Configure one pin (mode, speed, pull-up/down, output type, alt function)
 *
 * @param[in]	- pGPIOHandler : port base address + pin configuration
 *
 * @note		- All fields of the handler must be initialised by the caller
 */
void GPIO_Init(GPIOx_Handler_t *pGPIOHandler)
{
	uint32_t pin    = pGPIOHandler->PinConf_t.GPIO_Pin_Number;
	uint32_t mode   = pGPIOHandler->PinConf_t.GPIO_Pin_Mode;
	uint32_t speed  = pGPIOHandler->PinConf_t.GPIO_Pin_Speed;
	uint32_t pupd   = pGPIOHandler->PinConf_t.GPIO_PinPuPdControl;
	uint32_t optype = pGPIOHandler->PinConf_t.GPIO_PinOptype_Number;
	uint32_t altfn  = pGPIOHandler->PinConf_t.GPIO_Pin_AltFunMode;


	if(mode <= GPIO_MODE_ANALOG)
	{

		pGPIOHandler->pGPIOx->MODER &= ~(0x3U << (2 * pin));
		pGPIOHandler->pGPIOx->MODER |=  (mode << (2 * pin));
	}
	else
	{
		// interrupt mode
	}


	pGPIOHandler->pGPIOx->OSPEEDR &= ~(0x3U << (2 * pin));
	pGPIOHandler->pGPIOx->OSPEEDR |=  (speed << (2 * pin));


	pGPIOHandler->pGPIOx->PUPDR &= ~(0x3U << (2 * pin));
	pGPIOHandler->pGPIOx->PUPDR |=  (pupd << (2 * pin));


	pGPIOHandler->pGPIOx->OTYPER &= ~(0x1U << pin);
	pGPIOHandler->pGPIOx->OTYPER |=  (optype << pin);


	if(mode == GPIO_MODE_ALTFN)
	{
		uint32_t temp1 = pin / 8;	// AFR[0] (pins 0-7) ou AFR[1] (pins 8-15)
		uint32_t temp2 = pin % 8;
		pGPIOHandler->pGPIOx->AFR[temp1] &= ~(0xFU << (4 * temp2));
		pGPIOHandler->pGPIOx->AFR[temp1] |=  (altfn << (4 * temp2));
	}
}

void GPIO_DeInit(GPIO_Reg_Def_t *pGPIOx)
{
	if(pGPIOx == GPIOA)		{ GPIOA_REG_RESET(); }
	else if(pGPIOx == GPIOB){ GPIOB_REG_RESET(); }
	else if(pGPIOx == GPIOC){ GPIOC_REG_RESET(); }
	else if(pGPIOx == GPIOD){ GPIOD_REG_RESET(); }
	else if(pGPIOx == GPIOE){ GPIOE_REG_RESET(); }
	else if(pGPIOx == GPIOF){ GPIOF_REG_RESET(); }
	else if(pGPIOx == GPIOG){ GPIOG_REG_RESET(); }
	else if(pGPIOx == GPIOH){ GPIOH_REG_RESET(); }
}

uint8_t GPIO_ReadFromInput_Pin(GPIO_Reg_Def_t *pGPIOx, uint8_t GPIO_Pin_Number)
{
	return (uint8_t)((pGPIOx->IDR >> GPIO_Pin_Number) & 0x1U);
}

uint16_t GPIO_ReadFromInput_Port(GPIO_Reg_Def_t *pGPIOx)
{
	return (uint16_t)(pGPIOx->IDR);
}

void GPIO_WriteToOutput_Pin(GPIO_Reg_Def_t *pGPIOx, uint8_t GPIO_Pin_Number, uint8_t value)
{
	if(value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1U << GPIO_Pin_Number);
	}
	else
	{
		pGPIOx->ODR &= ~(1U << GPIO_Pin_Number);
	}
}

void GPIO_WriteToOutput_Port(GPIO_Reg_Def_t *pGPIOx, uint8_t value)
{
	pGPIOx->ODR = value;
}

void GPIO_ToggleOutput_Pin(GPIO_Reg_Def_t *pGPIOx, uint8_t GPIO_Pin_Number)
{
	pGPIOx->ODR ^= (1U << GPIO_Pin_Number);
}

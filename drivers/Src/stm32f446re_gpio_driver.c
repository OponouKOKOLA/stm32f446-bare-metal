/*
 * stm32f446re_gpio_driver.c
 *
 *  Created on: 18 sept. 2026
 *      Author: kokolaoponouemmanuel
 */

#include "stm32f446re_gpio_driver.h"

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

	// no interruption Mode
	if(mode <= GPIO_MODE_ANALOG)
	{

		pGPIOHandler->pGPIOx->MODER &= ~(0x3U << (2 * pin));
		pGPIOHandler->pGPIOx->MODER |=  (mode << (2 * pin));
	}

	// interrupt mode

	else
	{
		//1. Configure the Faling Interruption
		if(mode == GPIO_MODE_IT_FT)
		{
			EXTI->FTSR &=~(1<<pin);
			EXTI->RTSR &=~(1<<pin);

			EXTI->FTSR |=(1<<pin);
		}
		//2.Configure the Raising Interruption

		else if(mode == GPIO_MODE_IT_RT)
		{
					EXTI->FTSR &=~(1<<pin);
					EXTI->RTSR &=~(1<<pin);

					EXTI->RTSR |=(1<<pin);

		}
		//3. Configure the both Interruption

		else if(mode == GPIO_MODE_IT_RFT)
				{
					EXTI->FTSR &=~(1<<pin);
					EXTI->RTSR &=~(1<<pin);

					EXTI->FTSR |=(1<<pin);
					EXTI->RTSR |=(1<<pin);

				}
		//4.Configure the GPIO Port Selection in SYSCFG_EXTICR

		uint8_t temp1 = pin / 4;// chose the EXTI Number (EXTI[x])
		uint8_t temp2 = pin % 4;
		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandler->pGPIOx);
		SYSCFG_PCLCK_EN();
		SYSCFG->EXTICR[temp1] &=~ (0xF << (4*temp2));
		SYSCFG->EXTICR[temp1] |= (portcode << (4*temp2));

		//5. Enable the EXTI interruption
		EXTI->IMR |=(1<<pin);

	}

	// For Speed COnfiguration
	pGPIOHandler->pGPIOx->OSPEEDR &= ~(0x3U << (2 * pin));
	pGPIOHandler->pGPIOx->OSPEEDR |=  (speed << (2 * pin));


	pGPIOHandler->pGPIOx->PUPDR &= ~(0x3U << (2 * pin));
	pGPIOHandler->pGPIOx->PUPDR |=  (pupd << (2 * pin));


	pGPIOHandler->pGPIOx->OTYPER &= ~(0x1U << pin);
	pGPIOHandler->pGPIOx->OTYPER |=  (optype << pin);


	if(mode == GPIO_MODE_ALTFN)
	{
		uint32_t temp1 = pin / 8;	// AFR Register (LOW  0 to 7 and HIGH 7 to 15)
		uint32_t temp2 = pin % 8;	// AFR Bits
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

/******************************
 * @fn 			- IRQ_Interruption
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @note		-
 */

void GPIO_IRQInterrupt(uint8_t IRQ_Number,uint8_t ENorDI)
{
	if(ENorDI == ENABLE)
	{
		if(IRQ_Number <= 31)
		{
			//1.set enbale  ISER0 Register
			*NVIC_ISER0 |= (1<<IRQ_Number);
		}

		else if (IRQ_Number >= 32 && IRQ_Number <= 63)
		{
			//2.set enbale  ISER1 Register
			*NVIC_ISER1 |= (1<<(IRQ_Number %32));
		}

		else if (IRQ_Number >= 64 && IRQ_Number <= 95)
		{
					//3.set enbale  ISER2 Register
			*NVIC_ISER2 |= (1<<(IRQ_Number%32));

		}
	}

	else
	{
		if(IRQ_Number <= 31)
		{
			//1.set enbale  ISER0 Register
			*NVIC_ICER0 = (1<<IRQ_Number);
		}

		else if (IRQ_Number >= 32 && IRQ_Number <= 63)
		{
			//2.set enbale  ISER1 Register
			*NVIC_ICER1 = (1<<(IRQ_Number%32));
		}

		else if (IRQ_Number >= 64 && IRQ_Number <= 95)
		{
					//3.set enbale  ISER2 Register
			*NVIC_ICER2 = (1<<(IRQ_Number %32));

		}
	}


}

/******************************
 * @fn 			- IRQ_Interruption
 *
 * @brief		-
 *
 * @param[in]	-
 *
 * @note		-
 */

void GPIO_IRQ_Priority (uint8_t IRQ_Number,uint8_t IRQ_Priority)

{
	//1 find out the iPr register
	uint8_t iprx = IRQ_Number/4;
	uint8_t iprx_section = IRQ_Number%4;
	uint8_t Shift = (8*iprx_section)+(8- Nber_PR_Bits);
	*(NVIC_PR_BASSEADDR + (iprx) )|= (IRQ_Priority << Shift);
}

void GPIO_IRQHandling(uint8_t Pin_Number)
{

		(EXTI->PR = (1U<<Pin_Number));

}


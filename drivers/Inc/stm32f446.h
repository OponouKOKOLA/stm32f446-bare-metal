/*
 * stm32f446.h
 *
 *  Created on: 18 sept. 2026
 *      Author: kokolaoponouemmanuel
 */

#ifndef INC_STM32F446_H_
#define INC_STM32F446_H_

#include <stdint.h>



#define __vo				volatile


/* ARM Cortex Mx Processor NVIC ISERx Register Address  */

#define NVIC_ISER0 			((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1 			((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2			((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3			((__vo uint32_t*)0xE000E10C)



/* ARM Cortex Mx Processor NVIC ICERx Register Address  */

#define NVIC_ICER0 			((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1 			((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2			((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3			((__vo uint32_t*)0xE000E18C)

/* ARM Cortex Mx Processor NVIC Priority  Register Address  */

#define NVIC_PR_BASSEADDR ((__vo uint32_t*)0xE000E400)
#define Nber_PR_Bits 	4

/* Bases address for FLASH, RAM & ROM Memory*/
#define FLASH_BASE_ADDR		0x08000000U
#define SRAM1_BASE_ADDR		0x20000000U
#define SRAM2_BASE_ADDR		0x2001C000U

#define SRAM				SRAM1_BASE_ADDR
#define ROM					0x1FFF0000UL



/* AHBx and APBx BUS PERIPHERAL BASE ADDRESS  */

#define	PERIPH_BASE_ADDR			0x40000000U
#define APB1PERIPH_BASE_ADDR		0x40000000U
#define APB2PERIPH_BASE_ADDR		0x40010000U
#define AHB1PERIPH_BASE_ADDR		0x40020000U
#define AHB2PERIPH_BASE_ADDR		0x50000000U

/* BASE Address for Peripherals wich are hanging on AHB1 BUS	*/

#define GPIOA_BASE_ADDR			(AHB1PERIPH_BASE_ADDR+0x0000)
#define GPIOB_BASE_ADDR			(AHB1PERIPH_BASE_ADDR+0x0400)
#define GPIOC_BASE_ADDR			(AHB1PERIPH_BASE_ADDR+0x0800)
#define GPIOD_BASE_ADDR			(AHB1PERIPH_BASE_ADDR+0x0C00)
#define GPIOE_BASE_ADDR			(AHB1PERIPH_BASE_ADDR+0x1000)
#define GPIOF_BASE_ADDR			(AHB1PERIPH_BASE_ADDR+0x1400)
#define GPIOG_BASE_ADDR			(AHB1PERIPH_BASE_ADDR+0x1800)
#define GPIOH_BASE_ADDR			(AHB1PERIPH_BASE_ADDR+0x1C00)
#define RCC_BASE_ADDR			(AHB1PERIPH_BASE_ADDR+0x3800)

/* BASE Address for Peripherals wich are hanging on APB1 BUS	*/

#define I2C1_BASE_ADDR	 		(APB1PERIPH_BASE_ADDR+0x5400)
#define I2C2_BASE_ADDR			(APB1PERIPH_BASE_ADDR+0x5800)
#define I2C3_BASE_ADDR			(APB1PERIPH_BASE_ADDR+0x5C00)

#define SPI2_BASE_ADDR			(APB1PERIPH_BASE_ADDR+0x3800)
#define SPI3_BASE_ADDR			(APB1PERIPH_BASE_ADDR+0x3C00)

#define USART2_BASE_ADDR		(APB1PERIPH_BASE_ADDR+0x4400)
#define USART3_BASE_ADDR		(APB1PERIPH_BASE_ADDR+0x4800)
#define UART4_BASE_ADDR		    (APB1PERIPH_BASE_ADDR+0x4C00)
#define UART5_BASE_ADDR		    (APB1PERIPH_BASE_ADDR+0x5000)

/* BASE Address for Peripherals wich are hanging on APB2 BUS	*/

#define EXTI_BASE_ADDR			(APB2PERIPH_BASE_ADDR + 0x3C00)

#define SPI1_BASE_ADDR			(APB2PERIPH_BASE_ADDR + 0x3000)

#define  USART1_BASE_ADDR		(APB2PERIPH_BASE_ADDR + 0x1000)
#define  USART6_BASE_ADDR		(APB2PERIPH_BASE_ADDR + 0x1400)

#define  SYSCFG_BASE_ADDR		(APB2PERIPH_BASE_ADDR + 0x3800)

/******* Peripheral Register definition Structure *****/

/* Structure for different Mode of GPIO*/
typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];/*AFR[0] GPIO Alternante function LOW register and AFR[1] to HIGH register */

}GPIO_Reg_Def_t;

/*Structure for EXTI Interruption*/

typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_Reg_Def_t;

typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	__vo uint32_t RESERVED1[2];
	__vo uint32_t CMPCR;
	__vo uint32_t RESERVED2[2];
	__vo uint32_t CFGR;
} SYSCFG_Reg_Def_t;

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
		 uint32_t Reserved;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
		 uint32_t Reserved1;
		 uint32_t Reserved2;
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
		 uint32_t Reserved3;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t PLLSAICFGR;
	__vo uint32_t DCKCFGR;
	__vo uint32_t CKGATENR;
	__vo uint32_t DCKCFGR2;
} RCC_Reg_Def_t;

/*====================== ENABLE  Macros  Peripherals	============================ */

/* Peripheral definition */

#define GPIOA	((GPIO_Reg_Def_t*)GPIOA_BASE_ADDR)
#define GPIOB	((GPIO_Reg_Def_t*)GPIOB_BASE_ADDR)
#define GPIOC	((GPIO_Reg_Def_t*)GPIOC_BASE_ADDR)
#define GPIOD	((GPIO_Reg_Def_t*)GPIOD_BASE_ADDR)
#define GPIOE	((GPIO_Reg_Def_t*)GPIOE_BASE_ADDR)
#define GPIOF	((GPIO_Reg_Def_t*)GPIOF_BASE_ADDR)
#define GPIOG	((GPIO_Reg_Def_t*)GPIOG_BASE_ADDR)
#define GPIOH	((GPIO_Reg_Def_t*)GPIOH_BASE_ADDR)

#define RCC	((RCC_Reg_Def_t*)RCC_BASE_ADDR)

#define EXTI ((EXTI_Reg_Def_t*)EXTI_BASE_ADDR)

#define SYSCFG ((SYSCFG_Reg_Def_t*)SYSCFG_BASE_ADDR)


/*Clock Enable Macros for GPIOx Peripherals*/

#define GPIOA_PCLCK_EN()	(RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLCK_EN()	(RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLCK_EN()	(RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLCK_EN()	(RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLCK_EN()	(RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLCK_EN()	(RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLCK_EN()	(RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLCK_EN()	(RCC->AHB1ENR |= (1<<7))

/*Clock Enable Macros for I2Cx Peripherals*/

#define I2C1_PCLCK_EN()	(RCC->APB1ENR |=(1<<21))
#define I2C2_PCLCK_EN()	(RCC->APB1ENR |= (1<<22))
#define I2C3_PCLCK_EN()	(RCC->APB1ENR |= (1<<23))


/*Clock Enable Macros for SPIx Peripherals*/

#define SPI1_PCLCK_EN()	(RCC->APB2ENR |= (1<<12))
#define SPI2_PCLCK_EN()	(RCC->APB1ENR |= (1<<14))
#define SPI3_PCLCK_EN()	(RCC->APB1ENR |= (1<<15))
#define SPI4_PCLCK_EN()	(RCC->APB2ENR |= (1<<13))

/*Clock Enable Macros for USARTx Peripherals*/

#define USART2_PCLCK_EN()	(RCC->APB1ENR |= (1<<17))
#define USART3_PCLCK_EN()	(RCC->APB1ENR |= (1<<18))
#define USART1_PCLCK_EN()	(RCC->APB2ENR |= (1<<4))
#define USART6_PCLCK_EN()	(RCC->APB2ENR |= (1<<5))

/*Clock Enable Macros for UARTx Peripherals*/

#define UART4_PCLCK_EN()	(RCC->APB1ENR |= (1<<19))
#define UART5_PCLCK_EN()	(RCC->APB1ENR |= (1<<20))




#define SYSCFG_PCLCK_EN()	(RCC->APB2ENR |= (1<<14))

/*====================== Disable Macros  Peripherals	============================*/

/*CLock Disable Macros for GPIOx Peripherals*/

#define GPIOA_PCLCK_DI()	(RCC->AHB1ENR &=~ (1<<0))
#define GPIOB_PCLCK_DI()	(RCC->AHB1ENR &=~ (1<<1))
#define GPIOC_PCLCK_DI()	(RCC->AHB1ENR &=~ (1<<2))
#define GPIOD_PCLCK_DI()	(RCC->AHB1ENR &=~ (1<<3))
#define GPIOE_PCLCK_DI()	(RCC->AHB1ENR &=~ (1<<4))
#define GPIOF_PCLCK_DI()	(RCC->AHB1ENR &=~ (1<<5))
#define GPIOG_PCLCK_DI()	(RCC->AHB1ENR &=~ (1<<6))
#define GPIOH_PCLCK_DI()	(RCC->AHB1ENR &=~ (1<<7))

/*Clock Disable Macros for I2Cx Peripherals*/

#define I2C1_PCLCK_DI()	(RCC->APB1ENR &=~ (1<<21))
#define I2C2_PCLCK_DI()	(RCC->APB1ENR &=~ (1<<22))
#define I2C3_PCLCK_DI()	(RCC->APB1ENR &=~ (1<<23))


/*Clock Disable Macros for SPIx Peripherals*/

#define SPI1_PCLCK_DI()	(RCC->APB2ENR &=~ (1<<12))
#define SPI2_PCLCK_DI()	(RCC->APB1ENR &=~ (1<<14))
#define SPI3_PCLCK_DI()	(RCC->APB1ENR &=~ (1<<15))
#define SPI4_PCLCK_DI()	(RCC->APB2ENR &=~(1<<13))

/*Clock Disable Macros for USARTx Peripherals*/

#define USART2_PCLCK_DI()	(RCC->APB1ENR &=~ (1<<17))
#define USART3_PCLCK_DI()	(RCC->APB1ENR &=~ (1<<18))
#define USART1_PCLCK_DI()	(RCC->APB2ENR &=~ (1<<4))
#define USART6_PCLCK_DI()	(RCC->APB2ENR &=~ (1<<5))

/*Clock Disable Macros for UARTx Peripherals*/

#define UART4_PCLCK_DI()	(RCC->APB1ENR &=~ (1<<19))
#define UART5_PCLCK_DI()	(RCC->APB1ENR &=~ (1<<20))

/*=============================================*/


#define SYSCFG_PCLCK_DI()	(RCC->APB2ENR &=~ (1<<14))

#define GPIO_BASEADDR_TO_CODE(x)	   ((x==GPIOA) ? 0 :\
										(x==GPIOB) ? 1 :\
										(x==GPIOC) ? 2 :\
										(x==GPIOD) ? 3 :\
										(x==GPIOE) ? 4 :\
										(x==GPIOF) ? 5 :\
										(x==GPIOG) ? 6 :\
										(x==GPIOH) ? 7 :0)


// Some macros generic for the Clock
#define ENABLE			1
#define DISABLE			0
#define SET				ENABLE
#define RESET			DISABLE

#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET

/* Macros to DISABLE peripheral */

#define GPIOA_REG_RESET()    do{ (RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()    do{ (RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()    do{ (RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()    do{ (RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()    do{ (RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOF_REG_RESET()    do{ (RCC->AHB1RSTR |= (1<<5)); (RCC->AHB1RSTR &= ~(1<<5)); }while(0)
#define GPIOG_REG_RESET()    do{ (RCC->AHB1RSTR |= (1<<6)); (RCC->AHB1RSTR &= ~(1<<6)); }while(0)
#define GPIOH_REG_RESET()    do{ (RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &= ~(1<<7)); }while(0)

#include "stm32f446re_gpio_driver.h"



#endif /* INC_STM32F446_H_ */

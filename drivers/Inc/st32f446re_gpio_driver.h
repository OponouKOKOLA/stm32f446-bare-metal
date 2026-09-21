/*
 * st32f446re_gpio_driver.h
 *
 *  Created on: 18 sept. 2026
 *      Author: kokolaoponouemmanuel
 */

#ifndef INC_STM32F446RE_GPIO_DRIVER_H_
#define INC_STM32F446RE_GPIO_DRIVER_H_

#include "stm32f446.h"
#include <stdint.h>

typedef struct
{
	uint8_t GPIO_Pin_Number;	/*! <Possible Values from Pin_Number @GPIO_Pin_Number>*/
	uint8_t GPIO_Pin_Mode;		/*! <Possible Values from Moder @GPIO_Pin_Mode>*/
	uint8_t GPIO_Pin_Speed;		/*! < Possible Values from Speed @GPIO_Pin_Speed>*/
	uint8_t GPIO_PinPuPdControl; /*! <Possible Values from @GPIO_PinPuPdControl>*/
	uint8_t GPIO_PinOptype_Number; /*! <Possible Values from OUTYPE @GPIO_PinOptype_Number>*/
	uint8_t GPIO_Pin_AltFunMode;


}GPIO_PinConf_t;


typedef struct
{
	GPIO_Reg_Def_t *pGPIOx;
	GPIO_PinConf_t PinConf_t;
}GPIOx_Handler_t;

/* GPIO_PIN_MODE
 *@GPIO_PIN_MODES  */

#define GPIO_MODE_INPUT		0
#define GPIO_MODE_OUTPUT	1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT     4  // IT=> Interruption
#define GPIO_MODE_IT_RT     5
#define GPIO_MODE_IT_RFT    6   // Rinsig_falling

/* gpio OUTPUT_TYPE Pin
 *@GPIO_PinOptype_Number*/

#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OD		1

/* gpio OUTPUT_speed Pin
*@GPIO_Pin_Speed*/

#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM   1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

/* gpio PULL UP AND PULL DOWN Pin
 *@GPIO_PinPuPdControl*/

#define GPIO_NOPUPD				0
#define GPIO_PIN_PU				1
#define GPIO_PIN_PD				2

/* GPIO Pin Number
 *@GPIO_Pin_Number*/

#define GPIO_Pin_Nber0	0
#define GPIO_Pin_Nber1	1
#define GPIO_Pin_Nber2	2
#define GPIO_Pin_Nber3	3
#define GPIO_Pin_Nber4	4
#define GPIO_Pin_Nber5	5
#define GPIO_Pin_Nber6	6
#define GPIO_Pin_Nber7	7
#define GPIO_Pin_Nber8	8
#define GPIO_Pin_Nber9	9
#define GPIO_Pin_Nber10	10
#define GPIO_Pin_Nber11	11
#define GPIO_Pin_Nber12	12
#define GPIO_Pin_Nber13	13
#define GPIO_Pin_Nber14	14
#define GPIO_Pin_Nber15	15


/*======== APIs Supported by this drivers==============*/

/* Peripheral clock */

void GPIO_PeriClock_Control(GPIO_Reg_Def_t *pGPIOx, uint8_t EnorDI);//Enable or Desable Peripheral Clock

/* Init and De-Init */

void GPIO_Init(GPIOx_Handler_t *pGPIOHandler);
void GPIO_DeInit(GPIO_Reg_Def_t *pGPIOx);

/* Data Read and Write*/

uint8_t GPIO_ReadFromInput_Pin(GPIO_Reg_Def_t *pGPIOx,uint8_t GPIO_Pin_Number);
uint16_t GPIO_ReadFromInput_Port(GPIO_Reg_Def_t *pGPIOx);
void GPIO_WriteToOutput_Pin(GPIO_Reg_Def_t *pGPIOx,uint8_t GPIO_Pin_Number,uint8_t value);
void GPIO_WriteToOutput_Port(GPIO_Reg_Def_t *pGPIOx,uint8_t value);
void GPIO_ToggleOutput_Pin(GPIO_Reg_Def_t *pGPIOx,uint8_t GPIO_Pin_Number);

/* IRQ Configuartion and ISR Handling*/

void GPIO_IRQConfig(uint8_t IRQ_Number,uint8_t IRQ_Priority,uint8_t ENorDI);
void GPIO_IRQHandling(uint8_t Pin_Number);




#endif /* INC_STM32F446RE_GPIO_DRIVER_H_ */

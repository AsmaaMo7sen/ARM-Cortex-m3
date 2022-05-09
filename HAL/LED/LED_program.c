/*
 * Author : asmaa
 * Version : V01
 * V02 at23March2022 : using BSRR & BRR instead of ODR
 * V03 at 7April2022 : adding timing at toggle function using systick
 * Date : 22March2022
 * Description : this file contains logical implementation of functions
 */

/*********************************Includes*********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



void LED_voidLedOn(u8 COPY_u8Port ,u8 COPY_u8Pin)
{
	GPIO_voidSetPinDirection(COPY_u8Port , COPY_u8Pin , GPIO_OUTPUT_PP_2M);
	GPIO_voidSetOutputPinValue( COPY_u8Port , COPY_u8Pin , GPIO_HIGH);
}

void LED_voidLedOff(u8 COPY_u8Port ,u8 COPY_u8Pin)
{
	GPIO_voidSetPinDirection(COPY_u8Port , COPY_u8Pin , GPIO_OUTPUT_PP_2M);
	GPIO_voidSetOutputPinValue( COPY_u8Port , COPY_u8Pin , GPIO_LOW);
}

void LED_voidLedToggle(u8 COPY_u8Port , u8 COPY_u8Pin)
{
	GPIO_voidToggleLed(COPY_u8Port , COPY_u8Pin) ;
}





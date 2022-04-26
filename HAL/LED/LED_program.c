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
#include "GPIO_private.h"
#include "LED_private.h"
#include "LED_config.h"



void LED_voidLedOn(u8 COPY_u8Port ,u8 COPY_u8Pin)
{
	/*switching over ports*/
	switch (COPY_u8Port)
	{
	    /*in case of port A*/
		case GPIO_PORTA :

			if (COPY_u8Pin <= 7)  //checking existing at first 8 pins
			{
				GPIOA->CRL &= ~(0b1111 << (COPY_u8Pin *4)); //preparing pins to receive new value
				GPIOA->CRL |= (0b0010 << (COPY_u8Pin *4)); //setting this pin to be output pushpull at 2MHz
				SET_BIT(GPIOA->BSRR , COPY_u8Pin); //powering led on
			}
			else if (COPY_u8Pin <=15) //checking existing at second 8 pins
			{
				GPIOA->CRH &= ~(0b1111 << (COPY_u8Pin *4)); //preparing pins to receive new value
				GPIOA->CRH |= (0b0010 << (COPY_u8Pin *4)); //setting this pin to be output pushpull at 2MHz
				SET_BIT(GPIOA->BSRR , COPY_u8Pin); //powering led on
			}
			else
			{

			}

			/*break from case of port A*/
			break ;

		/*in case of port B*/
		case GPIO_PORTB :
			if (COPY_u8Pin <= 7)  //checking existing at first 8 pins
			{
				GPIOB->CRL &= ~(0b1111 << (COPY_u8Pin *4)); //preparing pins to receive new value
				GPIOB->CRL |= (0b0010 << (COPY_u8Pin *4)); //setting this pin to be output pushpull at 2MHz
				SET_BIT(GPIOB->BSRR , COPY_u8Pin); //powering led on
			}
			else if (COPY_u8Pin <=15) //checking existing at second 8 pins
			{
				GPIOB->CRH &= ~(0b1111 << (COPY_u8Pin *4)); //preparing pins to receive new value
				GPIOB->CRH |= (0b0010 << (COPY_u8Pin *4)); //setting this pin to be output pushpull at 2MHz
				SET_BIT(GPIOB->BSRR , COPY_u8Pin); //powering led on
			}
			else
			{

			}
			/*break from case of port B*/
			break ;

		/*in case of port C*/
		case GPIO_PORTC :

		   if (COPY_u8Pin <=15) //checking existing at PORT C	 pins
			{
				GPIOC->CRH &= ~(0b1111 << (COPY_u8Pin *4)); //preparing pins to receive new value
				GPIOC->CRH |= (0b0010 << (COPY_u8Pin *4)); //setting this pin to be output pushpull at 2MHz
				SET_BIT(GPIOC->BSRR , COPY_u8Pin); //powering led on
			}
			else
			{

			}
			/*break from case of port C*/
			break ;

		/*in case of default*/
		default :
			/*do nothing and break*/
			break ;
	}

	/*return from this function*/
	return ;
}

void LED_voidLedOff(u8 COPY_u8Port ,u8 COPY_u8Pin)
{	/*switching over ports*/
	switch (COPY_u8Port)
	{
	    /*in case of port A*/
		case GPIO_PORTA :

			if (COPY_u8Pin <= 7)  //checking existing at first 8 pins
			{
				GPIOA->CRL &= ~(0b1111 << (COPY_u8Pin *4)); //preparing pins to receive new value
				GPIOA->CRL |= (0b0010 << (COPY_u8Pin *4)); //setting this pin to be output pushpull at 2MHz
				SET_BIT(GPIOA->BRR , COPY_u8Pin); //powering led off
			}
			else if (COPY_u8Pin <=15) //checking existing at second 8 pins
			{
				GPIOA->CRH &= ~(0b1111 << (COPY_u8Pin *4)); //preparing pins to receive new value
				GPIOA->CRH |= (0b0010 << (COPY_u8Pin *4)); //setting this pin to be output pushpull at 2MHz
				SET_BIT(GPIOA->BRR , COPY_u8Pin); //powering led off
			}
			else
			{

			}

			/*break from case of port A*/
			break ;

		/*in case of port B*/
		case GPIO_PORTB :
			if (COPY_u8Pin <= 7)  //checking existing at first 8 pins
			{
				GPIOB->CRL &= ~(0b1111 << (COPY_u8Pin *4)); //preparing pins to receive new value
				GPIOB->CRL |= (0b0010 << (COPY_u8Pin *4)); //setting this pin to be output pushpull at 2MHz
				SET_BIT(GPIOB->BRR , COPY_u8Pin); //powering led off
			}
			else if (COPY_u8Pin <=15) //checking existing at second 8 pins
			{
				GPIOB->CRH &= ~(0b1111 << (COPY_u8Pin *4)); //preparing pins to receive new value
				GPIOB->CRH |= (0b0010 << (COPY_u8Pin *4)); //setting this pin to be output pushpull at 2MHz
				SET_BIT(GPIOB->BRR , COPY_u8Pin); //powering led off
			}
			else
			{

			}
			/*break from case of port B*/
			break ;

		/*in case of port C*/
		case GPIO_PORTC :

			 if (COPY_u8Pin <=15) //checking existing at PORT C pins
			{
				GPIOC->CRH &= ~(0b1111 << (COPY_u8Pin *4)); //preparing pins to receive new value
				GPIOC->CRH |= (0b0010 << (COPY_u8Pin *4)); //setting this pin to be output pushpull at 2MHz
				SET_BIT(GPIOC->BRR , COPY_u8Pin); //powering led off
			}
			else
			{

			}
			/*break from case of port C*/
			break ;

		/*in case of default*/
		default :
			/*do nothing and break*/
			break ;

	}
	/*return from this function*/
	return ;
}

void LED_voidLedToggle(u8 COPY_u8Port , u8 COPY_u8Pin)
{
	/*switching over ports*/
		switch(COPY_u8Port)
		{
		    /*in case of port A*/
			case GPIO_PORTA :

				TOGGLE_BIT(GPIOA->ODR , COPY_u8Pin); //Toggling the pin value

				/*break from case of port A*/
				break ;

		    /*in case of port B*/
			case GPIO_PORTB :

				TOGGLE_BIT(GPIOB->ODR , COPY_u8Pin); //Toggling the pin value

				/*break from case of port B*/
				break ;

			/*in case of port C*/
			case GPIO_PORTC :

				TOGGLE_BIT(GPIOC->ODR , COPY_u8Pin); //Toggling the pin value

				/*break from case of port C*/
				break ;

			default :
				break ;
		}


    /*return from this function*/
	return ;

}





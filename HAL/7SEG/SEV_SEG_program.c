/*
 * Author : asmaa
 * Version : V01
 * Date : 21March2022
 * Description : this file contains logical implementation of functions
 */

/****************************Includes******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SEV_SEG_interface.h"
#include "SEV_SEG_private.h"
#include "SEV_SEG_config.h"




void _7SEG_voidDisplayNumber(u8 COPY_u8Type , u8 COPY_u8Port , u8 COPY_u8Number)
{

	switch(COPY_u8Type)
	{
	    /*in case of common cathode 7-segments*/
		case COMMON_CATHOD :

			/*switching over ports*/
			switch(COPY_u8Port)
			{
				/*in case of portA*/
			    case GPIO_PORTA :
			    	/*setting target value to pins to display the number*/
					GPIO_voidSetOutputPinValue(GPIO_PORTA , GPIO_PIN0 , GET_BIT(COPY_u8Number , 0));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , GPIO_PIN1 , GET_BIT(COPY_u8Number , 1));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , GPIO_PIN2 , GET_BIT(COPY_u8Number , 2));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , GPIO_PIN3 , GET_BIT(COPY_u8Number , 3));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , GPIO_PIN4 , GET_BIT(COPY_u8Number , 4));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , GPIO_PIN5 , GET_BIT(COPY_u8Number , 5));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , GPIO_PIN6 , GET_BIT(COPY_u8Number , 6));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , GPIO_PIN7 , GET_BIT(COPY_u8Number , 7));

			    	/*break from case of portA*/
			    	break ;


				/*in case of portB*/
				case GPIO_PORTB :
					/*setting target value to pins to display the number*/
					GPIO_voidSetOutputPinValue(GPIO_PORTB , GPIO_PIN0 , GET_BIT(COPY_u8Number , 0));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , GPIO_PIN1 , GET_BIT(COPY_u8Number , 1));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , GPIO_PIN2 , GET_BIT(COPY_u8Number , 2));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , GPIO_PIN3 , GET_BIT(COPY_u8Number , 3));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , GPIO_PIN4 , GET_BIT(COPY_u8Number , 4));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , GPIO_PIN5 , GET_BIT(COPY_u8Number , 5));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , GPIO_PIN6 , GET_BIT(COPY_u8Number , 6));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , GPIO_PIN7 , GET_BIT(COPY_u8Number , 7));
					/*break from case of portB*/
					break ;


				/*in case of default*/
				default :
					/*do nothing and break*/
					break ;
			}

			/*break from case of common cathode*/
			break;


		/*in case of common anode 7-segments*/
		case COMMON_ANODE :

			/*switching over ports*/
			switch(COPY_u8Port)
			{
				/*in case of portA*/
			    case GPIO_PORTA :
			    	/*setting target value to pins to display the number*/
					GPIO_voidSetOutputPinValue(GPIO_PORTA , _7SEG_PIN_A ,~(GET_BIT(COPY_u8Number , 0)));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , _7SEG_PIN_B ,~(GET_BIT(COPY_u8Number , 1)));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , _7SEG_PIN_C ,~(GET_BIT(COPY_u8Number , 2)));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , _7SEG_PIN_D ,~(GET_BIT(COPY_u8Number , 3)));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , _7SEG_PIN_E ,~(GET_BIT(COPY_u8Number , 4)));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , _7SEG_PIN_F ,~(GET_BIT(COPY_u8Number , 5)));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , _7SEG_PIN_G ,~(GET_BIT(COPY_u8Number , 6)));
					GPIO_voidSetOutputPinValue(GPIO_PORTA , _7SEG_PIN_DOT ,~(GET_BIT(COPY_u8Number , 7)));

			    	/*break from case of portA*/
			    	break ;


				/*in case of portB*/
				case GPIO_PORTB :
					/*setting target value to pins to display the number*/
					GPIO_voidSetOutputPinValue(GPIO_PORTB , _7SEG_PIN_A ,~(GET_BIT(COPY_u8Number , 0)));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , _7SEG_PIN_B,~(GET_BIT(COPY_u8Number , 1)));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , _7SEG_PIN_C ,~(GET_BIT(COPY_u8Number , 2)));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , _7SEG_PIN_D ,~(GET_BIT(COPY_u8Number , 3)));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , _7SEG_PIN_E ,~(GET_BIT(COPY_u8Number , 4)));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , _7SEG_PIN_F ,~(GET_BIT(COPY_u8Number , 5)));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , _7SEG_PIN_G ,~(GET_BIT(COPY_u8Number , 6)));
					GPIO_voidSetOutputPinValue(GPIO_PORTB , _7SEG_PIN_DOT ,~(GET_BIT(COPY_u8Number , 7)));
					/*break from case of portB*/
					break ;


				/*in case of default*/
				default :
					/*do nothing and break*/
					break ;
			}


			/*break from case of common anode*/
			break;


		/*in case of default*/
		default :
			/*do nothing and break*/
			break ;
	}


	/*return from this function*/
	return ;
}





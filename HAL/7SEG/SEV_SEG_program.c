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


			/*setting target value to pins to display the number*/
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_A ,(GET_BIT(COPY_u8Number , 0)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_B ,(GET_BIT(COPY_u8Number , 1)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_C ,(GET_BIT(COPY_u8Number , 2)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_D ,(GET_BIT(COPY_u8Number , 3)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_E ,(GET_BIT(COPY_u8Number , 4)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_F ,(GET_BIT(COPY_u8Number , 5)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_G ,(GET_BIT(COPY_u8Number , 6)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_DOT ,(GET_BIT(COPY_u8Number , 7)));

				/*break from case of common anode*/
				break;


		/*in case of common anode 7-segments*/
		case COMMON_ANODE :

			    	/*setting target value to pins to display the number*/
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_A ,~(GET_BIT(COPY_u8Number , 0)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_B ,~(GET_BIT(COPY_u8Number , 1)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_C ,~(GET_BIT(COPY_u8Number , 2)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_D ,~(GET_BIT(COPY_u8Number , 3)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_E ,~(GET_BIT(COPY_u8Number , 4)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_F ,~(GET_BIT(COPY_u8Number , 5)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_G ,~(GET_BIT(COPY_u8Number , 6)));
					GPIO_voidSetOutputPinValue(COPY_u8Port , _7SEG_PIN_DOT ,~(GET_BIT(COPY_u8Number , 7)));

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





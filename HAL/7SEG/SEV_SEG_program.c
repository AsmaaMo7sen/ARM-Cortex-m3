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
#include "SEV_SEG_config.h"
#include "SEV_SEG_private.h"


void _7SEG_voidInit(void)
{
#if _7SEG_1 == ENABLE

	GPIO_voidSetPinDirection(_7SEG_1_PIN_A , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_1_PIN_B , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_1_PIN_C , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_1_PIN_D , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_1_PIN_E , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_1_PIN_F , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_1_PIN_G , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_1_PIN_DOT , GPIO_OUTPUT_PP_2M) ;


	#endif

#if _7SEG_2 == ENABLE

	GPIO_voidSetPinDirection(_7SEG_2_PIN_A , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_2_PIN_B , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_2_PIN_C , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_2_PIN_D , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_2_PIN_E , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_2_PIN_F , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_2_PIN_G , GPIO_OUTPUT_PP_2M) ;
	GPIO_voidSetPinDirection(_7SEG_2_PIN_DOT , GPIO_OUTPUT_PP_2M) ;

#endif


}



void _7SEG_voidDisplayNumber(u8 COPY_u8Type , u8 COPY_u8SevenSeg , u8 COPY_u8Number)
{

	switch(COPY_u8Type)
	{
	    /*in case of common cathode 7-segments*/
		case COMMON_CATHOD :

			if (COPY_u8SevenSeg == _7SEG_1)
			{
					/*setting target value to pins to display the number*/
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_A,(GET_BIT(COPY_u8Number , 0)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_B,(GET_BIT(COPY_u8Number , 1)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_C ,(GET_BIT(COPY_u8Number , 2)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_D ,(GET_BIT(COPY_u8Number , 3)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_E,(GET_BIT(COPY_u8Number , 4)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_F ,(GET_BIT(COPY_u8Number , 5)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_G ,(GET_BIT(COPY_u8Number , 6)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_DOT ,(GET_BIT(COPY_u8Number , 7)));
			}

			else if (COPY_u8SevenSeg == _7SEG_2)
			{
					/*setting target value to pins to display the number*/
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_A,(GET_BIT(COPY_u8Number , 0)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_B,(GET_BIT(COPY_u8Number , 1)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_C ,(GET_BIT(COPY_u8Number , 2)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_D ,(GET_BIT(COPY_u8Number , 3)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_E,(GET_BIT(COPY_u8Number , 4)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_F ,(GET_BIT(COPY_u8Number , 5)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_G ,(GET_BIT(COPY_u8Number , 6)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_DOT ,(GET_BIT(COPY_u8Number , 7)));
			}
			else
			{
				/*Do nothing*/
			}

				/*break from case of common anode*/
				break;


		/*in case of common anode 7-segments*/
		case COMMON_ANODE :
			if (COPY_u8SevenSeg == _7SEG_1)
				{
					/*setting target value to pins to display the number*/
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_A,~(GET_BIT(COPY_u8Number , 0)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_B,~(GET_BIT(COPY_u8Number , 1)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_C ,~(GET_BIT(COPY_u8Number , 2)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_D ,~(GET_BIT(COPY_u8Number , 3)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_E,~(GET_BIT(COPY_u8Number , 4)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_F ,~(GET_BIT(COPY_u8Number , 5)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_G ,~(GET_BIT(COPY_u8Number , 6)));
					GPIO_voidSetOutputPinValue(_7SEG_1_PIN_DOT ,~(GET_BIT(COPY_u8Number , 7)));
				}
			else if (COPY_u8SevenSeg == _7SEG_2)

			{
				/*setting target value to pins to display the number*/
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_A,~(GET_BIT(COPY_u8Number , 0)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_B,~(GET_BIT(COPY_u8Number , 1)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_C ,~(GET_BIT(COPY_u8Number , 2)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_D ,~(GET_BIT(COPY_u8Number , 3)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_E,~(GET_BIT(COPY_u8Number , 4)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_F ,~(GET_BIT(COPY_u8Number , 5)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_G ,~(GET_BIT(COPY_u8Number , 6)));
					GPIO_voidSetOutputPinValue(_7SEG_2_PIN_DOT ,~(GET_BIT(COPY_u8Number , 7)));
			}
			else
			{
				/*Do nothing*/
			}
				/*break from case of common anode*/
				break;


		/*in case of default*/
		default :
			/*do nothing and break*/
			break ;
	}


}





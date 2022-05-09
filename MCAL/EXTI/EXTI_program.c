/*
 * Author : asmaa
 * Date : 1April2022
 * Version : V01
 * Description : this file contains logical implementation of functions
 */

/*******************************Includes***********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/**********************Global paremeters**********************/

/*pointers responsible for call back*/
void (*EXTI0_CallBack[16])(void)  ;

/**********************Functions' Definition*******************************/

void EXTI_voidInit(void)
{
    /*EXTI0*/
	#if EXTI0_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE0);

		#if EXTI0_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE0);

		#elif EXTI0_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE0);

		#elif EXTI0_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE0);
			SET_BIT(EXTI -> RTSR , EXTI_LINE0);
		#else
			#error ("wrong sensing signal configuration")
		#endif

	#elif EXTI0_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE1);

	#else
    	#error("wrong mode configuration")
	#endif


	/*EXTI1*/
	#if EXTI1_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE1);

		#if EXTI1_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE1);

		#elif EXTI1_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE1);

		#elif EXTI1_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE1);
			SET_BIT(EXTI -> RTSR , EXTI_LINE1);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI1_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE1);

	#else
		#error("wrong mode configuration")
	#endif

	/*EXTI2*/
	#if EXTI2_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE2);

		#if EXTI2_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE2);

		#elif EXTI2_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE2);

		#elif EXTI2_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE2);
			SET_BIT(EXTI -> RTSR , EXTI_LINE2);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI2_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE2);

	#else
		#error("wrong mode configuration")
	#endif


	/*EXTI3*/
	#if EXTI3_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE3);

		#if EXTI3_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE3);

		#elif EXTI3_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE3);

		#elif EXTI3_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE3);
			SET_BIT(EXTI -> RTSR , EXTI_LINE3);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI3_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE3);

	#else
		#error("wrong mode configuration")
	#endif


	/*EXTI4*/
	#if EXTI4_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE4);

		#if EXTI4_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE4);

		#elif EXTI4_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE4);

		#elif EXTI4_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE4);
			SET_BIT(EXTI -> RTSR , EXTI_LINE4);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI4_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE4);

	#else
		#error("wrong mode configuration")
	#endif

	/*EXTI5*/
	#if EXTI5_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE5);

		#if EXTI5_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE5);

		#elif EXTI5_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE5);

		#elif EXTI5_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE5);
			SET_BIT(EXTI -> RTSR , EXTI_LINE5);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI5_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE5);

	#else
		#error("wrong mode configuration")
	#endif

	/*EXTI6*/
	#if EXTI6_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE6);

		#if EXTI6_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE6);

		#elif EXTI6_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE6);

		#elif EXTI6_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE6);
			SET_BIT(EXTI -> RTSR , EXTI_LINE6);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI6_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE6);

	#else
		#error("wrong mode configuration")
	#endif

	/*EXTI7*/
	#if EXTI7_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE7);

		#if EXTI7_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE7);

		#elif EXTI7_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE7);

		#elif EXTI7_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE7);
			SET_BIT(EXTI -> RTSR , EXTI_LINE7);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI7_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE7);

	#else
		#error("wrong mode configuration")
	#endif

	/*EXTI8*/
	#if EXTI8_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE8);

		#if EXTI8_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE8);

		#elif EXTI8_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE8);

		#elif EXTI8_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE8);
			SET_BIT(EXTI -> RTSR , EXTI_LINE8);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI8_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE8);

	#else
		#error("wrong mode configuration")
	#endif

	/*EXTI9*/
	#if EXTI9_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE9);

		#if EXTI9_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE9);

		#elif EXTI9_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE9);

		#elif EXTI9_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE9);
			SET_BIT(EXTI -> RTSR , EXTI_LINE9);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI9_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE9);

	#else
		#error("wrong mode configuration")
	#endif


	/*EXTI10*/
	#if EXTI10_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE10);

		#if EXTI10_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE10);

		#elif EXTI10_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE10);

		#elif EXTI10_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE10);
			SET_BIT(EXTI -> RTSR , EXTI_LINE10);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI10_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE10);

	#else
		#error("wrong mode configuration")
	#endif


	/*EXTI11*/
	#if EXTI11_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE11);

		#if EXTI11_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE11);

		#elif EXTI11_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE11);

		#elif EXTI11_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE11);
			SET_BIT(EXTI -> RTSR , EXTI_LINE11);
		#else
			#error ("wrong sensing signal configuration")
		#endif

	#elif EXTI11_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE11);

	#else
		#error("wrong mode configuration")
	#endif


	/*EXTI12*/
	#if EXTI12_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE12);

		#if EXTI12_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE12);

		#elif EXTI12_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE12);

		#elif EXTI12_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE12);
			SET_BIT(EXTI -> RTSR , EXTI_LINE12);
		#else
			#error ("wrong sensing signal configuration")
		#endif

	#elif EXTI12_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE12);

	#else
		#error("wrong mode configuration")
	#endif


	/*EXTI13*/
	#if EXTI13_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE13);

		#if EXTI13_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE13);

		#elif EXTI13_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE13);

		#elif EXTI13_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE13);
			SET_BIT(EXTI -> RTSR , EXTI_LINE13);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI13_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE13);

	#else
		#error("wrong mode configuration")
	#endif

	/*EXTI14*/
	#if EXTI14_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE14);

		#if EXTI14_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE14);

		#elif EXTI14_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE14);

		#elif EXTI14_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE14);
			SET_BIT(EXTI -> RTSR , EXTI_LINE14);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI14_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE14);

	#else
		#error("wrong mode configuration")
	#endif


	/*EXTI15*/
	#if EXTI15_ENABLE   == ENABLE      //in case of EXTI 0 is enabled
		SET_BIT(EXTI -> IMR , EXTI_LINE15);

		#if EXTI15_TRIGGER_SELECT == FALLING_EDGE  //in case of falling edge triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE15);

		#elif EXTI15_TRIGGER_SELECT == RISING_EDGE //in case of rising edge triggred
			SET_BIT(EXTI -> RTSR , EXTI_LINE15);

		#elif EXTI15_TRIGGER_SELECT == ON_CHANGE   //in case of on_change triggerd
			SET_BIT(EXTI -> FTSR , EXTI_LINE15);
			SET_BIT(EXTI -> RTSR , EXTI_LINE15);
		#else
			#error "wrong sensing signal configuration"
		#endif

	#elif EXTI15_ENABLE == DISABLE
			CLR_BIT(EXTI -> IMR , EXTI_LINE15);

	#else
		#error("wrong mode configuration")
	#endif
}

/************************************************************************************************/

void EXTI_voidSetSenseSignal(u8 COPY_u8LineID , u8 COPY_u8SenseSignal)
{

	/*checking existance at the correct range*/
	if (COPY_u8LineID <= 15)
	{
		/*switching over sensing signals*/
		switch(COPY_u8SenseSignal)
		{
			case RISING_EDGE :     //in case of rising edge triggered

				SET_BIT(EXTI -> RTSR , COPY_u8LineID) ;
				CLR_BIT(EXTI -> FTSR , COPY_u8LineID) ;

				break ;            //break from case of rising edge

			case FALLING_EDGE :    //in case of falling edge triggered

				SET_BIT((EXTI -> FTSR ), COPY_u8LineID) ;
				CLR_BIT((EXTI -> RTSR ), COPY_u8LineID) ;

				break ;            //break from case of falling edge

			case ON_CHANGE :      //in case of on-change triggered

				SET_BIT(EXTI -> RTSR , COPY_u8LineID) ;
				SET_BIT(EXTI -> FTSR , COPY_u8LineID) ;

				break ;           //break from case of on-change

			default :             //in case of default
				 /*do nothing and break*/
				break ;
		}

	}
	else
		{
			/*throw error*/
		}
}

/************************************************************************************/

void EXTI_voidClearPendingFlag(u8 COPY_u8LineID)
{
	/*checking existance at the correct range*/
	if (COPY_u8LineID <= 15)
	{
		SET_BIT(EXTI -> PR , COPY_u8LineID);    //setting the bit to clear the pending flag
	}

	else
	{
		/*throw error*/
	}
}

/************************************************************************************/

void EXTI_voidSoftwareTrigger(u8 COPY_u8LineID)
{
	/*checking existance at the correct range*/
	if (COPY_u8LineID <= 15)
	{
		SET_BIT(EXTI -> SWIER , COPY_u8LineID);
		CLR_BIT(EXTI -> PR , COPY_u8LineID) ;
	}

	else
	{
		/*throw error*/
	}

}

/************************************************************************************/

void EXTI_voidEnableExtInt(u8 COPY_u8LineID )
{

	/*checking existance at the correct range*/
	if (COPY_u8LineID <= 15)
	{
		SET_BIT(EXTI -> IMR , COPY_u8LineID);
	}

	else
	{
		/*throw error*/
	}

}

/************************************************************************************/

void EXTI_voidDisableExtInt(u8 COPY_u8LineID)
{
	/*checking existance at the correct range*/
	if (COPY_u8LineID <= 15)
	{
		CLR_BIT(EXTI -> IMR , COPY_u8LineID);
	}

	else
	{
		/*throw error*/
	}
}

/************************************************************************************/

void EXTI_voidSetCallBack(void (*ptr)(void))
{
	for (u8 i = 0 ; i <16 ; i ++)
	{
		EXTI0_CallBack[i] = ptr ;   //pointing to target ISR made by user by global pointer
	}

}

/************************************************************************************/

void EXTI0_IRQHandler(void)
{

	EXTI0_CallBack[0]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 0) ;  //clearing pending bit
}

void EXTI1_IRQHandler(void)
{
	EXTI0_CallBack[1]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 1) ;  //clearing pending bit

}

void EXTI2_IRQHandler(void)
{
	EXTI0_CallBack[2]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 2) ;  //clearing pending bit

}

void EXTI3_IRQHandler(void)
{
	EXTI0_CallBack[3]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 3) ;  //clearing pending bit

}

void EXTI4_IRQHandler(void)
{
	EXTI0_CallBack[4]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 4) ;  //clearing pending bit

}

void EXTI5_IRQHandler(void)
{
	EXTI0_CallBack[5]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 5) ;  //clearing pending bit

}

void EXTI6_IRQHandler(void)
{
	EXTI0_CallBack[6]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 6) ;  //clearing pending bit

}


void EXTI7_IRQHandler(void)
{
	EXTI0_CallBack[7]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 7) ;  //clearing pending bit

}

void EXTI8_IRQHandler(void)
{
	EXTI0_CallBack[8]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 8) ;  //clearing pending bit

}

void EXTI9_IRQHandler(void)
{
	EXTI0_CallBack[9]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 9) ;  //clearing pending bit

}

void EXTI10_IRQHandler(void)
{
	EXTI0_CallBack[10]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 10) ;  //clearing pending bit

}

void EXTI11_IRQHandler(void)
{
	EXTI0_CallBack[11]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 11) ;  //clearing pending bit

}

void EXTI12_IRQHandler(void)
{
	EXTI0_CallBack[12]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 12) ;  //clearing pending bit

}

void EXTI13_IRQHandler(void)
{
	EXTI0_CallBack[13]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 13) ;  //clearing pending bit

}

void EXTI14_IRQHandler(void)
{
	EXTI0_CallBack[14]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 14) ;  //clearing pending bit

}

void EXTI15_IRQHandler(void)
{
	EXTI0_CallBack[15]() ;    //excuting target ISR made by user as an interrupt
	SET_BIT(EXTI->PR , 15) ;  //clearing pending bit

}

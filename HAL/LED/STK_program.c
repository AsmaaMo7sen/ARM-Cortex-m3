/*
 * Author : asmaa
 * Date : 4April2022
 * Version : V01
 * Description : this file contains logical implementation of functions
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void (*CallBack)(void);


void STK_voidInit()
{
	//in case of AHB=8000000 as input of systick
	#if STK_CLOCK_SOURCE == STK_SRC_AHB
	  SET_BIT( SYSTICK -> CTRL , 2 ); //setting bit 2 to chose AHB as clock source for systick
	  CLR_BIT( SYSTICK -> CTRL , 0) ; //clearing enable bit to make sure Systick is not running
	  CLR_BIT( SYSTICK -> CTRL , 1) ; //clearing interrupt bit to make sure INT is disabled


	//in case of AHB/8=1000000 as input of systick
	#elif STK_CLOCK_SOURCE == STK_SRC_AHB_BY_8
	  CLR_BIT( SYSTICK -> CTRL , 2 ); //clearing bit 2 to chose AHB/8 as clock source for systick
	  CLR_BIT( SYSTICK -> CTRL , 0) ; //clearing enable bit to make sure Systick is not running
	  CLR_BIT( SYSTICK -> CTRL , 1) ; //clearing interrupt bit to make sure INT is disabled

	  #else
    	#error "wrong configuration"
	#endif

	/*return from this function*/
	return ;
}


void STK_voidSetBusyWait(u32 COPY_u32Ticks )
{

	SYSTICK -> LOAD = 0 ; //resetting load register to receive new values
	SYSTICK -> VAL  = 0 ; //resetting value register to receive new values

	SYSTICK -> LOAD = COPY_u32Ticks ; //assinging target ticks to load register
	SET_BIT( SYSTICK -> CTRL , 0) ;   //enabling systick to start counting
	while(GET_BIT(SYSTICK->CTRL ,16)==0); //polling in this loop until counting is over and flag is raised

	/*return from this function*/
	return ;
}

void STK_voidSetIntervalSingle(u32 COPY_u32Ticks , void (*ptr)(void))
{

	SYSTICK -> LOAD = 0 ; //resetting load register to receive new values
	SYSTICK -> VAL  = 0 ; //resetting value register to receive new values

    SYSTICK->LOAD = COPY_u32Ticks ;  //assigning target ticks to load register
    SET_BIT(SYSTICK->CTRL , 0 );     //enabling systick to start counting
    SET_BIT(SYSTICK->CTRL , 1 );     //enabling underflow interrupt

    if (GET_BIT(SYSTICK->CTRL , 16) == 1 )
    {
    	CLR_BIT(SYSTICK->CTRL , 0) ; //disabling systick to stop counting
    	CallBack = ptr ;             //firing an interrupt
    }
    else
    {
    	/*do nothing*/
    }

	/*return from this function*/
	return ;
}

void STK_voidSetIntervalPeriodic(u32 COPY_u32Ticks , void (*ptr)(void))
{

	SYSTICK -> LOAD = 0 ; //resetting load register to receive new values
	SYSTICK -> VAL  = 0 ; //resetting value register to receive new values

      while(1)
      {
    	  SYSTICK->LOAD = COPY_u32Ticks ;  //assigning target ticks to load register
    	  SET_BIT(SYSTICK->CTRL , 0 );     //enabling systick to start counting
          SET_BIT(SYSTICK->CTRL , 1 );     //enabling underflow interrupt

    	  if (GET_BIT(SYSTICK->CTRL , 16) == 1 )
		  {
			CLR_BIT(SYSTICK->CTRL , 0) ; //disabling systick to stop counting
			CallBack = ptr ;             //firing an interrupt
		  }
		  else
		  {
			/*do nothing*/
		  }
      }
      /*return from this function*/
	return ;
}

void STK_voidStopSystick(void)
{
	CLR_BIT( SYSTICK -> CTRL , 0) ; //clearing this bit to disable systick


	/*return from this function*/
	return ;
}

u32 STK_u32GetRemainingTime(void)
{
	u32 LOCAL_u32RemainingTime = 0 ; //local variable to store the value of remaining time

	LOCAL_u32RemainingTime = SYSTICK -> VAL ; //assinging the value in VAL register as remaining time

	/*return the remaining time*/
	return LOCAL_u32RemainingTime ;
}

u32 STK_u32GetEllapsedTime(void)
{
	u32 LOCAL_u32EllapsedTime = 0 ; //local variable to store the value of ellapsed time

	LOCAL_u32EllapsedTime = (SYSTICK->LOAD) - (SYSTICK->VAL) ; //calculating the ellapsed time

	/*return the ellapsed time*/
	return LOCAL_u32EllapsedTime ;
}

/*Systick ISR*/
void SysTick_Handler(void)
{
	CallBack();
}




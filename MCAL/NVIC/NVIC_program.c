/*
 * Author : asmaa
 * Version : V01
 * Date :24March2022
 * Description : this file contains logical implementation of functions
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



void NVIC_voidSetInterruptPriority(u8 COPY_u8InterruptID , u8 COPY_u8Periority)
{
	 /*in the range of 60 available 60 interrupts*/
	 if (COPY_u8InterruptID <=59)
	 {
		 /*setting the priority shifted to fit 4MSBs of each interrupt 8Bits*/
		 /*in case of setting interrupt only in 4 bits*/
		 NVIC_IPR[COPY_u8InterruptID] = COPY_u8Periority << 4 ;
	 }
	 /*out the range of the available 60 interrupts*/
	 else
	 {
	  /*do nothing*/
	 }

	    /*return from this function*/
		return ;
}

void NVIC_voidEnableInterrupt(u8 COPY_u8InterruptId)
{
	if (COPY_u8InterruptId <= 31)      //the first 32 external interrupt
	{
		NVIC_ISER0 = (1<<COPY_u8InterruptId) ;//setting the bit to enable the interrupt
				                              //writing 0 has no effect that's why didn't use setbit
	}

	else if (COPY_u8InterruptId <= 63) //the second 32 external interrupt
	{
		NVIC_ISER1 = (1<<(COPY_u8InterruptId-32)) ; //setting the bit to enable the interrupt
											        //writing 0 has no effect that's why didn't use setbit
	}

	else
	{
		/*do nothing*/
	}

	/*return from this function*/
	return ;
}

void NVIC_voidDisableInterrupt(u8 COPY_u8InterruptId)
{
	if (COPY_u8InterruptId <= 31)      //the first 32 external interrupt
	{
		NVIC_ICER0 = (1<<COPY_u8InterruptId) ;//setting the bit to disable the interrupt
				                              //writing 0 has no effect that's why didn't use setbit
	}

	else if (COPY_u8InterruptId <= 63) //the second 32 external interrupt
	{
		NVIC_ICER1 = (1<<(COPY_u8InterruptId-32)) ; //setting the bit to disable the interrupt
											        //writing 0 has no effect that's why didn't use setbit
	}

	else
	{
		/*do nothing*/
	}

	/*return from this function*/
	return ;
}


void NVIC_voidSetPendingFlag(u8 COPY_u8InterruptId)
{
	if (COPY_u8InterruptId <= 31)      //the first 32 external interrupt
	{
		NVIC_ISPR0 = (1<<COPY_u8InterruptId) ;//setting the bit to disable the interrupt
				                              //writing 0 has no effect that's why didn't use setbit
	}

	else if (COPY_u8InterruptId <= 63) //the second 32 external interrupt
	{
		NVIC_ISPR1 = (1<<(COPY_u8InterruptId-32)) ; //setting the bit to disable the interrupt
											        //writing 0 has no effect that's why didn't use setbit
	}

	else
	{
		/*do nothing*/
	}

	/*return from this function*/
	return ;
}


void NVIC_voidClearPendingFlag(u8 COPY_u8InterruptId)
{
	if (COPY_u8InterruptId <= 31)      //the first 32 external interrupt
	{
		NVIC_ICPR0 = (1<<COPY_u8InterruptId) ;//setting the bit to disable the interrupt
				                              //writing 0 has no effect that's why didn't use setbit
	}

	else if (COPY_u8InterruptId <= 63) //the second 32 external interrupt
	{
		NVIC_ICPR1 = (1<<(COPY_u8InterruptId-32)) ; //setting the bit to disable the interrupt
											        //writing 0 has no effect that's why didn't use setbit
	}

	else
	{
		/*do nothing*/
	}

	/*return from this function*/
	return ;
}

u8 NVIC_u8ReadActiveFlag (u8 COPY_u8InterruptId)
{
	/*local variable to store flag status*/
	u8 LOCAL_u8FlagStatus ;

	if (COPY_u8InterruptId <= 31)      //the first 32 external interrupt
	{
		/*getting the value of the flag*/
		LOCAL_u8FlagStatus = GET_BIT(NVIC_IABR0 , COPY_u8InterruptId);
	}

	else if (COPY_u8InterruptId <= 63) //the second 32 external interrupt
	{
		/*getting the value of the flag*/
        LOCAL_u8FlagStatus = GET_BIT(NVIC_IABR1 ,( COPY_u8InterruptId-32));
	}

	else
	{
		/*do nothing*/
	}

	/*return from this function*/
	return LOCAL_u8FlagStatus;
}




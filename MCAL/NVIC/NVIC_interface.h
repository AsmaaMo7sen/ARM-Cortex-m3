/*
 * Author : asmaa
 * Version : V01
 * Date : 24March2022
 * Description : this file contains interfacing information of this peripheral
 */

/*Header File Guard*/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H




/**************************Functions' prototype******************************/

/*this function is to initialize NVIC with certain group and sub priorities distrubtion*/
void NVIC_voidInit();

/*this fucntion is to set the priority of a interrupt*/
void NVIC_voidSetInterruptPriority(u8 COPY_u8InterruptID , u8 COPY_u8Periority);

/*this function is to enable any interrupt*/
void NVIC_voidEnableInterrupt(u8 COPY_u8InterruptId);

/*this function is to disable any interrupt*/
void NVIC_voidDisableInterrupt(u8 COPY_u8InterruptId);

/*this function is to set the pending flag*/
void NVIC_voidSetPendingFlag(u8 COPY_u8InterruptId);

/*this function is to clear the pending flag*/
void NVIC_voidClearPendingFlag(u8 COPY_u8InterruptId);

/*this function is to read the active flag value*/
u8 NVIC_u8ReadActiveFlag (u8 COPY_u8InterruptId) ;

/*this function is to set the periority of an interrupt*/
void NVIC_voidSetPeriority(s8 COPY_s8InterruptId , u8 COPY_u8GroupPeriority ,
		u8 COPY_u8SubPeriority , u32 COPY_u32PriorityType);

#endif

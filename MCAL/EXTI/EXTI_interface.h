/*
 * Author : asmaa
 * Date : 1April2022
 * Version : V01
 * Description : this file contains interfacing information of EXTI peripheral
 */

/*Header File Guard*/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/**********************************Interfacing Macros*************************************/
/*EXTI lines*/
#define EXTI_LINE0                (0)
#define EXTI_LINE1                (1)
#define EXTI_LINE2                (2)
#define EXTI_LINE3                (3)
#define EXTI_LINE4                (4)
#define EXTI_LINE5                (5)
#define EXTI_LINE6                (6)
#define EXTI_LINE7                (7)
#define EXTI_LINE8                (8)
#define EXTI_LINE9                (9)
#define EXTI_LINE10               (10)
#define EXTI_LINE11               (11)
#define EXTI_LINE12               (12)
#define EXTI_LINE13               (13)
#define EXTI_LINE14               (14)
#define EXTI_LINE15               (15)


/*sensing signals*/
#define FALLING_EDGE            0
#define RISING_EDGE             1
#define ON_CHANGE               2

/*enabled or disabled*/
#define ENABLE                  1
#define DISABLE                 0

#define NULL ((void*)0)


/*********************************Functions' Prototype**************************************/

/*this function is to initialize EXTI with specific sensing signal (preconfiguration)*/
void EXTI_voidInit(void);

/*this function is to set the sense signal of a line(run time configuration)*/
void EXTI_voidSetSenseSignal(u8 COPY_u8LineID , u8 COPY_u8SenseSignal);

/*this function is to clear the pending flag*/
void EXTI_voidClearPendingFlag(u8 COPY_u8LineID);

void EXTI_voidSoftwareTrigger(u8 COPY_u8LineID);

/*this functinon is to enable an external interrupt*/
void EXTI_voidEnableExtInt(u8 COPY_u8LineID );

/*this function is to disable an external interrupt*/
void EXTI_voidDisableExtInt(u8 COPY_u8LineID);

/*this function is to call back ISR content */
void EXTI_voidSetCallBack(void (*ptr)(void));

#endif

/*
 * Author : asmaa
 * Date : 30March 2022
 * Version : V01
 *           V02 : redefinition for register using struct
 * Description : this file contains interfacing information of AFIO peripheral
 */

/*Header File Guard*/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/**************** Interfacing macros  ******************/

/*external interrupts lines*/
#define EXTI_LINE0             (0)
#define EXTI_LINE1             (1)
#define EXTI_LINE2             (2)
#define EXTI_LINE3             (3)
#define EXTI_LINE4             (4)
#define EXTI_LINE5             (5)
#define EXTI_LINE6             (6)
#define EXTI_LINE7             (7)
#define EXTI_LINE8             (8)
#define EXTI_LINE9             (9)
#define EXTI_LINE10            (10)
#define EXTI_LINE11            (11)
#define EXTI_LINE12            (12)
#define EXTI_LINE13            (13)
#define EXTI_LINE14            (14)
#define EXTI_LINE15            (15)

/*Ports*/
#define AFIO_PORTA             (0)
#define AFIO_PORTB             (1)
#define AFIO_PORTC             (2)

/****************Functions' Prototypes******************/

/*this function is to select the port of any line*/
void AFIO_voidExtiLinePortSelect(u8 COPY_u8LineID , u8 COPY_u8Port);

#endif

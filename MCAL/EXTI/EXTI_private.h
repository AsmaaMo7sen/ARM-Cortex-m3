/*
 * Author : asmaa
 * Date : 1April2022
 * Version : V01
 * Description : this file contains private information related to EXTI peripheral
 */

/*Header File Guard*/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/******************************Private macros**************************************/


/******************************Registers' Description*************************************/
typedef struct
{
	volatile u32 IMR ;
    volatile u32 EMR ;
    volatile u32 RTSR ;
    volatile u32 FTSR ;
    volatile u32 SWIER ;
    volatile u32 PR ;
}EXTI_t;

#define EXTI  ((volatile EXTI_t *)(0x40010400))

#endif

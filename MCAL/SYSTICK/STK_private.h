/*
 * Author : asmaa
 * Date : 4April2022
 * Version : V01
 * Description : this file contains private information of SysTick peripheral
 */

/*Header File Guard*/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/*systick registers*/
typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB ;
}SYSTICK_t;

#define SYSTICK ((volatile SYSTICK_t *)(0xE000E010))

#endif

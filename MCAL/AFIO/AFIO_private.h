/*
 * Author : asmaa
 * Date : 30March 2022
 * Version : V01
 *           V02 : redefinition for register using struct
 * Description : this file contains private information of AFIO peripheral
 */

/*Header File Guard*/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/********************************AFIO registers********************************/
typedef struct
{
	volatile u32 EXTICR1 ;
	volatile u32 EXTICR2 ;
	volatile u32 EXTICR3 ;
	volatile u32 EXTICR4 ;
}AFIO_t;

/*AFIO base address*/
#define AFIO ((volatile AFIO_t *)(0x40010008))



#endif

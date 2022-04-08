/*
 * Author : asmaa
 * Version : V01
 * Data : 24March2022
 * Description : this file contains private information of NVIC peripheral
 */

/*Header File Guard*/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H



/************************************Registers***********************************/

/*Base address = 0xE000E100*/

/*interrupt set enable registers*/
#define NVIC_ISER0        (*(u32 *)(0xE000E100)) //enable external from 0:31
#define NVIC_ISER1        (*(u32 *)(0xE000E104)) //enable external from 32:63


/*interrupt clear enable registers*/
#define NVIC_ICER0        (*(u32 *)(0xE000E180)) //disable external from 0:31
#define NVIC_ICER1        (*(u32 *)(0xE000E184)) //disable external from 32:63

/*set pending flag*/
#define NVIC_ISPR0        (*(u32 *)(0xE000E200)) //set pending flag from 0:31
#define NVIC_ISPR1        (*(u32 *)(0xE000E204)) //set pending flag from 32:63

/*clear pending flag*/
#define NVIC_ICPR0        (*(u32 *)(0xE000E280)) //clear pending flag from 0:31
#define NVIC_ICPR1        (*(u32 *)(0xE000E284)) //clear pending flag from 32:63

/*read active flag*/
#define NVIC_IABR0        (*(volatile u32 *)(0xE000E300)) //read active flag from 0:31
#define NVIC_IABR1        (*(volatile u32 *)(0xE000E304)) //read active flag from 32:63

/*interrupt priority register*/
#define NVIC_IPR          ((volatile u8 *)(0xE000E400))



#endif

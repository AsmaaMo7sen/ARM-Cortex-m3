/****************************************************************************************/
/*    Author  : asmaa                                                                   */
/*    Date    :12March2022                                                              */
/*    Version : V01                                                                     */
/*     V02 at 23March2022: a new function to set value of pins with BSRR & BRR          */
/*                          + another 1 to set port value with ODR                      */
/*                          + another 1 to lock bits                                    */
/*     V03 at 1April : added toggle led function                                        */
/*     V04 at 8April : redefinition of registers using struct                           */
/*    Description :this file contains private information of peripheral                 */
/****************************************************************************************/

/*Header File Guard*/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/*GPIO registers*/
typedef struct
{
	volatile u32 CRL  ;
	volatile u32 CRH  ;
	volatile u32 IDR  ;
	volatile u32 ODR  ;
	volatile u32 BSRR ;
	volatile u32 BRR  ;
	volatile u32 LCKR ;

}GPIO_t;

/*port A base adderss*/
#define GPIOA ((volatile GPIO_t *)(0x40010800))

/*port B base address*/
#define GPIOB ((volatile GPIO_t *)(0x40010C00))

/*port C base address*/
#define GPIOC ((volatile GPIO_t *)(0x40011000))



#endif

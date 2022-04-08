/*****************************************************************************************/
/*        Author  : asmaa                                                                */
/*        Date    : 8March2022                                                           */
/*        Version : V01                                                                  */
/*                  V02 : redefinition of registers using struct                         */
/*        Description  : this file contains private data of RCC peripheral               */
/*****************************************************************************************/

/*Header File Guard*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/********************private macros***********************/

/*four different types of system clock*/
#define RCC_SYSTEM_CLOCK_HSE_RC                 (0)
#define RCC_SYSTEM_CLOCK_HSE_CRYSTAL            (1)
#define RCC_SYSTEM_CLOCK_HSI                    (2)
#define RCC_SYSTEM_CLOCK_PLL                    (3)

/*different inputs for PLL circuit*/
#define RCC_PLL_INPUT_HSE_RC                    (0)
#define RCC_PLL_INPUT_HSE_CRYSTAL               (1)
#define RCC_PLL_INPUT_HSE_RC_DIV_2              (2)
#define RCC_PLL_INPUT_HSE_CRYSTAL_DIV_2         (3)
#define RCC_PLL_INPUT_HSI                       (4)


/********************Registers' Definition**********************/

/*RCC registers*/
typedef struct
{   volatile u32 CR   ;
	volatile u32 CFGR ;
	volatile u32 CIR  ;
	volatile u32 APB2RSTR  ;
	volatile u32 APB1RSTR  ;
	volatile u32 AHBENR  ;
	volatile u32 APB2ENR  ;
	volatile u32 APB1ENR  ;
	volatile u32 BDCR  ;
	volatile u32 CSR  ;
}RCC_t;

/*RCC base address*/
#define RCC ((volatile RCC_t *)(0x40021000))


#endif

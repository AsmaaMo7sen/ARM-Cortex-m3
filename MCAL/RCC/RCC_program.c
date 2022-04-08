/*****************************************************************************************/
/*     Author  : asmaa                                                                   */
/*     Date    : 8March2022                                                              */
/*     Version : V01                                                                     */
/*                  V02 : redefinition of registers using struct                         */
/*     Description : this file contains logical implementation of functions              */
/*****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*this function is to select a system clock source*/
void RCC_voidInitSystemClock(void)
{
/*in case of selecting internal rc as system clock*/
#if RCC_SYSTEM_CLOCK == RCC_SYSTEM_CLOCK_HSI

	RCC->CR   = 0x00000001 ; //enable HSI =8M
	RCC->CFGR = 0x00000000 ; //select HSI as system clock

/*in case of selecting external rc as system clock*/
#elif RCC_SYSTEM_CLOCK == RCC_SYSTEM_CLOCK_HSE_RC

	RCC->CR   = 0x00050000 ; //enable external RC
	RCC->CFGR = 0X00000001 ; //select external RC as system clock

/*in case of selecting external crystal as system clock*/
#elif RCC_SYSTEM_CLOCK == RCC_SYSTEM_CLOCK_HSE_CRYSTAL

	RCC->CR   = 0x00010000 ; //enable external crystal
	RCC->CFGR = 0x00000001 ; //select external crystal as system clock

/*in case of selecting pll as system clock*/
#elif RCC_SYSTEM_CLOCK == RCC_SYSTEM_CLOCK_PLL

  /*in case of external rc as input of pll*/
  #if RCC_PLL_INPUT == RCC_PLL_INPUT_HSE_RC

	RCC->CR   = 0x00050000 ; //enable external rc
	RCC->CFGR = 0x00010000 ; //selecting external rc as pll input with PLLMUL=0000
	RCC->CR   = 0x01050000 ; //enable pll
	RCC->CFGR = 0x00010402 ; //selecting pll as system clock with ABP1 prescaler=2

  /*in case of external crystal as pll input*/
  #elif RCC_PLL_INPUT == RCC_PLL_INPUT_HSE_CRYSTAL

	RCC->CR   = 0x00010000 ; //enable external crystal
	RCC->CFGR = 0x00090000 ; //selecting external crystal as pll input with PLLMUL=0010
	RCC->CR   = 0x01010000 ; //enable pll
	RCC->CFGR = 0x00090402 ; //selecting pll as system clock with ABP1 prescaler=2

  /*in case of external rc/2 as pll input*/
  #elif RCC_PLL_INPUT== RCC_PLL_INPUT_HSE_RC_DIV_2

	RCC->CR   = 0x00050000 ; //enable external rc
	RCC->CFGR = 0x003F0000 ; //selecting external rc/2 as pll input with PLLMUL=1111
	RCC->CR   = 0x01050000 ; //enable pll
	RCC->CFGR = 0x003F0402 ; //selecting pll as system clock with ABP1 prescaler=2

  /*in case of external crystal/2 as pll input*/
  #elif RCC_PLL_INPUT == RCC_PLL_INPUT_HSE_CRYSTAL_DIV_2

	RCC->CR   = 0x00010000 ; //enable external crystal
	RCC->CFGR = 0x00090000 ; //selecting external crystal as pll input with PLLMUL=0010
	RCC->CR   = 0x01010000 ; //enable pll
	RCC->CFGR = 0x00090402 ; //selecting pll as system clock with ABP1 prescaler=2

  /*in case of internal rc as pll input*/
  #elif RCC_PLL_INPUT == RCC_PLL_INPUT_HSI

	RCC->CR   = 0x00080001 ; //enable internal rc
	RCC->CFGR = 0x003C0001 ; //selecting internal rc as pll input with PLLMUL=1111
	RCC->CR   = 0x01008001 ; //enable pll
	RCC->CFGR = 0x00360402 ; //selecting pll as system clock with ABP1 prescaler=2

#endif

#else
#error ("you picked wrong configuration")

#endif
	return;
}


/*this function is to enable any peripheral at any bus*/
void RCC_voidEnableClock (u8 Copy_u8BusId , u8 Copy_u8PeripheralId)
{
	/*Checking for peripheral ID*/
	if(Copy_u8PeripheralId <= 31)
	{
	/*switching over Buses*/
	 switch(Copy_u8BusId)
	 {
		 /*in case of AHB bus*/
		 case RCC_AHB  :

			 /*enabling target peripheral*/
			  SET_BIT(RCC->AHBENR , Copy_u8PeripheralId);

			 /*break from AHB case*/
			 break ;

		 /*in case of APB1 bus*/
		 case RCC_APB1 :

			 /*enabling target peripheral*/
			 SET_BIT(RCC->APB1ENR , Copy_u8PeripheralId);

			 /*break from APB1 case*/
			 break ;

		 /*in case of APB2 bus*/
		 case RCC_APB2 :

			 /*enabling target peripheral*/
			  SET_BIT(RCC->APB2ENR , Copy_u8PeripheralId);

			 /*break from APB2 case*/
			 break ;

		 /*in case of default*/
		 default :
			   /*return error*/
			   /*break from default*/
			   break ;
		 }

	}

	else
	{
		/*return error*/
	}

	return ;
}


/*this function is to disable any peripheral at any bus*/
void RCC_voidDisableClock (u8 Copy_u8BusId , u8 Copy_u8PeripheralId)
{
	/*Checking for peripheral ID*/
	if(Copy_u8PeripheralId <= 31)
	{
	/*switching over Buses*/
	 switch(Copy_u8BusId)
	 {
		 /*in case of AHB bus*/
		 case RCC_AHB  :

			 /*disabling target peripheral*/
			  CLR_BIT(RCC->AHBENR , Copy_u8PeripheralId);

			 /*break from AHB case*/
			 break ;

		 /*in case of APB1 bus*/
		 case RCC_APB1 :

			 /*disabling target peripheral*/
			 CLR_BIT(RCC->APB1ENR , Copy_u8PeripheralId);

			 /*break from APB1 case*/
			 break ;

		 /*in case of APB2 bus*/
		 case RCC_APB2 :

			 /*disabling target peripheral*/
			  CLR_BIT(RCC->APB2ENR , Copy_u8PeripheralId);

			 /*break from APB2 case*/
			 break ;

		 /*in case of default*/
		 default :
			   /*return error*/
			   /*break from default*/
			   break ;
		 }
	}

	else
	{
		/*return error*/
	}

	return ;
}


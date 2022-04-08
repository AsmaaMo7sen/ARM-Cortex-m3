/*
 * Author : asmaa
 * Date : 30March2022
 * Version : V01
 *           V02 : redefinition for register using struct
 * Description : this file contains logical implementation of functions
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"



void AFIO_voidExtiLinePortSelect(u8 COPY_u8LineID , u8 COPY_u8Port)
{

	if (COPY_u8LineID <= 3)       /*in range of line [0:3]*/
	{
		AFIO->EXTICR1 &= ~(0b1111 << (COPY_u8LineID*4)) ;     //clearing bits to receive new values
		AFIO->EXTICR1 |= (COPY_u8Port << (COPY_u8LineID*4));  //setting target port of the line
	}

	else if(COPY_u8LineID <= 7)   /*in range of line [4:7]*/
	{
		COPY_u8LineID -= 4 ;
		AFIO->EXTICR2 &= ~(0b1111 << (COPY_u8LineID*4)) ;     //clearing bits to receive new values
		AFIO->EXTICR2 |= (COPY_u8Port << (COPY_u8LineID*4));  //setting target port of the line
	}

	else if (COPY_u8LineID <= 11)  /*in range of line [8:11]*/
	{
		COPY_u8LineID -= 8 ;
		AFIO->EXTICR2 &= ~(0b1111 << (COPY_u8LineID*4)) ;     //clearing bits to receive new values
		AFIO->EXTICR2 |= (COPY_u8Port << (COPY_u8LineID*4));  //setting target port of the line
	}

	else if (COPY_u8LineID <=15)   /*in range of line [12:15]*/
	{
		COPY_u8LineID -= 12 ;
		AFIO->EXTICR2 &= ~(0b1111 << (COPY_u8LineID*4)) ;     //clearing bits to receive new values
		AFIO->EXTICR2 |= (COPY_u8Port << (COPY_u8LineID*4));  //setting target port of the line
	}

	else
	{
		/*do nothing*/
	}

	/*return from this function*/
	return ;
}

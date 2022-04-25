/*
 * Author : asmaa
 * Date   : 6April
 * Version : V01
 * Description : this file contains logical implementation of functions
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SCB_interface.h"
#include "SCB_config.h"
#include "SCB_private.h"


void NVIC_voidInit()
{
	/*setting the configurable distribution*/
	SCB_AIRCR = NVIC_GRP_SUB_DISTRUBTION ;

	/*return from this function*/
	return ;
}

/*
 * Author : asmaa
 * Date   : 6April2022
 * Version: V01
 * Description : this file contains configurable parameters of SCB peripheral
 */

/*Header File Guard*/
#ifndef SCB_CONFIG_H
#define SCB_CONFIG_H

/*types of priorities' distrubtion* :
#define NVIC_16_GROUP_0_SUB    (0x05FA0300) //4bits for group & 0 for sub
#define NVIC_8_GROUP_2_SUB     (0x05FA0400) //3bits for group & 1 for sub
#define NVIC_4_GROUP_4_SUB     (0x05FA0500) //2bits for group & 2 for sub
#define NVIC_2_GROUP_8_SUB     (0x05FA0600) //1bits for group & 3 for sub
#define NVIC_0_GROUP_16_SUB    (0x05FA0700) //0bits for group & 4 for sub */
#define NVIC_GRP_SUB_DISTRUBTION  NVIC_4_GROUP_4_SUB


#endif

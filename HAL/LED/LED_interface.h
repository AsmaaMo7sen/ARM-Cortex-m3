/*
 * Author : asmaa
 * Version : V01
 * Date : 22March2022
 * Description : this file contains interfacing information of this peripheral
 */

/*Header File Guard*/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H



/********************************Functions' Prototypes******************************/

/*this function is to power on a led connected to a certain pin*/
void LED_voidLedOn(u8 COPY_u8Port ,u8 COPY_u8Pin);

/*this function is to power off a led connected to a certain pin*/
void LED_voidLedOff(u8 COPY_u8Port ,u8 COPY_u8Pin);

/*this function is to toggle a led connected to a certain pin with delay in usec*/
void LED_voidLedToggle(u8 COPY_u8Port ,u8 COPY_u8Pin ,u32 COPY_u32time);




#endif

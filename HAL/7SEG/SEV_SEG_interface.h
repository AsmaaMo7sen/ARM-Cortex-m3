/*
 * Author : asmaa
 * Version : V01
 * Date : 21March2022
 * Description : this file contains interfacing information of 7-segment peripheral
 */

/*Header File Guard*/
#ifndef SEV_SEG_INTERFACE_H
#define SEV_SEG_INTERFACE_H


/*7-segment type*/
#define COMMON_CATHOD                (0)
#define COMMON_ANODE                 (1)

/*Numbers representation*/
#define NUMBER_0                     (0b00111111)
#define NUMBER_1                     (0b00000110)
#define NUMBER_2                     (0b01011011)
#define NUMBER_3                     (0b01001111)
#define NUMBER_4                     (0b01100110)
#define NUMBER_5                     (0b01101101)
#define NUMBER_6                     (0b01111101)
#define NUMBER_7                     (0b00000111)
#define NUMBER_8                     (0b01111111)
#define NUMBER_9                     (0b01101111)
#define DOT                          (0b10000000)


/*7-segment pins*/
#define _7SEG_PIN_A                  (GPIO_PIN0)
#define _7SEG_PIN_B                  (GPIO_PIN1)
#define _7SEG_PIN_C                  (GPIO_PIN2)
#define _7SEG_PIN_D                  (GPIO_PIN3)
#define _7SEG_PIN_E                  (GPIO_PIN4)
#define _7SEG_PIN_F                  (GPIO_PIN5)
#define _7SEG_PIN_G                  (GPIO_PIN6)
#define _7SEG_PIN_DOT                (GPIO_PIN7)


/*******************************Functions' Prototypes********************************/

/*this function is to display a certain number*/
void _7SEG_voidDisplayNumber(u8 COPY_u8Type , u8 COPY_u8Port , u8 COPY_u8Number);

#endif

/*
 * Author : asmaa
 * Version : V01
 * Date : 21March2022
 * Description : this file contains configurable parameters of 7-segments peripheral
 */

/*Header File Guard*/
#ifndef SEV_SEG_CONFIG_H
#define SEV_SEG_CONFIG_H

/*status of 2 available 7-segments*/
#define _7SEG_1    DISABLE
#define _7SEG_2    ENABLE


/*first 7-segment pins connection [port and pin]*/
#define _7SEG_1_PIN_A                  GPIO_PORTA ,GPIO_PIN0
#define _7SEG_1_PIN_B                  GPIO_PORTA ,GPIO_PIN1
#define _7SEG_1_PIN_C                  GPIO_PORTA ,GPIO_PIN2
#define _7SEG_1_PIN_D                  GPIO_PORTA ,GPIO_PIN3
#define _7SEG_1_PIN_E                  GPIO_PORTA ,GPIO_PIN4
#define _7SEG_1_PIN_F                  GPIO_PORTA ,GPIO_PIN5
#define _7SEG_1_PIN_G                  GPIO_PORTA ,GPIO_PIN6
#define _7SEG_1_PIN_DOT                GPIO_PORTA ,GPIO_PIN7

/*second 7-segment pins connection [port and pin]*/
#define _7SEG_2_PIN_A                  GPIO_PORTA ,GPIO_PIN0
#define _7SEG_2_PIN_B                  GPIO_PORTA ,GPIO_PIN1
#define _7SEG_2_PIN_C                  GPIO_PORTA ,GPIO_PIN2
#define _7SEG_2_PIN_D                  GPIO_PORTA ,GPIO_PIN3
#define _7SEG_2_PIN_E                  GPIO_PORTA ,GPIO_PIN4
#define _7SEG_2_PIN_F                  GPIO_PORTA ,GPIO_PIN5
#define _7SEG_2_PIN_G                  GPIO_PORTA ,GPIO_PIN6
#define _7SEG_2_PIN_DOT                GPIO_PORTA ,GPIO_PIN7
#endif

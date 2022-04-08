/****************************************************************************************/
/*    Author  : asmaa                                                                   */
/*    Date    :12March2022                                                              */
/*    Version : V01                                                                     */
/*    V02 at 23March2022 : three new functions                                          */
/*    V03 at 1April : added toggle led function                                         */
/*    V04 at 8April : redefinition of registers using struct                           */
/*    Description :this file contains logical implementation of functions               */
/****************************************************************************************/

/*Header File Guard*/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*******************************Interfacing Macros********************************/

/*Ports numbers*/
#define GPIO_PORTA                     (0)
#define GPIO_PORTB                     (1)
#define GPIO_PORTC                     (2)

/*Pins numbers*/
#define GPIO_PIN0                       (0)
#define GPIO_PIN1                       (1)
#define GPIO_PIN2                       (2)
#define GPIO_PIN3                       (3)
#define GPIO_PIN4                       (4)
#define GPIO_PIN5                       (5)
#define GPIO_PIN6                       (6)
#define GPIO_PIN7                       (7)
#define GPIO_PIN8                       (8)
#define GPIO_PIN9                       (9)
#define GPIO_PIN10                      (10)
#define GPIO_PIN11                      (11)
#define GPIO_PIN12                      (12)
#define GPIO_PIN13                      (13)
#define GPIO_PIN14                      (14)
#define GPIO_PIN15                      (15)

/*Modes values*/
#define GPIO_INPUT_ANALOG               (0)
#define GPIO_INPUT_FLOATING             (4)
#define GPIO_INPUT_PULLED               (8)

#define GPIO_OUTPUT_PP_10M              (1)
#define GPIO_OUTPUT_OD_10M              (5)
#define GPIO_OUTPUT_AF_PP_10M           (9)
#define GPIO_OUTPUT_AF_OD_10M           (13)

#define GPIO_OUTPUT_PP_2M               (2)
#define GPIO_OUTPUT_OD_2M               (6)
#define GPIO_OUTPUT_AF_PP_2M            (10)
#define GPIO_OUTPUT_AF_OD_2M            (14)

#define GPIO_OUTPUT_PP_50M              (3)
#define GPIO_OUTPUT_OD_50M              (7)
#define GPIO_OUTPUT_AF_PP_50M           (11)
#define GPIO_OUTPUT_AF_OD_50M           (15)

/*pins values*/
#define GPIO_LOW                        (0)
#define GPIO_HIGH                       (1)

/*lock status*/
#define GPIO_UNLOCKED_PIN               (0)
#define GPIO_LOCKED_PIN                 (1)


/******************************Functions' Prototypes******************************/

/*this function is to set the direction of a pin */
void GPIO_voidSetPinDirection(u8 Copyu8Port , u8 Copyu8Pin , u8 Copyu8Mode);

/*this function is to set the value of output pins*/
void GPIO_voidSetOutputPinValue(u8 Copyu8Port , u8 Copyu8Pin , u8 Copyu8Value ) ;

/*this function is to get the value of an input pin*/
u8 GPIO_u8GetPinValue(u8 Copyu8Port , u8 Copyu8Pin);

/*this function is to set or reset pins using BSRR & BRR registers*/
void GPIO_voidSetFastPinValue(u8 Copyu8Port , u8 Copyu8Pin , u8 Copyu8Value ) ;

/*this function is to set a certain value to a port using ODR register*/
void GPIO_voidSetPortValue(u8 Copyu8Port , u32 Copyu32Value);

/*this function is to lock or unlock a pin in a port*/
void GPIO_voidLockStatus(u8 Copyu8Port , u8 Copyu8Pin , u8 Copyu8Value);

/*this function is to toggle led value*/
void GPIO_voidToggleLed(u8 Copyu8Port , u8 Copyu8Pin) ;
#endif

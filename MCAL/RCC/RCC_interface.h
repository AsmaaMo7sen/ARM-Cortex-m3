/*****************************************************************************************/
/*        Author  : asmaa                                                                */
/*        Date    : 8March2022                                                           */
/*        Version : V01                                                                  */
/*                  V02 : redefinition of registers using struct                         */
/*        Description  : this file contains interfacing information                      */
/*****************************************************************************************/


/*Header File Guard*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


/*Buses macros*/
#define RCC_AHB              (0)
#define RCC_APB1             (1)
#define RCC_APB2             (2)

/*AHB bus peripherals*/
#define RCC_AHB_SDIO         (10)
#define RCC_AHB_FSMC         (8)
#define RCC_AHB_CRC          (6)
#define RCC_AHB_FLITF        (4)
#define RCC_AHB_SRAM         (2)
#define RCC_AHB_DMA2         (1)
#define RCC_AHB_DMA1         (0)


/*APB1 bus peripherals*/
#define RCC_APB1_DAC         (29)
#define RCC_APB1_PWR         (28)
#define RCC_APB1_BKP         (27)
#define RCC_APB1_CAN         (25)
#define RCC_APB1_USB         (23)
#define RCC_APB1_I2C2        (22)
#define RCC_APB1_I2C1        (21)
#define RCC_APB1_UART5       (20)
#define RCC_APB1_UART4       (19)
#define RCC_APB1_UART3       (18)
#define RCC_APB1_UART2       (17)
#define RCC_APB1_SPI3        (15)
#define RCC_APB1_SPI2        (14)
#define RCC_APB1_WWDG        (11)
#define RCC_APB1_TIM14       (8)
#define RCC_APB1_TIM13       (7)
#define RCC_APB1_TIM12       (6)
#define RCC_APB1_TIM7        (5)
#define RCC_APB1_TIM6        (4)
#define RCC_APB1_TIM5        (3)
#define RCC_APB1_TIM4        (2)
#define RCC_APB1_TIM3        (1)
#define RCC_APB1_TIM2        (0)


/*APB2 bus periphals*/
#define RCC_APB2_TIM11       (21)
#define RCC_APB2_TIM10       (20)
#define RCC_APB2_TIM9        (19)
#define RCC_APB2_ADC3        (15)
#define RCC_APB2_USART1      (14)
#define RCC_APB2_TIM8        (13)
#define RCC_APB2_SPI1        (12)
#define RCC_APB2_TIM1        (11)
#define RCC_APB2_ADC2        (10)
#define RCC_APB2_ADC1        (9)
#define RCC_APB2_IOPG        (8)
#define RCC_APB2_IOPF        (7)
#define RCC_APB2_IOPE        (6)
#define RCC_APB2_IOPD        (5)
#define RCC_APB2_IOPC        (4)
#define RCC_APB2_IOPB        (3)
#define RCC_APB2_IOPA        (2)
#define RCC_APB2_AFIO        (0)



/*this function is to select a system clock*/
void RCC_voidInitSystemClock(void) ;

/*this function is to enable clock over a certain peripheral*/
void RCC_voidEnableClock (u8 Copy_u8BusId , u8 Copy_u8PeripheralId);

/*this fucntion is to disable clock over a certain peripheral*/
void RCC_voidDisableClock (u8 Copy_u8BusId , u8 Copy_u8PeripheralId) ;


#endif

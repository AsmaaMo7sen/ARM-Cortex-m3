/*
 * Author : asmaa
 * Date : 4April2022
 * Version : V01
 * Description : this file contains interfacing information of SysTick peripheral
 */

/*Header File Guard*/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/****************************Interfacing Macros****************************/
/*input clock for systick*/
#define STK_SRC_AHB            (1)
#define STK_SRC_AHB_BY_8       (0)

/*enable/disable systick/interrupt*/
#define ENABLE                 (1)
#define DISABLE                (0)



/****************************Functions' Prototypes****************************/

/*this function is to initialize systick with certain clock source [AHB | AHB/8] */
void STK_voidInit();

/*this function is to run systick in scynchronous mode*/
/*used for delay functionality*/
void STK_voidSetBusyWait(u32 COPY_u32Ticks );

/*this function is to run the systick for a single interval in ascynchronous mode and generate an interrupt*/
void STK_voidSetIntervalSingle(u32 COPY_u32Ticks , void (*ptr)(void));

/*this function is to run the systick for a repeated interval in ascynchronous mode and generate an interrupt*/
void STK_voidSetIntervalPeriodic(u32 COPY_u32Ticks , void (*ptr)(void));

/*this function is to stop counting*/
void STK_voidStopSystick(void);

/*this function is to get the remainig time*/
u32 STK_u32GetRemainingTime(void);

/*this function is to get the ellapsed time*/
u32 STK_u32GetEllapsedTime(void);





#endif

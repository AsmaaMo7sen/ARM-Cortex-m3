/*****************************************************************************************/
/*     Author  : asmaa                                                                   */
/*     Date    : 8March2022                                                              */
/*     Version : V01                                                                     */
/*     Description : this file contains standard bit math operations                     */
/*****************************************************************************************/


/*Header File Guard*/
#ifndef BIT_MATH_H
#define BIT_MATH_H


/*this function is to set a specific bit in a specific register*/
#define SET_BIT(REG, BIT)           REG |= (1<<(BIT))

/*this function is to clear a specific bit in a specific register*/
#define CLR_BIT(REG,BIT)           REG &= ~(1<<(BIT))

/*this function is to toggle a specific bit in a specific register*/
#define TOGGLE_BIT(REG,BIT)   REG ^= (1<<BIT)

/*this function is to get the value of a specific bit in a register*/
#define GET_BIT(REG,BIT)           ((REG>>BIT) & 1)


#endif

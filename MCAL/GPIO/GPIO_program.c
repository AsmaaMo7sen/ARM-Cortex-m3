/****************************************************************************************/
/*     Author      : asmaa                                                              */
/*     Date        :14March2022                                                         */
/*     Version     :V01                        											*/
/*     V02 at 23March2022: a new function to set value of pins with BSRR & BRR          */
/*                          + another 1 to set port value with ODR                      */
/*                          + another 1 to lock bits                                    */
/*     V03 at 1April : added toggle led function                                        */
/*     V04 at 8April : redefinition of registers using struct                           */
/*     Description :this file contains logical implementation of functions              */
/****************************************************************************************/

/*includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void GPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
  /*switching over ports*/
  switch(Copy_u8Port)
  {
     /*in case of port A*/
     case GPIO_PORTA :

    	  if (Copy_u8Pin <8)
    	  {
    		  GPIOA->CRL &= ~((0b1111) << (Copy_u8Pin *4));   //resetting target bits to add new value
    		  GPIOA->CRL |= (Copy_u8Mode << (Copy_u8Pin*4)); //setting target mode into target bits
    	  }
    	  else if (Copy_u8Pin >=8 && Copy_u8Pin <=15 )
    	  {
    		  Copy_u8Pin = Copy_u8Pin - 8;
    		  GPIOA->CRH &= ~((0b1111) << (Copy_u8Pin *4));   //resetting target bits to add new value
    		  GPIOA->CRH |= (Copy_u8Mode << (Copy_u8Pin*4)); //setting target mode into target bits
    	  }
    	  else
    	  {
    		  /*do nothing*/
    	  }

      	 /*breaking from port A case*/
        	 break ;


      /*in case of port B*/
	  case GPIO_PORTB :

    	  if (Copy_u8Pin <8)
    	  {
    		  GPIOB->CRL &= ~((0b1111) << (Copy_u8Pin *4));   //resetting target bits to add new value
    		  GPIOB->CRL |= (Copy_u8Mode << (Copy_u8Pin*4)); //setting target mode into target bits
    	  }
    	  else if (Copy_u8Pin >=8 && Copy_u8Pin <=15 )
    	  {
    		  Copy_u8Pin = Copy_u8Pin - 8;
    		  GPIOB->CRH &= ~((0b1111) << (Copy_u8Pin *4));   //resetting target bits to add new value
    		  GPIOB->CRH |= (Copy_u8Mode << (Copy_u8Pin*4)); //setting target mode into target bits
    	  }
    	  else
    	  {
    		  /*do nothing*/
    	  }

	  	 /*breaking from port B case*/
	    	 break ;


      /*in case of port C*/
	  case GPIO_PORTC :

    	  if (Copy_u8Pin <8)
    	  {
    		  Copy_u8Pin = Copy_u8Pin - 8;
    		  GPIOC->CRL &= ~((0b1111) << (Copy_u8Pin *4));   //resetting target bits to add new value
    		  GPIOC->CRL |= (Copy_u8Mode << (Copy_u8Pin*4)); //setting target mode into target bits
    	  }
    	  else if (Copy_u8Pin >=8 && Copy_u8Pin <=15 )
    	  {
    		  GPIOC->CRH &= ~((0b1111) << (Copy_u8Pin *4));   //resetting target bits to add new value
    		  GPIOC->CRH |= (Copy_u8Mode << (Copy_u8Pin*4)); //setting target mode into target bits
    	  }
    	  else
    	  {
    		  /*do nothing*/
    	  }

		 /*breaking from port C case*/
			 break ;

	  default :
		  break ;
  }


	/*return from this function*/
	return ;

}

/***************************************************************************************************/

void GPIO_voidSetOutputPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value )
{
	/*switching over ports*/
    switch(Copy_u8Port)
    {

    /*in case of port A*/
    case GPIO_PORTA :

    	/*switching over possible output values*/
    	switch(Copy_u8Value)
    	{
    	  /*in case of low output*/
    	  case GPIO_LOW :

    		  /*clearing target bit to get low output*/
    		  CLR_BIT(GPIOA->ODR , Copy_u8Pin);

    		  /*break from this case*/
    		  break ;

          /*in case of low output*/
		  case GPIO_HIGH :

			  /*setting target bit to get low output*/
			  SET_BIT(GPIOA->ODR , Copy_u8Pin);

			  /*break from this case*/
			  break ;
		  default :
			  break ;

    	}

    	/*break from this case*/
    	 break ;

    /*in case of port B*/
    case GPIO_PORTB :

    	/*switching over possible output values*/
		switch(Copy_u8Value)
		{
		  /*in case of low output*/
		  case GPIO_LOW :

			  /*clearing target bit to get low output*/
			  CLR_BIT(GPIOB->ODR , Copy_u8Pin);

			  /*break from this case*/
			  break ;

		  /*in case of low output*/
		  case GPIO_HIGH :

			  /*setting target bit to get low output*/
			  SET_BIT(GPIOB->ODR , Copy_u8Pin);

			  /*break from this case*/
			  break ;
		  default :
			  break ;
		}

    	/*break from this case*/
       	 break ;

    /*in case of port C*/
    case GPIO_PORTC :

        /*switching over possible output values*/
		switch(Copy_u8Value)
		{
		  /*in case of low output*/
		  case GPIO_LOW :

			  /*clearing target bit to get low output*/
			  CLR_BIT(GPIOC->ODR , Copy_u8Pin);

			  /*break from this case*/
			  break ;

		  /*in case of low output*/
		  case GPIO_HIGH :

			  /*setting target bit to get low output*/
			  SET_BIT(GPIOC->ODR , Copy_u8Pin);

			  /*break from this case*/
			  break ;
		  default :
			  break ;
		}
    	/*break from this case*/
       	 break ;

	  default :
		  break ;
    }


	/*return from this function*/
	return ;
}


u8 GPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	 /*local variable to get the value of target pin*/
     u8	Local_u8Result = 0 ;


 	/*switching over ports*/
     switch(Copy_u8Port)
     {

     /*in case of port A*/
     case GPIO_PORTA :

    	 /*getting pin value*/
    	 Local_u8Result = GET_BIT(GPIOA->IDR , Copy_u8Pin) ;

    	 /*break from this case*/
    	break ;

     /*in case of port B*/
	 case GPIO_PORTB :

		 /*getting pin value*/
		 Local_u8Result = GET_BIT(GPIOB->IDR , Copy_u8Pin) ;

	    /*break from this case*/
	    break ;

	 /*in case of port C*/
	 case GPIO_PORTC :

		 /*getting pin value*/
		 Local_u8Result = GET_BIT(GPIOC->IDR , Copy_u8Pin) ;

	    /*break from this case*/
	    break ;

	  default :
		  break ;

     }
	/*return from this function*/
	return Local_u8Result ;
}


void GPIO_voidSetFastPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value )
{
	/*switching over ports*/
	switch(Copy_u8Port)
	{
	    /*in case of port A*/
		case GPIO_PORTA :

			switch(Copy_u8Value)  //switching over output values
			{
				case GPIO_HIGH :     //in case of high output

					SET_BIT(GPIOA->BSRR , Copy_u8Pin);  //writing 1 for setting pin

					break ;          //break from case of high output

				case GPIO_LOW :      //in case of low output

					SET_BIT(GPIOA->BRR , Copy_u8Pin);   //writing 1 for clearing pin

					break ;          //break from case of low output

				default :            //in case of default
					break ;          //do nothing and break
			}

			/*break from case of port A*/
			break ;

		/*in case of port B*/
		case GPIO_PORTB :

			switch(Copy_u8Value)  //switching over output values
			{
				case GPIO_HIGH :     //in case of high output

					SET_BIT(GPIOB->BSRR , Copy_u8Pin);  //writing 1 for setting pin

					break ;          //break from case of high output

				case GPIO_LOW :      //in case of low output

					SET_BIT(GPIOB->BRR , Copy_u8Pin);   //writing 1 for clearing pin

					break ;          //break from case of low output

				default :            //in case of default
					break ;          //do nothing and break
			}
			/*break from case of port B*/
			break ;

		/*in case of port C*/
		case GPIO_PORTC :

			switch(Copy_u8Value)  //switching over output values
			{
				case GPIO_HIGH :     //in case of high output

					SET_BIT(GPIOC->BSRR , Copy_u8Pin);  //writing 1 for setting pin

					break ;          //break from case of high output

				case GPIO_LOW :      //in case of low output

					SET_BIT(GPIOC->BRR , Copy_u8Pin);   //writing 1 for clearing pin

					break ;          //break from case of low output

				default :            //in case of default
					break ;          //do nothing and break
			}
			/*break from case of port C*/
			break ;

		/*in case of default*/
		default :
			/*do nothing and break*/
			break ;
	}


	/*return from this function*/
	return ;
}

/***************************************************************************************/

void GPIO_voidSetPortValue(u8 Copy_u8Port , u32 Copy_u16Value)
{
    /*switching over ports*/
	switch(Copy_u8Port)
	{
		case GPIO_PORTA : //in case of port A

			GPIOA->ODR = Copy_u16Value ; //setting target value to the port

			break ;       //break from case of port A

		case GPIO_PORTB : //in case of port B

			GPIOB->ODR = Copy_u16Value ; //setting target value to the port

			break ;       //break from case of port B

		case GPIO_PORTC : //in case of port C

			GPIOC->ODR = Copy_u16Value ; //setting target value to the port

			break ;       //break from case of port C

		default :         //in case of default
			break ;       //do nothing and break

	}

	/*return from this function*/
	return ;
}

/***********************************************************************************/
void GPIO_voidLockStatus(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
    /*switching over ports*/
	switch(Copy_u8Port)
	{
		case GPIO_PORTA : //in case of port A
			switch(Copy_u8Value)
			{
				case GPIO_UNLOCKED_PIN :
					CLR_BIT(GPIOA->LCKR ,Copy_u8Pin); //clearing pin to unlock it
					break ;

				case GPIO_LOCKED_PIN :
					SET_BIT(GPIOA->LCKR ,Copy_u8Pin); //writing 1 to lock a pin
					break ;

				default :         //in case of default
					break ;       //do nothing and break

			}
			break ;       //break from case of port A


		case GPIO_PORTB : //in case of port B
			switch(Copy_u8Value)
			{
				case GPIO_UNLOCKED_PIN :
					CLR_BIT(GPIOB->LCKR ,Copy_u8Pin); //clearing pin to unlock it
					break ;

				case GPIO_LOCKED_PIN :
					SET_BIT(GPIOB->LCKR ,Copy_u8Pin); //writing 1 to lock a pin
					break ;

				default :         //in case of default
					break ;       //do nothing and break
			}
			break ;       //break from case of port B


		case GPIO_PORTC : //in case of port C
			switch(Copy_u8Value)
			{
				case GPIO_UNLOCKED_PIN :
					CLR_BIT(GPIOC->LCKR ,Copy_u8Pin); //clearing pin to unlock it
					break ;

				case GPIO_LOCKED_PIN :
					SET_BIT(GPIOC->LCKR ,Copy_u8Pin); //writing 1 to lock a pin
					break ;

				default :         //in case of default
					break ;       //do nothing and break
			}
			break ;       //break from case of port C

		default :         //in case of default
			break ;       //do nothing and break
	}
	/*return from this function*/
	return ;
}

void GPIO_voidToggleLed(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	/*switching over ports*/
	switch(Copy_u8Port)
	{
	    /*in case of port A*/
		case GPIO_PORTA :

			TOGGLE_BIT(GPIOA->ODR , Copy_u8Pin); //Toggling the pin value

			/*break from case of port A*/
			break ;

	    /*in case of port B*/
		case GPIO_PORTB :

			TOGGLE_BIT(GPIOB->ODR , Copy_u8Pin); //Toggling the pin value

			/*break from case of port B*/
			break ;

		/*in case of port C*/
		case GPIO_PORTC :

			TOGGLE_BIT(GPIOC->ODR , Copy_u8Pin); //Toggling the pin value

			/*break from case of port C*/
			break ;

		default :
			break ;
	}

	/*return from this function*/
	return ;
}


/********************************************************************/
 /******************************************************************/
 /* 		Title : STEPPERMOTOR Program File                      */
 /*		Author: Ahmed Mohamed Fathy (Ahmed Omda)				   */	
 /* 		Last Update: 19 Aug 2021						       */
 /******************************************************************/
/********************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "STEPPERMOTOR_int.h"
#include "STEPPERMOTOR_config.h"
#include "STEPPERMOTOR_private.h"


#include <avr/delay.h>  //for delay

void STEPPERMOTOR_void_Init(void)
{
	#if(STEPPERMOTOR_u8_MODE == STEPPERMOTOR_FULL_STEP)
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin1, DIO_u8HIGH);
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin1, DIO_u8LOW);
	
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin2, DIO_u8HIGH);
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin2, DIO_u8LOW);
	
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin3, DIO_u8HIGH);
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin3, DIO_u8LOW);

	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin4, DIO_u8HIGH);
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin4, DIO_u8LOW);

	#elif(STEPPERMOTOR_u8_MODE == STEPPERMOTOR_HALF_STEP)
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin1, DIO_u8HIGH); // 0001
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin2, DIO_u8HIGH); // 0011
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin1, DIO_u8LOW);  // 0010
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin3, DIO_u8HIGH); // 0110
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin2, DIO_u8LOW);  // 0100
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin4, DIO_u8HIGH); // 1100
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin3, DIO_u8LOW);  // 1000
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin1, DIO_u8HIGH); // 1001
	_delay_ms(100);
	DIO_void_SetPinValue(STEPPERMOTOR_u8_CoilPin4, DIO_u8LOW);  // 0001

	#endif

}

void STEPPERMOTOR_void_SET_DIR(void)
{

	#if(STEPPERMOTOR_u8_DIR == STEPPERMOTOR_Counter_Clock_Wise)
	// Turn One Side CCW
	for (int j=0,i =0; j<48; j++)
	{
	  PORTC = (1<<i);
	  i++;
	  _delay_ms(100);  // StepDelay
	  if (i==4)
		  i=0;
	}

    #elif(STEPPERMOTOR_u8_DIR == STEPPERMOTOR_Clock_Wise)
	// Turn The Other Side CCW
	for (int j=0,i=0; j<48; j++)
	{
	  PORTC = (8>>i);
	  i++;
	  _delay_ms(100);  // StepDelay
	  if (i==4)
		  i=0;
	}

    #endif
}

void STEPPERMOTOR_void_SET_POS()
{
	
}

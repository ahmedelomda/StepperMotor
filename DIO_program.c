/********************************************************************/
 /******************************************************************/
 /* 		Title : DIO Peripheral Program File                    */
 /*		Author: Ahmed Mohamed Fathy (Ahmed Omda)				   */	
 /* 		Last Update: 16 Aug 2021						       */
 /******************************************************************/
/********************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_private.h"

#include <avr/delay.h>  //for delay

int arr[10] = {zero,one,two,three,four,five,sex,seven,eight,nine};

void DIO_void_Init(void)
{
	DDRA = DIO_u8PORTA_DIR;
	DDRB = DIO_u8PORTB_DIR;
	DDRC = DIO_u8PORTC_DIR;
	DDRD = DIO_u8PORTD_DIR;

}

void DIO_void_SetPinValue(u8 Copy_u8_PinNo, u8 Copy_u8_PinValue)
{
	if( (Copy_u8_PinNo >= DIO_u8_PORTA_Start ) && (Copy_u8_PinNo <= DIO_u8_PORTA_End) )
	{
		if(Copy_u8_PinValue == DIO_u8HIGH)
		{
			SET_BIT(PORTA, Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8LOW)
		{
			CLEAR_BIT(PORTA, Copy_u8_PinNo);
		}
	}
	
	if( (Copy_u8_PinNo >= DIO_u8_PORTB_Start ) && (Copy_u8_PinNo <= DIO_u8_PORTB_End) )
	{
		/*Get valid range for PORTB Pins*/
		Copy_u8_PinNo = Copy_u8_PinNo - DIO_u8_PORT_Size;

		if(Copy_u8_PinValue == DIO_u8HIGH)
		{
			SET_BIT(PORTB, Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8LOW)
		{
			CLEAR_BIT(PORTB, Copy_u8_PinNo);
		}
	}
	
	if( (Copy_u8_PinNo >= DIO_u8_PORTC_Start ) && (Copy_u8_PinNo <= DIO_u8_PORTC_End) )
	{
		/*Get valid range for PORTC Pins*/
		Copy_u8_PinNo = Copy_u8_PinNo - (DIO_u8_PORT_Size*2);

		if(Copy_u8_PinValue == DIO_u8HIGH)
		{
			SET_BIT(PORTC, Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8LOW)
		{
			CLEAR_BIT(PORTC, Copy_u8_PinNo);
		}
	}
	
	if( (Copy_u8_PinNo >= DIO_u8_PORTD_Start ) && (Copy_u8_PinNo <= DIO_u8_PORTD_End) )
	{
		/*Get valid range for PORTD Pins*/
		Copy_u8_PinNo = Copy_u8_PinNo - (DIO_u8_PORT_Size*3);

		if(Copy_u8_PinValue == DIO_u8HIGH)
		{
			SET_BIT(PORTD, Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8LOW)
		{
			CLEAR_BIT(PORTD, Copy_u8_PinNo);
		}
	}
}

u8 DIO_u8_GetPinValue(u8 Copy_u8_PinNo)
{
	u8 Local_u8Result;
	
	if( (Copy_u8_PinNo >= DIO_u8_PORTA_Start ) && (Copy_u8_PinNo <= DIO_u8_PORTA_End) )
		{
			Local_u8Result = GET_BIT(PINA,Copy_u8_PinNo);

			if(Local_u8Result == DIO_u8HIGH)
			{
				Local_u8Result = DIO_u8HIGH;
			}
			else
			{
				Local_u8Result = DIO_u8LOW;
			}
		}

	if( (Copy_u8_PinNo >= DIO_u8_PORTB_Start ) && (Copy_u8_PinNo <= DIO_u8_PORTB_End) )
	{
		/*Get valid range for PORTB Pins*/
		Copy_u8_PinNo = Copy_u8_PinNo - DIO_u8_PORT_Size;
		Local_u8Result = GET_BIT(PINB,Copy_u8_PinNo);

		if(Local_u8Result == DIO_u8HIGH)
		{
			Local_u8Result = DIO_u8HIGH;
		}
		else
		{
			Local_u8Result = DIO_u8LOW;
		}
	}

	if( (Copy_u8_PinNo >= DIO_u8_PORTC_Start ) && (Copy_u8_PinNo <= DIO_u8_PORTC_End) )
	{
		/*Get valid range for PORTC Pins*/
		Copy_u8_PinNo = Copy_u8_PinNo - (DIO_u8_PORT_Size*2);
		Local_u8Result = GET_BIT(PINC,Copy_u8_PinNo);

		if(Local_u8Result == DIO_u8HIGH)
		{
			Local_u8Result = DIO_u8HIGH;
		}
		else
		{
			Local_u8Result = DIO_u8LOW;
		}
	}

	if( (Copy_u8_PinNo >= DIO_u8_PORTD_Start ) && (Copy_u8_PinNo <= DIO_u8_PORTD_End) )
	{
		/*Get valid range for PORTD Pins*/
		Copy_u8_PinNo = Copy_u8_PinNo - (DIO_u8_PORT_Size*3);
		Local_u8Result = GET_BIT(PIND,Copy_u8_PinNo);

		if(Local_u8Result == DIO_u8HIGH)
		{
			Local_u8Result = DIO_u8HIGH;
		}
		else
		{
			Local_u8Result = DIO_u8LOW;
		}
	}

	return Local_u8Result;
}

void traffic_stop_lightening(void)
{
	for(int i=9; i>=0; i--)
	{
		PORTC = arr[i];
		_delay_ms(50);
	}
}

void traffic_go_lightening(void)
{
	for(int i=9; i>=0; i--)
	{
		PORTD = arr[i];
		_delay_ms(50);
	}
}

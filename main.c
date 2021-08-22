#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "STEPPERMOTOR_int.h"

#include <avr/delay.h>

#define F_CPU 8000000   //define CPU 8Mega frequency Hertz

int main(void)
{
	DIO_void_Init();


	while(1)
	{
		//STEPPERMOTOR_void_Init();
		STEPPERMOTOR_void_SET_DIR();
	}

	return 0;
}



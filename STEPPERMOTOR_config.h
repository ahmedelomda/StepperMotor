/********************************************************************/
 /******************************************************************/
 /* 		Title : STEPPERMOTOR Cofigration File                  */
 /*		Author: Ahmed Mohamed Fathy (Ahmed Omda)				   */	
 /* 		Last Update: 19 Aug 2021						       */
 /******************************************************************/
/********************************************************************/

#ifndef STEPPERMOTOR_CONFIG_H_
#define STEPPERMOTOR_CONFIG_H_


#define STEPPERMOTOR_u8_CoilPin1 	 DIO_u8Pin16  //input 
#define STEPPERMOTOR_u8_CoilPin2     DIO_u8Pin17
#define STEPPERMOTOR_u8_CoilPin3	 DIO_u8Pin18
#define STEPPERMOTOR_u8_CoilPin4	 DIO_u8Pin19


#define STEPPERMOTOR_u8_MODE   		 STEPPERMOTOR_FULL_STEP
#define STEPPERMOTOR_u8_DIR			 STEPPERMOTOR_Counter_Clock_Wise

#endif  //STEPPERMOTOR_CONFIG_H_

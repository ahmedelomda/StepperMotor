/********************************************************************/
 /******************************************************************/
 /* 		Title : DIO Peripheral Private File                    */
 /*		Author: Ahmed Mohamed Fathy (Ahmed Omda)				   */	
 /* 		Last Update: 16 Aug 2021						       */
 /******************************************************************/
/********************************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DIO_u8PORTA_DIR  CONC_BIT(DIO_u8_DIR_Pin7, DIO_u8_DIR_Pin6, DIO_u8_DIR_Pin5, DIO_u8_DIR_Pin4, DIO_u8_DIR_Pin3, DIO_u8_DIR_Pin2, DIO_u8_DIR_Pin1, DIO_u8_DIR_Pin0)

#define DIO_u8PORTB_DIR  CONC_BIT(DIO_u8_DIR_Pin15, DIO_u8_DIR_Pin14, DIO_u8_DIR_Pin13, DIO_u8_DIR_Pin12, DIO_u8_DIR_Pin11, DIO_u8_DIR_Pin10, DIO_u8_DIR_Pin9, DIO_u8_DIR_Pin8)

#define DIO_u8PORTC_DIR  CONC_BIT(DIO_u8_DIR_Pin23, DIO_u8_DIR_Pin22, DIO_u8_DIR_Pin21, DIO_u8_DIR_Pin20, DIO_u8_DIR_Pin19, DIO_u8_DIR_Pin18, DIO_u8_DIR_Pin17, DIO_u8_DIR_Pin16)

#define DIO_u8PORTD_DIR  CONC_BIT(DIO_u8_DIR_Pin31, DIO_u8_DIR_Pin30, DIO_u8_DIR_Pin29, DIO_u8_DIR_Pin28, DIO_u8_DIR_Pin27, DIO_u8_DIR_Pin26, DIO_u8_DIR_Pin25, DIO_u8_DIR_Pin24)

#define PORTA_Address	(0x3B)
#define DDRA_Address	(0x3A)
#define PINA_Address	(0x39)

#define PORTB_Address   (0x38)
#define DDRB_Address	(0x37)
#define PINB_Address	(0x36)

#define PORTC_Address   (0x35)
#define DDRC_Address	(0x34)
#define PINC_Address	(0x33)

#define PORTD_Address	(0x32)
#define DDRD_Address	(0x31)
#define PIND_Address	(0x30)

#define PORTA 	*((volatile u8*)PORTA_Address)
#define DDRA 	*((volatile u8*)DDRA_Address)
#define PINA 	*((volatile u8*)PINA_Address)

#define PORTB 	*((volatile u8*)PORTB_Address)
#define DDRB 	*((volatile u8*)DDRB_Address)
#define PINB 	*((volatile u8*)PINB_Address)

#define PORTC 	*((volatile u8*)PORTC_Address)
#define DDRC 	*((volatile u8*)DDRC_Address)
#define PINC 	*((volatile u8*)PINC_Address)

#define PORTD 	*((volatile u8*)PORTD_Address)
#define DDRD 	*((volatile u8*)DDRD_Address)
#define PIND 	*((volatile u8*)PIND_Address)

/*Digital I/O Direction*/
#define DIO_u8INPUT     0
#define DIO_u8OUTPUT    1

/*Useful Definition*/
#define DIO_u8_PORTA_Start     0
#define DIO_u8_PORTA_End       7
#define DIO_u8_PORTB_Start     8
#define DIO_u8_PORTB_End	   15
#define DIO_u8_PORTC_Start     16
#define DIO_u8_PORTC_End	   23
#define DIO_u8_PORTD_Start     24
#define DIO_u8_PORTD_End	   31
#define DIO_u8_PORT_Size       8

/* number in binary*/
#define zero 0b00111111
#define one 0b00000110
#define two 0b01011011
#define three 0b01001111
#define four 0b01100110
#define five 0b01101101
#define sex 0b01111101
#define seven 0b00000111
#define eight 0b01111111
#define nine 0b01100111

#endif //DIO_PRIVATE_H_

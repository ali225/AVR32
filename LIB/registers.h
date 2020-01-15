/*
  Author:  Khaled Hossam
  Date:    8/24/2019
  Version: 1.0
*/

#ifndef REGISTERS_H
#define REGISTERS_H

/**************** Status Register ****************/
/*************************************************/
#define SREG (*((volatile unsigned char *) 0x5F))

/**************** DIO Registers ****************/
/***********************************************/

#define DDRA (*((volatile unsigned char *) 0x3A))
#define PORTA (*((volatile unsigned char *) 0x3B))
#define PINA (*((volatile unsigned char *) 0x39))

#define DDRB (*((volatile unsigned char *) 0x37))
#define PORTB (*((volatile unsigned char *) 0x38))
#define PINB (*((volatile unsigned char *) 0x36))

#define DDRC (*((volatile unsigned char *) 0x34))
#define PORTC (*((volatile unsigned char *) 0x35))
#define PINC (*((volatile unsigned char *) 0x33))

#define DDRD (*((volatile unsigned char *) 0x31))
#define PORTD (*((volatile unsigned char *) 0x32))
#define PIND (*((volatile unsigned char *) 0x30))

/**************** External Interrupt Registers ****************/
/**************************************************************/

#define MCUCR (*((volatile unsigned char *) 0x55))
#define MCUCSR (*((volatile unsigned char *) 0x54))
#define GICR (*((volatile unsigned char *) 0x5B))
#define GIFR (*((volatile unsigned char *) 0x5A))

/**************** Timer 0 Registers ***************************/
/**************************************************************/

#define TCCR0 (*((volatile unsigned char *) 0x53))
#define TCNT0 (*((volatile unsigned char *) 0x52))
#define OCR0 (*((volatile unsigned char *) 0x5C))
#define TIMSK (*((volatile unsigned char *) 0x59))
#define TIFR (*((volatile unsigned char *) 0x58))

/**************** ADC Registers *******************************/
/**************************************************************/

#define ADMUX   *((volatile u8*) 0x27)
#define ADCSRA  *((volatile u8*) 0x26)
#define ADCH    *((volatile u8*) 0x25)
#define ADCL    *((volatile u8*) 0x24)
#define SFIOR   *((volatile u8*) 0x50)
/**************** WDG Registers *******************************/
/**************************************************************/

#define WDTCR   *((volatile u8*) 0x41)


/**************** Timer 1 Registers ***************************/
/**************************************************************/

#define TCCR1A (*((volatile unsigned char *) 0x4F))
#define TCCR1B (*((volatile unsigned char *) 0x4E))
#define TCNT1H (*((volatile unsigned char *) 0x4D))
#define TCNT1L (*((volatile unsigned char *) 0x4C))
#define OCR1AH (*((volatile unsigned char *) 0x4B))
#define OCR1AL (*((volatile unsigned char *) 0x4A))
#define OCR1BH (*((volatile unsigned char *) 0x49))
#define OCR1BL (*((volatile unsigned char *) 0x48))
#define ICR1H (*((volatile unsigned char *) 0x47))
#define ICR1L (*((volatile unsigned char *) 0x48))

/**************** UART Registers *******************************/
/**************************************************************/
#define UDR  	*((volatile u8*) 0x2C)
#define UCSRA   *((volatile u8*) 0x2B)
#define UCSRB   *((volatile u8*) 0x2A)
#define UBRRL  	*((volatile u8*) 0x29)
#define UBRRH  	*((volatile u8*) 0x40)
#define UCSRC   *((volatile u8*) 0x40)

/************* SPI Registers ********************************/
/**************************************************************/

#define SPCR     *((volatile u8*) 0x2D)
#define SPSR     *((volatile u8*) 0x2E)
#define SPDR     *((volatile u8*) 0x2F)

#endif

/*
 * timer2_main.c
 *
 *  Created on: Jan 17, 2020
 *      Author: Eng Ali Gamal
 */
/*

#include <avr/io.h>
#include <avr/interrupt.h>



void Timer0_CTC_Square_Wave_Init(void)
{
	TCNT0 = 0; // initial value 0
	OCR0 = 250; // compare value
	DDRD = DDRD| (1<<PD6); // OC0 Pin as output pin
	 Configure timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. Toggle OC0 on compare match COM00=1 & COM01=0
	 * 4. clock = CPU clock CS00=1 CS01=0 CS02=0

	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS00);
}

int main(void)
{
	Timer0_CTC_Square_Wave_Init();
    while(1)
    {

    }
}
*/


/*

#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2

unsigned char g_tick = 0;

 Interrupt Service Routine for timer0 compare mode
ISR(TIMER0_COMP_vect)
{
	g_tick++;
	if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
	{
		PORTD = PORTD ^ (1<<PD7); //toggle led every 0.5 second
		g_tick = 0; //clear the tick counter again to count a new 0.5 second
	}
}

 For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so we just need 250 counts to get 250ms every overflow. put initial timer counter=0
 * and output compare register=250 0 --> 250 (250ms per overflow)
 * so we need timer to overflow 2 times to get a 0.5 second


void timer0_init_CTC_mode(unsigned char tick)
{
	TCNT0 = 0; //timer initial value
	OCR0  = tick; //compare value
	TIMSK |= (1<<OCIE0); //enable compare interrupt
	 Configure timer0 control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1

	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
}

int main(void)
{
	DDRD  |= (1<<PD7);         // configure the led pin to be output pin.
	PORTD &= ~(1<<PD7);        // LED is off at the beginning(Positive Logic).
	SREG  |= (1<<7);           // enable global interrupts in MC.
	timer0_init_CTC_mode(250); // start the timer.
    while(1)
    {

    }
}

*/

/*
 #define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2

 unsigned char g_tick = 0;



 ISR(TIMER0_OVF_vect){

 g_tick++;
 if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
 {
 PORTD = PORTD ^ (1<<PC6); //toggle led every 0.5 second
 g_tick = 0; //clear the tick counter again to count a new 0.5 second
 }
 }

 Description :
 * For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so put initial timer counter=0  0 --> 255 (256ms per overflow)
 * so we need timer to overflow 2 times to get a 0.5 second

 void timer0_init_normal_mode(void)
 {
 TCNT0 = 0; //timer initial value
 TIMSK |= (1<<TOIE0); //enable overflow interrupt
 Configure the timer control register
 * 1. Non PWM mode FOC0=1
 * 2. Normal Mode WGM01=0 & WGM00=0
 * 3. Normal Mode COM00=0 & COM01=0
 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1

 TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
 }

 int main(void)
 {
 DDRD  |= (1<<PD6); //configure the led pin to be output pin.
 PORTD &= ~(1<<PD6); //LED is off at the beginning(Positive Logic).
 SREG  |= (1<<7); //enable global interrupts in MC by setting the I-Bit.
 timer0_init_normal_mode(); //start the timer.
 while(1)
 {

 }
 }*/

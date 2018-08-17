#include<avr/io.h>
#include<avr/interrupt.h>

void Timer0_Init (void)
{
	SREG |= (1<<7);
	TCCR0 |= (1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS00);
	TCNT0 = 0;
	OCR0 = 128;

}

int main (void)
{
	Timer0_Init();
	DDRB |= (1<<PB3);
	while(1){}
}

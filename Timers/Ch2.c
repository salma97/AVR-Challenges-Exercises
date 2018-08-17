#include<avr/io.h>
#include<avr/interrupt.h>

void timer0_init (void)
{
	TCCR0 |= (1<<CS01) | (1<<COM01) | (1<<WGM00) | (1<<WGM01);
	SREG |= (1<<7);
	TCNT0 = 0;
	OCR0 = 128;
}

int main (void)
{
	timer0_init();
	DDRB |= (1<<PB3);
	while(1) {}
}

#include<avr/io.h>
#include<avr/interrupt.h>

unsigned char tick=0;

ISR (TIMER0_COMP_vect)
{
	tick++;
	if(tick == 2)
	{
		tick = 0;
		PORTC = PORTC ^ (1<<PC0);
	}
}

void Timer0_Init (void)
{
	SREG |= (1<<7);
	TCCR0 |= (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
	TIMSK |= (1<<OCIE0);
	TCNT0 = 0;
	OCR0 = 250;
}

int main(void)
{
	Timer0_Init();
	DDRC |= (1<<PC0);
	PORTC &= (~(1<<PC0));

	while(1){}
}

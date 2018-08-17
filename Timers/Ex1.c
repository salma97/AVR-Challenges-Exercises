#include<avr/io.h>
#include<avr/interrupt.h>

unsigned char tick = 0;

ISR (TIMER0_OVF_vect)
{
	tick++;
	if(tick == 2)
	{
		tick = 0;
		PORTC = PORTC ^ (1<<PC0);
	}
}

void TIMER0_Init (void)
{
	TCCR0 |=(1<<FOC0) | (1<<CS02) | (1<<CS00);
	TCNT0 = 0;
	TIMSK |= (1<<TOIE0);
}

int main (void)
{
	SREG |= (1<<7);
	TIMER0_Init();
	DDRC |= (1<<PC0);
	PORTC &= (~(1<<PC0));

	while(1){
	}
}

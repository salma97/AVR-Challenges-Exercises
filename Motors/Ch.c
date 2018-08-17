#include<avr/io.h>
#include<avr/interrupt.h>

int steps [8] = {8,12,4,6,2,3,1,9};
int i = 0, tick = 0;

void Timer0_Init (void)
{
	TCCR0 |= (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
	SREG |= (1<<7);
	TCNT0 = 0;
	OCR0 = 250;
	TIMSK |= (1<<OCIE0);
}

ISR (TIMER0_COMP_vect)
{
	tick++;
	if(tick == 2)
	{
		tick = 0;
		if (i == 8)
		{
			i = 0;
			PORTC = (PORTC & 0xF0) | (steps[i] & 0x0F);
		}
		else
		{
			PORTC = (PORTC & 0xF0) | (steps[i] & 0x0F);
		}
		i++;
	}
}

int main (void)
{
	DDRC |= 0x0F;
	PORTC &= 0xF0;
	Timer0_Init();

	while(1){}
}

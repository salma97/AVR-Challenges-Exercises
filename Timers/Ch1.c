#include<avr/io.h>
#include<avr/interrupt.h>

unsigned char tick = 0;

ISR (TIMER0_OVF_vect)
{
	TCNT0 = 6;
	tick++;
	if(tick == 123)
	{
		if(PORTC == 9)
		{
			PORTC = 0x00;
			tick = 0;
		}
		else
		{
			PORTC++;
			tick = 0;
		}
	}
}

void Timer0_Init (void)
{
	TCCR0 |= (1<<FOC0) | (1<<CS02);
	TCNT0 = 6;
	SREG |= (1<<7);
	TIMSK |= (1<<TOIE0);
}

int main (void)
{
	Timer0_Init();
	DDRC = 0xFF;
	PORTC = 0x00;

	while(1) {}
}

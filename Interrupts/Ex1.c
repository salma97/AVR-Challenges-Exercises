#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

ISR (INT0_vect)
{
	PORTC = PORTC ^ (1<<PC0);
}

void INT0_Init (void)
{
	SREG |= (1<<7);
	GICR |= (1<<INT0);
	MCUCR |= (1<<ISC00) | (1<<ISC01);
	DDRD &= (~(1<<PD2));
}

int main (void)
{
	INT0_Init();

	DDRC |= (1<<PC0);
	PORTC |= (1<<PC0);

	while(1)
	{
	}

}

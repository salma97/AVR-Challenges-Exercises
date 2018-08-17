#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

unsigned char num = 0;

ISR (INT2_vect)
{
	if((PORTC & 0x0F) == 9)
	{
		num = 0;
		PORTC = (PORTC & 0xF0) | (num & 0x0F);
	}
	else
	{
		num++;
		PORTC = (PORTC & 0xF0) | (num & 0x0F);
	}
}

int main (void)
{
	DDRC = 0x0F;
	PORTC = 0x00;

	DDRB &= (~(1<<PB2));
	SREG |= (1<<7);
	GICR |= (1<<INT2);
	MCUCSR |= (1<<ISC2);

	while(1)
	{

	}
}

#include<avr/io.h>
#include<avr/interrupt.h>
#include<avr/delay.h>

unsigned char i;

ISR (INT1_vect)
{
	for(i = 0; i < 5; i++)
	{
		PORTC = 0xFF;
		_delay_ms(500);
		PORTC = 0x00;
		_delay_ms(500);
	}
}

void INT1_Init (void)
{
	DDRD &= (~(1<<PD3));
	SREG |= (1<<7);
	GICR |= (1<<INT1);
	MCUCR |= (1<<ISC11) | (1<<ISC10);
}

int main (void)
{
	INT1_Init();

	DDRC = 0xFF;
	PORTC = 0x01;

	while(1)
	{
		_delay_ms(500);

		if(PORTC == 0)
			PORTC = 0x01;
		else
			PORTC = (PORTC << 1);

	}
}

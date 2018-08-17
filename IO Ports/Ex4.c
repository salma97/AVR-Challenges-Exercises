#include<avr/io.h>
#include<util/delay.h>

unsigned char flag;

int main (void)
{
	DDRB &= (~(1<<PB0));
	PORTB |= (1<<PB0);

	DDRC |= (1<<PC0);
	PORTC |= (1<<PC0);

	while(1)
	{
		if(!(PINB & (1<<PB0)))
		{
			_delay_ms (30);
			if((!(PINB & (1<<PB0))) && flag==0)
			{
				PORTC ^= (1<<PC0);
				flag = 1;
			}
		}
		else
		{
			flag = 0;
		}
	}
}

#include <avr/io.h>
#include<util/delay.h>

int main (void)
{
	DDRA &= ~(1<<PA3);
	DDRC |= (1<<PC5);

	PORTC = PORTC & ~(1<<5);

	while (1)
	{
		if(PINA & (1<<PA3))
		{
			_delay_ms(30);
			if(PINA & (1<<PA3))
			{
				PORTC |= (1<<PC5);
			}
		}

		else
		{
			PORTC &= ~(1<<PC5);
		}
	}
}

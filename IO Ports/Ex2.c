#include <avr/io.h>
#include<util/delay.h>

int main (void)
{
	DDRD |= (1<<PD6);

	PORTD = PORTD | (1<<6);

	while (1)
	{
		PORTD &= (~(1<<6));
		_delay_ms(1000);
		PORTD |= (1<<6);
		_delay_ms(1000);
	}
}

#include<avr/io.h>
#include<util/delay.h>

int main (void)
{
	DDRC = 0xFF;
	PORTC = 0x01;

	while(1)
	{
		_delay_ms(500);

		if(PORTC & (1<<PC7))
		{
			PORTC = 0x01;
		}
		else
		{
			PORTC = (PORTC << 1);
		}
	}
}

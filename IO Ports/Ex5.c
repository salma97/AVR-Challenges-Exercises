#include<avr/io.h>
#include<util/delay.h>

int  main (void)
{
	DDRD &= (~(1<<PD4));
	DDRC |= (1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3);

	PORTC = PORTC & 0xF0;

	unsigned num = 0, flag = 0;

	while(1)
	{
		if(PIND & (1<<PD4))
		{
			_delay_ms(30);
			if(PIND & (1<<PD4) && flag==0)
			{
				flag = 1;

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
		}
		else
		{
			flag = 0;
		}
	}
}

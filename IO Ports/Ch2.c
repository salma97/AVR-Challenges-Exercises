#include<avr/io.h>
#include<util/delay.h>

int main (void)
{

	DDRA &= (~(1<<0));
	DDRA &= (~(1<<1));
	DDRD |= 0x0F;
	PORTD &= 0xF0;

	unsigned char flag = 0;
	unsigned char num = 0;

	while(1)
	{
		if((PINA & (1<<0)))
		{
			_delay_ms(30);

			if((PINA & (1<<0)) && flag == 0)
			{
				flag = 1;

				if((PORTD & 0x0F) == 9)
				{

				}
				else
				{
					num++;
					PORTD = (PORTD & 0xF0) | (num & 0x0F);
				}
			}
		}

		else if((PINA & (1<<1)))
		{
			_delay_ms(30);

			if((PINA & (1<<1)) && flag == 0)
			{
				flag = 1;

				if((PORTD & 0x0F) == 0)
				{

				}
				else
				{
					num--;
					PORTD = (PORTD & 0xF0) | (num & 0x0F);
				}
			}
		}
		else
		{
			flag = 0;
		}
	}
}

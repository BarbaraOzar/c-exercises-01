/*
 * exe_5.c
 *
 * Created: 2018-04-10 11:06:02
 * Author : Barbara
 */ 

#define F_CPU 10000000L
#include <avr/io.h>
#include <util/delay.h>
int i, prime;

int main(void)
{
	DDRA = 0xff;
	DDRB = 0x00;
	PORTA = 0xff;
	
    for(int n = 2; n <= 100; n++) 
	{	z 
		prime = 1;
		i = 2;
		
		while(i <= sqrt(n))
		{
			if(n % i == 0)
				prime = 0;
			i++;
		}
		if(prime)
		{
			PORTA &= ~n;
			_delay_ms(1000);
			PORTA = 0xff;
			_delay_ms(1000);
			
			while(PINB == 0xff)			// wait for a button press
			{}
		}
	}
	PORTA = 0xff;
}


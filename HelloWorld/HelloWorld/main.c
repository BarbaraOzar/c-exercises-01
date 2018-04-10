
#define F_CPU 10000000L
#include <avr/io.h>
#include <util/delay.h>

void led_on(int led_no) ;
void led_off(int led_no);

int main(void)
{
    DDRA = 0xff;				// setting all I/O's in port A as outputs
	PORTA = 0xff;				// turning all leds off
	
	while(1) 
	{
		led_on(3);
		_delay_ms(500);
		led_off(3);
		_delay_ms(500);
	}	
}

void led_on(int led_no) 
{
	PORTA &= ~(1<<led_no);      // turning on led
}

void led_off(int led_no)
{
	PORTA |= 1<<led_no;			// turning off led
}
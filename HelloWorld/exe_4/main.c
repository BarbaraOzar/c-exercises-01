/*
 * exe_4.c
 *
 * Created: 2018-04-10 10:51:48
 * Author : Barbara
 */ 

#define F_CPU 10000000L
#include <avr/io.h>
#include <util/delay.h>
int led = 0;

void led_on(int led_no) ;
void led_off(int led_no);

int main(void)
{
	DDRA = 0xff;				// setting all I/O's in port A as outputs
	PORTA = 0xff;				// turning all leds off
	
	while(led != 8)
	{
		led_on(led);
		_delay_ms(1000);
		led_off(led);
		led++;
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


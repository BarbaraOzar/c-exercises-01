/*
 * exe_7.c
 *
 * Created: 2018-04-16 17:07:52
 * Author : Barbara
 */ 

#define F_CPU 10000000L
#include <avr/io.h>
#include <util/delay.h>

void increment_time(int *time);
void decrement_time(int *time);
void start(int *started, int *time, int *count_to);
void stop(int *started);
void reset(int *time);
void get_input(int *started, int *time, int *count_to);
void output(int value);
void timer_done(int *started, int *time);

int main(void)
{
    int time = 0, started = 0, count_to = 0xff;
	
	DDRA = 0xff;
	DDRB = 0x00;
	PORTA = 0xff;
			
	output(1); // control led
	
	PORTA = ~count_to;	// display to what timer counts
	
	while(1) 
	{
		while(PINB == 0xff)						// wait for a button press
		{}
		get_input(&started, &time, &count_to);
		output(1);								// control led
		PORTA = ~count_to;						// display to what timer counts
	}
}

void increment_time(int *time) 
{
	*time += 1;
}

void decrement_time(int *time) // not used in case of counter counting up
{
	*time -= 1;
}

void start(int *started, int *time, int *count_to)
{
	while(*time <= *count_to && *started) 
	{
		output(*time);
		get_input(started, time, count_to);
		increment_time(time);
	}
	if(*time > *count_to)
		timer_done(started, time);
}

void stop(int *started)
{
	*started = 0;
}

void reset(int *time)
{
	*time = 0;	
}

void get_input(int *started, int *time, int *count_to)
{	
	PORTA = 0xff;
	
	if(PINB == (0xff - 0x01) && !*started) 
	{
		output(0xfe);	// the counting starts
		*started = 1;
		start(started, time, count_to);
	}
	else if(PINB == (0xff - 0x01) && *started) 
	{
		output(0xff);	// counter has been stopped, but not reset
		stop(started);
	}
	else if(PINB == (0xff - 0x40) && !*started)
	{
		*count_to -= 50;
	}
	else if(PINB == (0xff - 0x80) && !*started)
	{
		*count_to += 50;		
	}
	else if(PINB == (0xff - 0xc0))
		reset(time);
	else
		return;
}

void output(int value)
{
	PORTA = ~value;
	_delay_ms(1000);
	PORTA = 0xff;
}

void timer_done(int *started, int *time)
{
	stop(started);
	reset(time);
	int repeat = 0;
	
	while(repeat < 3)
	{	
		PORTA = 0x00;
		_delay_ms(300);
		PORTA = 0xff;
		_delay_ms(300);
		repeat++;
	}
}
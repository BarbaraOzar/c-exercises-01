/*
 * hello_world.c
 *
 * Created: 2018-04-17 09:51:20
 * Author : Dell
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "atmega2560_drivers.h"
#include <stdio.h>

int main(void)
{
	init_stdio(0, 10000000L);
	sei();
    printf("hello world");
	while(1)
	{
		
	}
}


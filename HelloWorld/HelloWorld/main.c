
#define F_CPU 10000000L
#include <avr/io.h>


int main(void)
{
    DDRA = 0xff;            // setting all I/O's in port A as outputs
    PORTA = ~(1<<PA3);      // turning on led 3 (active low)
}

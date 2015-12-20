#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#define LED D
#define GLUE(a, b) a##b
#define LEDPORT1(s) GLUE(PORT,s)
#define LEDPORT LEDPORT1(LED)
#define LEDDDR1(s) GLUE(DDR,s)
#define LEDDDR LEDDDR1(LED)
#define KL PB1

const uint8_t DP=0x7f;

const uint8_t DIGITS[] PROGMEM = {
		0xC0,	// 0
			0xF9,	// 1
			0xA4,	// 2
			0xB0,	// 3
			0x99,	// 4
			0x92,	// 5
			0x82,	// 6
			0xD8,	// 7
			0x80,	// 8
			0x90,	// 9
};

int main()
{
LEDDDR=0xFF;
PORTB|=_BV(PB1) | _BV(PB0);

uint8_t x=0;
while(1)
{
ShowOnLED(x);
x=(x+1)%10;
_delay_ms(1000);
}
}

void ShowOnLED(uint8_t val)
{
uint8_t tmp=0x00;
if((val )<=10) tmp=pgm_read_byte(&DIGITS[val]);
else tmp=0x80;
LEDPORT=tmp;
}

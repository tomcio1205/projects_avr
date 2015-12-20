#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#define LED D
#define GLUE(a, b) a##b
#define LEDPORT1(s) GLUE(PORT,s)
#define LEDPORT LEDPORT1(LED)
#define LEDDDR1(s) GLUE(DDR,s)
#define LEDDDR LEDDDR1(LED)
#define DIG1 PB0
#define DIG2 PB1
#define DIG3 PB2
#define MINUS PC0


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
			0x290,	// 9
};

int main()
{
uint8_t a,b,c;
LEDDDR=0xFF;
DDRB  |= (1<<DIG1) | (1<<DIG2) | (1<<DIG3);
DDRC |= (1<<MINUS);
int x=345;
while(1)
{

	if(x>0 & x<100){
		a=x%10;
		b=x/10;
		ShowOnLED1(a);
		ShowOnLED2(b);
	}
	if(x>=100 & x<700){
		a=x%10;
		c=x/100;
		b=(x-c*100)/10;
		ShowOnLED1(a);
	    ShowOnLED2(b);
	    ShowOnLED3(c);
	    PORTC |= (1<<MINUS);
		}
}
}

void ShowOnLED1(uint8_t val)
{
uint8_t tmp=0x00;
	tmp=pgm_read_byte(&DIGITS[val]);
	PORTB |=(1<<DIG3);
	LEDPORT=tmp;
	_delay_ms(2);
	PORTB ^=(1<<DIG3);
}
void ShowOnLED2(uint8_t val)
{
uint8_t tmp=0x00;
	PORTB |=(1<<DIG2);
	tmp=pgm_read_byte(&DIGITS[val]);
	LEDPORT=tmp & 0x7F;
	_delay_ms(2);
	PORTB ^=(1<<DIG2);
}
void ShowOnLED3(uint8_t val)
{
uint8_t tmp=0x00;
	PORTB |=(1<<DIG1);
	tmp=pgm_read_byte(&DIGITS[val]);
	LEDPORT=tmp;
	_delay_ms(2);
	PORTB ^=(1<<DIG1);
}

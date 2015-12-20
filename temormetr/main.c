#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include<stdlib.h>
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


#define PIN_1WIRE 5
#define PORT_1WIRE PINC
#define OUT_1WIRE_LOW PORT_1WIRE&=~(1<<PIN_1WIRE);
#define OUT_1WIRE_HIGH PORT_1WIRE |= 1<<PIN_1WIRE;
#define DIR_1WIRE_IN DDRC&=~(1<<PIN_1WIRE);
#define DIR_1WIRE_OUT DDRC |=1<<PIN_1WIRE;
#define DIG1 PB0
#define DIG2 PB1
#define DIG3 PB2
#define MINUS PC0

char cStringBuffer[8];

unsigned char uc1Wire_ResetPulse(void)
{
	unsigned char ucPresenceImpulse;

	OUT_1WIRE_LOW;
	DIR_1WIRE_OUT;
	_delay_us(300);
	DIR_1WIRE_IN;
	_delay_us(45);

	if (bit_is_clear(PORT_1WIRE, PIN_1WIRE))
		ucPresenceImpulse=1;
	else
		ucPresenceImpulse=0;
	_delay_us(270);

	return ucPresenceImpulse;
}

void v1Wire_SendBit(char cBit)
{
	DIR_1WIRE_OUT;
	_delay_us(5);
	if(cBit==1)
		DIR_1WIRE_IN;
	_delay_us(80);
	DIR_1WIRE_IN;
}

unsigned char uc1Wire_ReadBit(void)
{
	unsigned char ucBit;

	DIR_1WIRE_OUT;
	_delay_us(2);
	DIR_1WIRE_IN;
	_delay_us(15);
	if(bit_is_set(PORT_1WIRE, PIN_1WIRE))
		ucBit=1;
	else
		ucBit=0;
	return(ucBit);
}

void v1Wire_SendByte(char ucByteValue)
{
	unsigned char ucCounter;
	unsigned char ucValueToSend;

	for (ucCounter=0; ucCounter<8; ucCounter++)
	{
		ucValueToSend = ucByteValue>>ucCounter;
		ucValueToSend &= 0x01;
		v1Wire_SendBit(ucValueToSend);
	}
	_delay_us(80);
}

unsigned char uv1Wire_ReadByte(void)
{
	unsigned char ucCounter;
	unsigned char ucReadByte = 0;

	for (ucCounter=0; ucCounter<8; ucCounter++)
	{
		if (uc1Wire_ReadBit())
			ucReadByte |= 0x01<<ucCounter;
		_delay_us(15);
	}
	return (ucReadByte);
}

int main(void)
{
	uint8_t a,b,c;
		int x;
		LEDDDR=0xFF;
		DDRB  |= (1<<DIG1) | (1<<DIG2) | (1<<DIG3);
		DDRC |= (1<<MINUS);

	unsigned char ucReset;
	char cTemperatureH=0, cTemperatureL=0;
	float fTemperature=0;

	 //LCD_Initalize();   //inicjalizacja LCD
     //LCD_GoTo(0, 0);      //Ustawienie kursora w pozycji (0,0)
    // LCD_WriteText("1-WIRE");
    // _delay_ms(200);

     while(1)
     {
    	 ucReset=uc1Wire_ResetPulse();
    	 if (ucReset==1)     //Ustawienie kursora w pozycji (0,0)
    	 {
    		 v1Wire_SendByte(0xCC);
    		 v1Wire_SendByte(0x44);
    		// _delay_ms(750);
    		 ucReset=uc1Wire_ResetPulse();
    		 v1Wire_SendByte(0xCC);
    		 v1Wire_SendByte(0xBE);
    		 cTemperatureL=uv1Wire_ReadByte();
    		 cTemperatureH=uv1Wire_ReadByte();
    		 ucReset=uc1Wire_ResetPulse();

    		 fTemperature=(float)(cTemperatureL+(cTemperatureH<<8))/16;
    		 dtostrf(fTemperature,1,1,cStringBuffer);
    		x=fTemperature*10;
    		x=abs(x);
    		 //	 x=225;
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


           //  _delay_ms(200);
       	 }
    	 else
    	 {
    		// LCD_GoTo(1,0);
             //LCD_WriteText("Cisza");
    	 }
     }


}
void ShowOnLED2(uint8_t val)
{
uint8_t tmp=0x00;
	PORTB |=(1<<DIG2);
	tmp=pgm_read_byte(&DIGITS[val]);
	LEDPORT=tmp & 0x7F;
	_delay_ms(2.5);
	PORTB ^=(1<<DIG2);
}
void ShowOnLED3(uint8_t val)
{
uint8_t tmp=0x00;
	PORTB |=(1<<DIG1);
	tmp=pgm_read_byte(&DIGITS[val]);
	LEDPORT=tmp;
	_delay_ms(2.5);
	PORTB ^=(1<<DIG1);
}
void ShowOnLED1(uint8_t val)
{
uint8_t tmp=0x00;
	tmp=pgm_read_byte(&DIGITS[val]);
	PORTB |=(1<<DIG3);
	LEDPORT=tmp;
	_delay_ms(2.5);
	PORTB ^=(1<<DIG3);
}





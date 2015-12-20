#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "HD44780.h"
#include <avr/pgmspace.h>

#define PIN_1WIRE 5
#define PORT_1WIRE PINC
#define OUT_1WIRE_LOW PORT_1WIRE&=~(1<<PIN_1WIRE);
#define OUT_1WIRE_HIGH PORT_1WIRE |= 1<<PIN_1WIRE;
#define DIR_1WIRE_IN DDRD&=~(1<<PIN_1WIRE);
#define DIR_1WIRE_OUT DDRD |=1<<PIN_1WIRE;


char cStringBuffer[8];

unsigned char uc1Wire_ResetPulse(void)
{
	unsigned char ucPresenceImpulse;

	OUT_1WIRE_LOW;
	DIR_1WIRE_OUT;
	_delay_us(500);
	DIR_1WIRE_IN;
	_delay_us(45);

	if (bit_is_clear(PORT_1WIRE, PIN_1WIRE))
		ucPresenceImpulse=1;
	else
		ucPresenceImpulse=0;
	_delay_us(470);

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
	_delay_us(100);
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
	unsigned char ucReset;
	char cTemperatureH=0, cTemperatureL=0;
	float fTemperature=0;

	 LCD_Initalize();   //inicjalizacja LCD
     LCD_GoTo(0, 0);      //Ustawienie kursora w pozycji (0,0)
     LCD_WriteText("1-WIRE");
     _delay_ms(200);

     while(1)
     {
    	 ucReset=uc1Wire_ResetPulse();
    	 if (ucReset==1)     //Ustawienie kursora w pozycji (0,0)
    	 {
    		 v1Wire_SendByte(0xCC);
    		 v1Wire_SendByte(0x44);
    		 _delay_ms(750);
    		 ucReset=uc1Wire_ResetPulse();
    		 v1Wire_SendByte(0xCC);
    		 v1Wire_SendByte(0xBE);
    		 cTemperatureL=uv1Wire_ReadByte();
    		 cTemperatureH=uv1Wire_ReadByte();
    		 ucReset=uc1Wire_ResetPulse();

    		 fTemperature=(float)(cTemperatureL+(cTemperatureH<<8))/16;
    		 dtostrf(fTemperature,1,1,cStringBuffer);
    		 LCD_GoTo(0,1);
             LCD_WriteText(cStringBuffer);

             _delay_ms(200);
       	 }
    	 else
    	 {
    		 LCD_GoTo(1,0);
             LCD_WriteText("Cisza");
    	 }
     }


}





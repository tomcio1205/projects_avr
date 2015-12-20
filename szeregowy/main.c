#include<avr/io.h>
#include<util/delay.h>
#include"USART.h"

int main (void)
{
	char serialCharacter;

	DDRD=0b11111100;
	initUSART();
	printString("---Wyslij 2 lub 4----\r\n");

	while(1)
	{
		serialCharacter=receiveByte();
		if(serialCharacter==2)
		{
			printString("---Wyslales 2---\r\n");
		}
		else if (serialCharacter==4)
		{
			printString("---Wyslales 4---\r\n");
		}
		else
		{
			printString("---Miales wyslac 2 lub 4---\r\n");
		}
		//transmitByte(serialCharacter);
		//PORTD=serialCharacter;
	}
}

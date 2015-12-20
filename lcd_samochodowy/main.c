#include <avr/io.h>
#include <util/delay.h>
#include "hd44780.h"

void paliwo(uint8_t, uint8_t);
void celsjusz(uint8_t);
void termometr(uint8_t);
void piorun(uint8_t);
void zegar(uint8_t);
int main()
{

	lcd_init();
	lcd_goto(0);
	lcd_puts("Zatankuj");
	//lcd_goto(8);
	paliwo(66,67);
	celsjusz(68);
	termometr(69);
	piorun(70);
	zegar(71);
	 //DO NOT FORGET to issue a GOTO command to go back to writing to the LCD
		//ddram OR you will spend hours like me thinking the LCD is locked up
		//when it working just fine and you are outputting to cgram instead of
		//ddram!

		 //Displays custom character 0

}
void paliwo (uint8_t x,uint8_t y){
	lcd_command(_BV(LCD_CGRAM)+0*8); //The 0 on this line may be 0-7
			lcd_putc(0b11110); //5x8 bitmap of character, in this example a backslash
			lcd_putc(0b10010);
			lcd_putc(0b10011);
			lcd_putc(0b11111);
			lcd_putc(0b11111);
			lcd_putc(0b11111);
			lcd_putc(0b11110);
			lcd_putc(0b11110);
			lcd_goto(x);
			lcd_putc(0);
			lcd_command(_BV(LCD_CGRAM)+1*8);
			lcd_putc(0b00000);
			lcd_putc(0b01100);
			lcd_putc(0b01100);
			lcd_putc(0b00000);
			lcd_putc(0b01100);
			lcd_putc(0b01100);
			lcd_putc(0b00000);
			lcd_putc(0b00000);
			lcd_goto(y);
			lcd_putc(1);
}
void celsjusz (uint8_t z){
	lcd_command(_BV(LCD_CGRAM)+3*8); //The 0 on this line may be 0-7
		lcd_putc(0b01000);
		lcd_putc(0b10100);
		lcd_putc(0b01000);
		lcd_putc(0b00011);
		lcd_putc(0b00100);
		lcd_putc(0b00100);
		lcd_putc(0b00100);
		lcd_putc(0b00011);
		lcd_goto(z);
		lcd_putc(3);
}
void termometr (uint8_t k){
	lcd_command(_BV(LCD_CGRAM)+4*8); //The 0 on this line may be 0-7
		lcd_putc(0b00100);
		lcd_putc(0b01010);
		lcd_putc(0b01011);
		lcd_putc(0b01010);
		lcd_putc(0b01010);
		lcd_putc(0b10001);
		lcd_putc(0b10001);
		lcd_putc(0b01110);
		lcd_goto(k);
		lcd_putc(4);
}
void piorun (uint8_t p){
	lcd_command(_BV(LCD_CGRAM)+5*8); //The 0 on this line may be 0-7
		lcd_putc(0b00001);
		lcd_putc(0b00010);
		lcd_putc(0b00100);
		lcd_putc(0b00010);
		lcd_putc(0b10100);
		lcd_putc(0b11000);
		lcd_putc(0b11100);
		lcd_putc(0b00000);
		lcd_goto(p);
		lcd_putc(5);
}
void zegar (uint8_t e){
	lcd_command(_BV(LCD_CGRAM)+6*8); //The 0 on this line may be 0-7
		lcd_putc(0b00000);
		lcd_putc(0b00000);
		lcd_putc(0b00000);
		lcd_putc(0b01110);
		lcd_putc(0b10101);
		lcd_putc(0b10111);
		lcd_putc(0b10001);
		lcd_putc(0b01110);
		lcd_goto(e);
		lcd_putc(6);
}


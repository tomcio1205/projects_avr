#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "hd44780.h"
#include "i2c.h"
#include "PCF8583.h"

uint8_t godz, min, sek, hsek;
uint8_t dzien, miesiac;
uint16_t rok;

int main(void)
{
	i2cInit();
        PCF8583_init();
       PCF8583_set_time(9, 55, 31, 0);
        PCF8583_set_date(13, 4, 2015);

	lcd_init();
	//lcd_puts("zzzz");
	char tekst [20];

        while(1)
        {
               PCF8583_get_time(&godz, &min, &sek, &hsek);
		PCF8583_get_date(&dzien, &miesiac, &rok);

		//lcd_clrscr();
		sprintf(tekst, "GODZ:   %2u:%02u:%02u", godz, min, sek);
		lcd_goto(0); //pierwsza linia
                lcd_puts(tekst);
               lcd_goto(64); //druga linia
             sprintf(tekst, "DATA: %2u-%02u-%04u", dzien, miesiac, rok);
                lcd_puts(tekst);
          //     _delay_ms(1000);
    }
}

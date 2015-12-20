#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "conf.c"

// Pętla główna
int main(void)
{
	//definicja portow do ktorych podlaczone sa czujniki jako wejscia
	DDRC &= ~ (1<<CZ1) | (1<<CZ2) | (1<<CZ3) | (1<<CZ4);
	DDRA &= ~ (1<<CZ5) | (1<<CZ6) | (1<<CZ7) | (1<<CZ8) | (1<<CZ9) | (1<<CZ10) | (1<<CZ11) | (1<<CZ12);
	//wlaczenie pull-upow
	PORTC |= (1<<CZ1) | (1<<CZ2) | (1<<CZ3) | (1<<CZ4);
	PORTA |= (1<<CZ5) | (1<<CZ6) | (1<<CZ7) | (1<<CZ8) | (1<<CZ9) | (1<<CZ10) | (1<<CZ11) | (1<<CZ12);
	//definicja portow do sterowania mostkiem jako wyjscia
	DDRD |= (1<<AIN2) | (1<<BIN1) | (1<<BIN2) |(1<<PW1) | (1<<PW2);
	//defincja portu do czujnika tsop jako wejscie
	DDRD &= ~ (1<<TSOP);
	//definicja portow do ktorych podlaczone sa ledy jako wyjscia
	DDRB  |= (1<<LED1) | (1<<LED2) | (1<<LED3) ;


    ICR1  = 1000;
    OCR1A = 0;
    OCR1B = 0;
	  //  TCCR1A = 0xA0;
	    TCCR1A = (1<<COM1A1)|(1<<COM1B1);
	  //  TCCR1B = 0x12;
	    TCCR1B = (1<<WGM13)|(1<<CS11);


   while (1) //Pętla główna
   {
	   OCR1A = OCR1B = 900;
	    PORTC |= (1<<AIN1);
	    PORTD |=(1<<BIN2);

      PORTB ^=(1<<LED2); //suma modulo 2 (XOR) stanu poprzedniego na porcie
                             //pinu LED1 (zmiana stanu na przeciwny)
     //  _delay_ms(300);

  //  PORTB ^=(1<<LED2); //suma modulo 2 (XOR) stanu poprzedniego na porcie
                             //pinu LED2 (zmiana stanu na przeciwny)

     //   _delay_ms(300); //opóźnienie 1000ms czyli 1s
    // PORTB |=(1<<LED3);
      _delay_ms(5000);
    }
}

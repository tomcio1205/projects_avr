#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//definicja LED1 (do którego pinu podłączony LED1)
#define LED1 PB4

//definicja LED2 (do którego pinu podłączony LED2)
#define LED2 PB3
#define LED3 PB2


// Pętla główna
int main(void)
{
    //########### I/O ######http://alekino.tv/filmy?rates[0]=8.0+-+9.0&rates[1]=9.0+-+10.0&p=3#####
    DDRB  |= (1<<LED1) | (1<<LED2) | (1<<LED1) ; //Ustawienie pinów sterujących diodami
                                         //jako wyjścia

    PORTB |= (1<<LED1);    //Ustawienie stanu wysokiego na wyjściu
                                 //sterującym LED1 (stan początkowy)
     //##########################

   while (1) //Pętla główna
   {

      PORTB ^=(1<<LED1); //suma modulo 2 (XOR) stanu poprzedniego na porcie
                             //pinu LED1 (zmiana stanu na przeciwny)
     //  _delay_ms(300);

    PORTB ^=(1<<LED2); //suma modulo 2 (XOR) stanu poprzedniego na porcie
                             //pinu LED2 (zmiana stanu na przeciwny)

        _delay_ms(300); //opóźnienie 1000ms czyli 1s
    // PORTB |=(1<<LED3);
      _delay_ms(1000);
    }
}

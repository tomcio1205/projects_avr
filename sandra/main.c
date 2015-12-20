#include <avr/io.h>
#include <util/delay.h>

//definicja LED1 (do którego pinu podłączony LED1)
#define LED1 PB0

//definicja LED2 (do którego pinu podłączony LED2)
#define LED2 PB1


// Pętla główna
void main(void)
{
    //########### I/O ###########
    DDRB  |= (1<<LED1) | (1<<LED2); //Ustawienie pinów sterujących diodami
                                         //jako wyjścia

    PORTB |= (1<<LED1);    //Ustawienie stanu wysokiego na wyjściu
                                 //sterującym LED1 (stan początkowy)
     //##########################

   while (1) //Pętla główna
   {

        PORTB ^=(1<<LED1); //suma modulo 2 (XOR) stanu poprzedniego na porcie
                             //pinu LED1 (zmiana stanu na przeciwny)

        PORTB ^=(1<<LED2); //suma modulo 2 (XOR) stanu poprzedniego na porcie
                             //pinu LED2 (zmiana stanu na przeciwny)

        _delay_ms(3000); //opóźnienie 1000ms czyli 1s
    }
}

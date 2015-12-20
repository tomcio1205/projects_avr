/*
   Naciśnij przycisk jak najszybciej po zapaleniu się diod LED.
   Twój czas reakcji zostanie wypisany przez port szeregowy.
*/

// ------- Preambuła -------- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "USART.h"

#include "support.h"

static inline void initTimer1(void) {
                               /* Tryb normalny (domyślny), samo zliczanie */
  TCCR1B |= (1 << CS11) | (1 << CS10);
  /* Szybkość zegara: 1 MHz / 64,
     każde tyknięcie to 64 mikrosekundy ~= 15.6 na ms  */
                                         /* Bez specjalnych trybów wyjścia */
}

int main(void) {
  char byte;
  uint16_t timerValue;

  // -------- Inicjalizacja --------- //

  initUSART();
  initTimer1();
  DDRD = 0b11111100;                      /* wszystkie diody LED są wyjściami */
  PORTB |= (1 << PB0);             /* włącz oporniki podciągające */

  printString("\r\nCzas reakcji:\r\n");
  printString("---------------\r\n");
  printString("Naciśnij klawisz, żeby zacząć.\r\n");

  // ------ Pętla zdarzeń ------ //
  while (1) {

    byte = receiveByte();                      /* naciśnij dowolny klawisz */
    printString("\r\nPrzygotuj się...");
    randomDelay();

    printString("\r\nJuż!\r\n");
    PORTD = 0b11111100;                                        /* zapal diody */
    TCNT1 = 0;                                          /* wyzeruj licznik */

    if ((PINB&(1<<PB0))==0) {												//(PINB&(1<<PB0))==0
          /* Przycisk naciśnięto równo z zapaleniem się diod. Podejrzane. */
      printString("Oszukujesz tylko siebie.\r\n");
    }
    else {
      // Czekaj aż przycisk zostanie naciśnięty, zapisz wartość licznika.
    	while(PINB & (1<<PB0));														//while(!(PINB & (1<<PB0)))
      timerValue = TCNT1>>4 ;
      /* każde tyknięcie to mniej więcej 1/16 milisekundy, możemy dzielić przesuwając bity */

      printMilliseconds(timerValue);
      printComments(timerValue);
    }

    // Zgaś diody i zacznij od początku.
    PORTD = 0b00000000;
    printString("Press any key to try again.\r\n");

  }                                               /* Koniec pętli zdarzeń */
  return (0);                      /* Ta instrukcja nie zostanie wykonana */
}

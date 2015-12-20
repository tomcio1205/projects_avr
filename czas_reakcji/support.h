
  /* Funkcje pomocjicze zwiększające czytelność głównego kodu */

                                                           /* dołączenia */
#include <util/delay.h>
#include <avr/io.h>
#include "USART.h"

                                   /* Prototypy funkcji z pliku support.c */

void printMilliseconds(uint16_t value);
  /* Na podstawie wartości w milisakundach, wypisuje liczbę sekund
     poprzez port szeregowy. Wykonuje konwersję znaków ASCII, dodaje 
     przecinek dziesiętny i usuwa wiodące zera.
   */

void printComments(uint16_t value);
            /* Na podstawie wartości w milisekundach ocenia Twoje reakcje */

void randomDelay(void);
                        /* Odczekuje "losowy" czas 1 - 3,5 sekundy */
                           /* Wymaga zainidjowanego i działającego licznika 1 */
  /* Nie jest to narpawdę losowe, ale bardzo trudne do przewidzenia --
     jak rzucanie monetą. */

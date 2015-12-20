                                      /* Prosty przykład modulacji impulsu */

// ------- Preambuła -------- //
#include <avr/io.h>                        /* Definicje pinów, portów itp. */
#include <util/delay.h>                          /* Funkcje marnujące czas */


#define LED_DELAY  30                                      /* mikrosekundy */

void pwmAllPins(uint8_t brightness) {
  uint8_t i;
  PORTD= 0b11111100;                                            /* włączenie */
  for (i = 0; i < 255; i++) {
    if (i >= brightness) {            /* po odczekaniu dość długiego czasu */
      PORTD = 0b00000000;                                          /* wyłączenie */
    }
    _delay_us(LED_DELAY);
  }
}

int main(void) {

  uint8_t brightness = 0;
  int8_t direction = 1;

  // -------- Inicjalizacja --------- //

  // Inicjowanie wszystkich diod
  DDRD = 0b11111100;
  // ------ Pętla zdarzeń ------ //
  while (1) {
    // Rozjaśnianie i przygaszanie
    if (brightness == 0) {
      direction = 1;
    }
    if (brightness == 255) {
      direction = -1;
    }
    brightness += direction;
    pwmAllPins(brightness);


   }                                               /* Koniec pętli zdarzeń */
  return (0);                       /* ta instrukcja nie zostanie wykonana */
}

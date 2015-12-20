
#include "support.h"

void printMilliseconds(uint16_t value) {
  /* Na podstawie wartości w milisakundach, wypisuje liczbę sekund
     poprzez port szeregowy. Wykonuje konwersję znaków ASCII, dodaje 
     przecinek dziesiętny i usuwa wiodące zera.
   */
  uint8_t digit;

  printString("\r\nZajęło Ci to ");
                                               /* sumowanie dziesiątek tysięcy */
  digit = 0;
  while (value >= 10000) {
    digit++;
    value -= 10000;
  }
  if (digit) {
    transmitByte('0' + digit);
  }
                                                   /* sumowanie tysięcy */
  digit = 0;
  while (value >= 1000) {
    digit++;
    value -= 1000;
  }
  transmitByte('0' + digit);

                            /* przecinek dziesiętny, ponieważ dzielimy przez 1000 */
  transmitByte('.');

                                                    /* sumowanie setek */
  digit = 0;
  while (value >= 100) {
    digit++;
    value -= 100;
  }
  transmitByte('0' + digit);
                                                        /* sumowanie dziesiątek */
  digit = 0;
  while (value >= 10) {
    digit++;
    value -= 10;
  }
  transmitByte('0' + digit);

  // Jednostki to już prosta sprawa.
  transmitByte('0' + value);

  printString(" sekund.\r\n");
}

void printComments(uint16_t value) {
            /* Na podstawie wartości w milisekundach ocenia Twoje reakcje */
  if (value > 2000) {
    printString("---->  Emmm...to jest miernik szybkości reakcji...\r\n");
  }
  else if (value > 1000) {
    printString("---->  Żart?\r\n");
  }
  else if (value > 500) {
    printString("---->  Powoli.\r\n");
  }
  else if (value > 250) {
    printString("---->  Łyknij jeszcze kawy.\r\n");
  }
  else if (value > 200) {
    printString("---->  Nieźle.\r\n");
  }
  else if (value >= 150) {
    printString("---->  Szybko.\r\n");
  }
  else if (value < 150) {
    printString("---->  Niesamowicie!\r\n");
  }
}

void randomDelay(void) {
                        /* Odczekuje "losowy" czas 1 - 3,5 sekundy */
                           /* Wymaga zainidjowanego i działającego licznika 1 */
  /* Nie jest to narpawdę losowe, ale bardzo trudne do przewidzenia --
     jak rzucanie monetą. */
  uint8_t randomTime;

  _delay_ms(1000);                              /* odczekaj przynajmniej 1 sekundę */
  randomTime = (uint8_t) TCNT1;
  /* rzutowanie 16-bitowego rejestru TCNT1 na liczbę 8-bitową 
     zachowuje jedynie 8 mniej znaczących bitów, tych podlegających najszybszym zmionom. */
  while (--randomTime) {
    _delay_ms(10);                      /* maksymalna wartość to 255 ~= 2.5 sek */
  }
}

#include <stddef.h>
#include<avr/io.h>

#define UDR0 UDR
#define UCSR0A UCSRA
#define UBRR0H UBRRH
#define UBRR0L UBRRL
#define U2X0 U2X
#define UCSR0B UCSRB
#define RXEN0 RXEN
#define TXEN0 TXEN
#define RXCIE0 RXCIE
#define UDRIE0 UDRIE
#define UCSR0C UCSRC
#define UMSEL0 UMSEL
#define UPM00 UPM0
#define USBS0 USBS
#define UCSZ00 UCSZ0
#define UCPOL0 UCPOL
#define UCSZ00 UCSZ0
#define UCSZ01 UCSZ1
#define UDRE0 UDRE
#define RXC0 RXC

static void uart_9600()
{
#define BAUD 9600
#include <util/setbaud.h>
		UBRRH=UBRRH_VALUE;
		UBRRL=UBRRL_VALUE;
#if USE_2X
		UCSRA|=(1<<U2X);
#else
		UCSRA &=~(1<<U2X);
#endif
}


static void uart_init()
{
	uart_9600();
	UCSRC=_BV(URSEL)|_BV(UCSZ0)|_BV(UCSZ1);
	UCSRB=_BV(TXEN)|_BV(RXEN)| _BV(RXCIE);
}

uint8_t rec_uart()
{
	while(!(UCSRA & _BV(RXC)));
	return UDR;
}

void send_uart(uint8_t byte)
{
	while(!(UCSRA & _BV(UDRE)));
	UDR=byte;
}

void transmitByte(uint8_t data) {
                                     /* Wait for empty transmit buffer */
  loop_until_bit_is_set(UCSRA, UDRE);
  UDR = data;                                            /* send data */
}

void printString(const char myString[]) {
  uint8_t i = 0;
  while (myString[i]) {
    transmitByte(myString[i]);
    i++;
  }
}

int main()
{
	uart_init();
	printString("witaj!\r\n");
	while(1)
	{
		send_uart(rec_uart());
	}
}

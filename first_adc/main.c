#include <avr/io.h>
#include <util/delay.h>

static void inline initADC(void)
{
	ADMUX|=(1<<REFS0)|(1<<MUX0)|(1<<MUX1); //NAPIECIE REFERENCYJNE NA AVCC/ POTENCJOMETR POD ADC3
	ADCSRA|=(1<<ADPS1)|(1<<ADPS0); // PRESKALER 8
	ADCSRA|=(1<<ADEN); //WLACZ ADC
	ADCSRA|=(1<<ADFR);//tryb ciaglej konwersji
}

int main (void)
{
	DDRD=0xff;     //diody
	uint8_t ledValue;
	uint16_t adcValue;
	uint8_t i;

	initADC();

	while(1){

	ADCSRA |= (1<<ADSC); //URUCHOM KONWERSJE
//	while(ADCSRA & (1<<ADSC)); //oczekuj na jej zakonczenie w przypadku pojedynczej konwersji
	adcValue=ADC; //odczytaj wynik
	ledValue=(adcValue>>7); //z 10 bitow potrzeba tylko 3 bo mamy 8 diod (na 3 bitach mozna zapisac 8 max)
	PORTD=0b00000000;
	for(i=0;i<=ledValue; i++){
		PORTD|=(1<<i);
	}
	_delay_ms(50);
	}

}

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "hd44780.h"

#define	 LKEY	!(PINB&_BV(PD0))
#define	 RKEY	!(PINB&_BV(PD1))
#define OKKEY	!(PINB&_BV(PD2))

#define GetAddr(ptr, field) (void*)pgm_read_word(((uint8_t*)ptr)+offsetof(struct _menuitem, field))
//zwraca wskaznik na podane pole w strukturze

uint8_t LCD_ROWS = 2;
uint8_t LCD_COLUMNS = 8; //lb znaków w wierszu

typedef void (*menuitemfuncptr)(); //typ wskaznikowy menuitemfuncptr

struct PROGMEM _menuitem
{
prog_char *text; // wskaznik do FLAsH w której znajduje sie tekst opisujacy dana pozycje menu
menuitemfuncptr menuitemfunc; //wskaznik do funkcji wywoływanej po wybraniu danej pozycji menu
const struct _menuitem *parent;//wskaznik do struktury _menuitem menu rodzica lub NULL jesli dane menu jest głównym
const struct _menuitem *submenu;//wskaznik do podmenu lub NULL jesli dana pozycja nie ma podmenu
const struct _menuitem *next;//wskaznik do kolejnej struktury o typie _menuitem, lub NULL jesli dana pozycja jest ostatnia
};

void menufunc1();
void menufunc2();
void menufunc3();
void menufunc4();
void menufunc5();
void menufunc6();
void menufunc7();
void Menu_Back();

prog_char txt1[]="Menu1";
prog_char txt2[]="Menu2";
prog_char txt3[]="Menu3";
prog_char txt4[]="Menu4";

prog_char txt5[]="PodmenuA1";
prog_char txt6[]="PodmenuA2";
prog_char txt7[]="PodmenuA3";

prog_char txt8[]="PodmenuB1";
prog_char txt9[]="PodmenuB2";
prog_char txt10[]="<z powrotem>";
prog_char txt11[]="F: ";

extern struct _menuitem PROGMEM menu;//wskaznik do pierwszego elementu menu

struct _menuitem menu;
struct _menuitem menuA1;
struct _menuitem menuB1;

struct _menuitem menuB3 PROGMEM = {txt10, Menu_Back, &menuB1, 0 , 0};
struct _menuitem menuB2 PROGMEM = {txt9, menufunc7, &menuB1, 0 , &menuB3};
struct _menuitem menuB1 PROGMEM = {txt8, menufunc6, &menuA1, 0 , &menuB2};

struct _menuitem menuA4 PROGMEM = {txt10, Menu_Back, &menuA1, 0 , 0};
struct _menuitem menuA3 PROGMEM = {txt7, menufunc5, &menuA1, 0 , &menuA4};
struct _menuitem menuA2 PROGMEM = {txt6, 0, &menuB1, &menuB1 , &menuA3};
struct _menuitem menuA1 PROGMEM = {txt5, menufunc4, &menu, 0 , &menuA2};

struct _menuitem menu3 PROGMEM = {txt4, menufunc3, &menu, 0 , 0};
struct _menuitem menu2 PROGMEM = {txt3, menufunc2, &menu, 0 , &menu3};
struct _menuitem menu1 PROGMEM = {txt2, 0, &menuB1, &menuA1 , &menu2};
struct _menuitem menu PROGMEM = {txt1, menufunc1, 0, 0 , &menu1};

static const struct _menuitem *currMenuPtr=&menu;//zmienna wskazujaca na pierwsyz element aktualnie wybranego menu
static int8_t menuindex; //zmienna wskazujaca na aktualnie wybrany element menu
static int8_t menufirstpos;//nr pozycji menu wyswietlanej w pierwszy wierszu LCD

const struct _menuitem *GetMenuItem(uint8_t index)
{
const struct _menuitem *tmpmenuitem=currMenuPtr;
while((tmpmenuitem)&&(index>0))
{
	tmpmenuitem=GetAddr(tmpmenuitem, next);
	index--;
}
return tmpmenuitem;
}

void Menu_Show()//func wysweitlajaca menu na podstawie zmiennych currmenuitem, menuindex oraz menufirstpos
{
	const struct _menuitem *tmpmenuitem=GetMenuItem(menufirstpos);

	uint8_t charcnt=1;
	lcd_goto(0);
	lcd_puts("lllll");
	if(GetAddr(tmpmenuitem, text))
	{
		lcd_puts(GetAddr(tmpmenuitem, text));
	}
//tmpmenuitem=GetAddr(tmpmenuitem, next);
}



void menufunc1()
{

}

void menufunc2()
{

}

void menufunc3()
{

}

void menufunc4()
{

}

void menufunc5()
{

}

void menufunc6()
{

}

void menufunc7()
{

}

void Menu_Back()
{

}


int main (void)
{
lcd_init();

Menu_Show();

}

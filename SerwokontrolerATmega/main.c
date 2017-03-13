/*
 * main.c
 *
 *  Created on: 16-12-2015
 *      Author: bartek
 */
/*
 * Serwokotroler jest budowany na potrzeby platformy Stewarta na rekrutacje do Synergii
 * Nie zawiera pamieci programu lub czegos podobnego
 * Dziala jedynie na zasadzie ustawiania serw wg danych przychodzacych z uart
 *
 * Timer0 odmierza czas 2.5ms, czyli okres serwa. W sekundzie jest takich 8 okresow, wiec max 8 serw
 *
 * Timer1 odmierza indywidualnie dla kazdego serwa czas trwania impulsu w okresie 2.5ms
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#include "Defines.h"

#define BAUD 57600       //tutaj podaj ¿¹dan¹ prêdkoœæ transmisji
#include <util/setbaud.h> //linkowanie tego pliku musi byæ
                          //po zdefiniowaniu BAUD

//funkcje
void Init(void);
void ZmienSerwo(void);
void WylaczSerwa(void);


//zmienne globalne
volatile unsigned char licznik_okresu = 0; // uzywana w Timer0, zeby odliczac okres 2.5ms
volatile unsigned char czy_zmienic_serwo = 0; // zmienna ktora mowi, czy zmienic serwo
volatile unsigned char czy_wylaczyc_serwa = 0; // wylacza serwa jak Timer1 zliczy do maksa
volatile unsigned int tiki_dla_serw[8];
volatile unsigned int tmp_tiki_dla_serw[8];
volatile signed char offset_tiki_dla_serw[] = {-7, 0, 3, -8, -10, 7};
volatile unsigned int tiki_dla_katow[181]; // wyliczane sa wartosci tikow dla katow -90...90 co 0.5 stopnia
unsigned char numer_serwa_do_zmiany = 0;
volatile char rec_data;
volatile char bajt_mlodszy, bajt_starszy;
volatile unsigned char rec_flag;
volatile unsigned char numer_serwa_odebranego = 0;
volatile unsigned char odebrano_dane = 1;
volatile char tab_indexow_serw[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'U'};
volatile int ile = 0;
volatile unsigned char CRC = 0;


//przerwanie od Timer0
ISR(TIMER0_OVF_vect)
{
	TCNT0 = 127;
	if(++licznik_okresu == 27) //uplynelo 2.5ms
	{
		licznik_okresu = 0;
		czy_zmienic_serwo = 1;
	}
}


//przerwanie od Timer1, ktory odmierza stan wysoki osobno dla kazdego serwa
ISR(TIMER1_OVF_vect)
{
	TCNT1 = 0;
	czy_wylaczyc_serwa = 1;
}

// wysylane sa zapytania o dane do serw
ISR(TIMER2_OVF_vect)
{
	TCNT2 = 150;
	if(odebrano_dane)
	{
		odebrano_dane = 0;
		UDR = tab_indexow_serw[numer_serwa_odebranego];
	}
}


ISR(USART_RXC_vect)
{
	//przerwanie generowane po odebraniu bajtu

	rec_data = UDR;   //zapamiêtaj odebran¹ liczbê
	ile++;

	if(numer_serwa_odebranego == 6)
	{
		numer_serwa_odebranego = 0;
		// dane sa dobre bo program odpowiedzial 'Z'
		if(rec_data == CRC)
		{
			unsigned char i;
			for(i = 0; i < 6; i++)
				tiki_dla_serw[i] = tmp_tiki_dla_serw[i];
		}
		CRC = 0;
	}
	else
	{
		CRC += rec_data;
		tmp_tiki_dla_serw[numer_serwa_odebranego] = tiki_dla_katow[(unsigned char)rec_data];
		if(++numer_serwa_odebranego == 7)
			numer_serwa_odebranego = 0;
	}

	odebrano_dane = 1;
}



int main(void)
{
	Init();
	LED_1_ON;
	_delay_ms(500);
	LED_1_OFF;
	unsigned char i;
	for(i = 0; i < 6; i++)
		tiki_dla_serw[i] = tiki_dla_katow[90 + offset_tiki_dla_serw[i]];
	sei();

	// zainicjowanie komunikacji
	while(1)
	{
		if(czy_zmienic_serwo) // czas na zmiane serwa
		{
			czy_zmienic_serwo = 0;
			ZmienSerwo();
			if(++numer_serwa_do_zmiany == 8)
				numer_serwa_do_zmiany = 0;
		}
		if(czy_wylaczyc_serwa)
		{
			czy_wylaczyc_serwa = 0;
			WylaczSerwa();
		}

	}
}


void Init(void)
{
	// F cpu = 11,0592 MHz
	// inicjalizacja Timer0, ktory bedzie odmierzal okresy 2.5ms
	TCCR0 |= (1<<CS01); // preskaler = 8, czyli na 2.5ms, trzeba uzbierac 3456 tikow, czyli 128*27
	TIMSK |= (1<<TOIE0); // odblokowanie przerwania Timer0
	TCNT0 = 127; // do przepelneinia musi miec 250

	/*
	 wg jakis danych, sygnal serwa TowerPro SG90 ma:
	 neutralny - 1,5ms
	 0  -  0,6ms   =   829 tikow
	 180 - 2,5ms
	 1st = (2,5-0,6)/180 = 0,0105555ms  =  14,6 tikow
	 */
	// inicjalizacja Timer1, ktory bedzie odmierzal okresy dla stanow wysokich dla kazdego serwa
	TCCR1B |= (1<<CS11); //
	TIMSK |= (1<<TOIE1); // odblokowanie przerwania
	TCNT1 = 0;  // bedzie dlugo zliczal, ale potem sie nadpisze to

	// ustawienie Timer2 do generowania przerwan dla danych z UART
	TCCR2 |= (1<<CS22) | (1<<CS21) | (1<<CS20);
	TIMSK |= (1 << TOIE2);
	TCNT2 = 20;


	// ustawienia UART
	 //ustaw obliczone przez makro wartoœci
	 UBRRH = UBRRH_VALUE;
	 UBRRL = UBRRL_VALUE;
	 #if USE_2X
		 UCSRA |=  (1<<U2X);
	 #else
		 UCSRA &= ~(1<<U2X);
	 #endif
		UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);  //bitów danych: 8
														//bity stopu:  1
														//parzystoœæ:  brak
	 //w³¹cz nadajnik i odbiornik oraz ich przerwania odbiornika
	 //przerwania nadajnika w³¹czamy w funkcji wyslij_wynik()
	 UCSRB = (1<<TXEN) | (1<<RXEN) | (1<<RXCIE);


	// inicjalizacja portow serw
	SERWO_1_DDR;
	SERWO_2_DDR;
	SERWO_3_DDR;
	SERWO_4_DDR;
	SERWO_5_DDR;
	SERWO_6_DDR;

	// inicjalizacja diod
	LED_1_DDR;
	LED_2_DDR;
	LED_1_OFF;
	LED_2_OFF;

	// wypelnienie tablicy wartosciami tikow dla poszczegolnych katow
	float i;
	int index = 0;
	for(i = -90.0; i <= 90.0; i += 1.0)
	{
		tiki_dla_katow[index++] = (int)(829 + (90.0 + i)*14.05);
	}
}



void ZmienSerwo(void)
{
	if(numer_serwa_do_zmiany == 0)
	{
		SERWO_1_ON;
		TCNT1 = 0xFFFF - tiki_dla_serw[0];
		return;
	}
	if(numer_serwa_do_zmiany == 1)
	{
		SERWO_2_ON;
		TCNT1 = 0xFFFF - tiki_dla_serw[1];
		return;
	}
	if(numer_serwa_do_zmiany == 2)
	{
		SERWO_3_ON;
		TCNT1 = 0xFFFF - tiki_dla_serw[2];
		return;
	}
	if(numer_serwa_do_zmiany == 3)
	{
		SERWO_4_ON;
		TCNT1 = 0xFFFF - tiki_dla_serw[3];
		return;
	}
	if(numer_serwa_do_zmiany == 4)
	{
		SERWO_5_ON;
		TCNT1 = 0xFFFF - tiki_dla_serw[4];
		return;
	}
	if(numer_serwa_do_zmiany == 5)
	{
		SERWO_6_ON;
		TCNT1 = 0xFFFF - tiki_dla_serw[5];
		return;
	}
}


void WylaczSerwa(void)
{
	SERWA_PORTC_OFF;
}

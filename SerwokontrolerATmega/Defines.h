/*
 * Defines.h
 *
 *  Created on: 17-12-2015
 *      Author: bartek
 */

#ifndef DEFINES_H_
#define DEFINES_H_

// porty do serw
#define SERWO_1_DDR DDRC |= 0x01
#define SERWO_2_DDR DDRC |= 0x02
#define SERWO_3_DDR DDRC |= 0x04
#define SERWO_4_DDR DDRC |= 0x08
#define SERWO_5_DDR DDRC |= 0x10
#define SERWO_6_DDR DDRC |= 0x20
#define SERWO_7_DDR DDRB |= 0x01
#define SERWO_8_DDR DDRD |= 0x80

// wlaczanie wylaczanie serw
#define SERWO_1_ON PORTC |= 0x01
#define SERWO_1_OFF PORTC &= ~0x01

#define SERWO_2_ON PORTC |= 0x02
#define SERWO_2_OFF PORTC &= ~0x02

#define SERWO_3_ON PORTC |= 0x04
#define SERWO_3_OFF PORTC &= ~0x04

#define SERWO_4_ON PORTC |= 0x08
#define SERWO_4_OFF PORTC &= ~0x08

#define SERWO_5_ON PORTC |= 0x10
#define SERWO_5_OFF PORTC &= ~0x10

#define SERWO_6_ON PORTC |= 0x20
#define SERWO_6_OFF PORTC &= ~0x20

#define SERWO_7_ON PORTB |= 0x01
#define SERWO_7_OFF PORTB &= ~0x01

#define SERWO_8_ON PORTD |= 0x80
#define SERWO_8_OFF PORTD &= ~0x80

#define SERWA_PORTC_OFF PORTC &= ~0x3F

// LEDY
#define LED_1_DDR DDRD |= 0x40
#define LED_2_DDR DDRD |= 0x80

#define LED_1_ON PORTD &= ~0x40
#define LED_1_OFF PORTD |= 0x40

#define LED_2_ON PORTD &= ~0x80
#define LED_2_OFF PORTD |= 0x80


#endif /* DEFINES_H_ */

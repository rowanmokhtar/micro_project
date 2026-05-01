#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "TYPES.h"

/* =========================================================
 * ATmega328P GPIO Registers
 * ATmega32 vs ATmega328P addresses are different!
 * =========================================================
 *
 * ATmega328P has NO PORTA — only B, C, D
 *
 * PORTB — Arduino Uno digital pins D8–D13
 * PORTC — Arduino Uno analog  pins A0–A5
 * PORTD — Arduino Uno digital pins D0–D7
 */

/* PORTB */
#define DDRB  *((volatile u8*)0x24)
#define PORTB *((volatile u8*)0x25)
#define PINB  *((volatile u8*)0x23)

/* PORTC */
#define DDRC  *((volatile u8*)0x27)
#define PORTC *((volatile u8*)0x28)
#define PINC  *((volatile u8*)0x26)

/* PORTD */
#define DDRD  *((volatile u8*)0x2A)
#define PORTD *((volatile u8*)0x2B)
#define PIND  *((volatile u8*)0x29)

#endif /* GPIO_PRIVATE_H */
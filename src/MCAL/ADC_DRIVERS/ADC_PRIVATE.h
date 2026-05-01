#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "TYPES.h"

/* =========================================================
 * ATmega328P ADC Registers
 * =========================================================
 * ATmega32  ADMUX  = 0x27  → ATmega328P ADMUX  = 0x7C
 * ATmega32  ADCSRA = 0x26  → ATmega328P ADCSRA = 0x7A
 * ATmega32  ADCH   = 0x25  → ATmega328P ADCH   = 0x79
 * ATmega32  ADCL   = 0x24  → ATmega328P ADCL   = 0x78
 * ATmega32  SFIOR  = 0x50  → ATmega328P ADCSRB = 0x7B (no SFIOR)
 */

#define ADMUX  *((volatile u8*)0x7C)
#define ADCSRA *((volatile u8*)0x7A)
#define ADCSRB *((volatile u8*)0x7B)
#define ADCH   *((volatile u8*)0x79)
#define ADCL   *((volatile u8*)0x78)

#endif /* ADC_PRIVATE_H */
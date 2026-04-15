#include "GPIO_INTERFACE.h"

void GPIO_setPinDirection(port_t port, pin_t pin, direction_t direction) {
    switch (port) {
        case GPIOA:
            switch (direction) {
                case INPUT: clearBit(DDRA, pin); break;
                case INPUT_PULLUP: clearBit(DDRA, pin); setBit(PORTA, pin); break;
                case OUTPUT: setBit(DDRA, pin); break;
            }
            break;

        case GPIOB:
            switch (direction) {
                case INPUT: clearBit(DDRB, pin); break;
                case INPUT_PULLUP: clearBit(DDRB, pin); setBit(PORTB, pin); break;
                case OUTPUT: setBit(DDRB, pin); break;
            }
            break;

        case GPIOC:
            switch (direction) {
                case INPUT: clearBit(DDRC, pin); break;
                case INPUT_PULLUP: clearBit(DDRC, pin); setBit(PORTC, pin); break;
                case OUTPUT: setBit(DDRC, pin); break;
            }
            break;

        case GPIOD:
            switch (direction) {
                case INPUT: clearBit(DDRD, pin); break;
                case INPUT_PULLUP: clearBit(DDRD, pin); setBit(PORTD, pin); break;
                case OUTPUT: setBit(DDRD, pin); break;
            }
            break;
    }
}

void GPIO_setPinValue(port_t port, pin_t pin, value_t value) {
    switch (port) {
        case GPIOA:
            switch (value) {
                case LOW: clearBit(PORTA, pin); break;
                case HIGH: setBit(PORTA, pin); break;
            }
            break;

        case GPIOB:
            switch (value) {
                case LOW: clearBit(PORTB, pin); break;
                case HIGH: setBit(PORTB, pin); break;
            }
            break;

        case GPIOC:
            switch (value) {
                case LOW: clearBit(PORTC, pin); break;
                case HIGH: setBit(PORTC, pin); break;
            }
            break;

        case GPIOD:
            switch (value) {
                case LOW: clearBit(PORTD, pin); break;
                case HIGH: setBit(PORTD, pin); break;
            }
            break;
            
    }
}

void GPIO_togglePinValue(port_t port, pin_t pin) {
    switch (port) {
        case GPIOA: toggleBit(PORTA, pin); break;
        case GPIOB: toggleBit(PORTB, pin); break;
        case GPIOC: toggleBit(PORTC, pin); break;
        case GPIOD: toggleBit(PORTD, pin); break;
    }
}

value_t GPIO_readPinValue(port_t port, pin_t pin) {
    u8 value = 0;  // Default value
    switch (port) {
        case GPIOA: value = readBit(PINA, pin); break;
        case GPIOB: value = readBit(PINB, pin); break;
        case GPIOC: value = readBit(PINC, pin); break;
        case GPIOD: value = readBit(PIND, pin); break;
    }
    return value;
}

void GPIO_setPortDirection (port_t port, direction_t direction){
    switch (port) {
        case GPIOA:
            switch (direction) {
                case INPUT: DDRA = 0x00; break;
                case INPUT_PULLUP: DDRA = 0x00; PORTA = 0xFF; break;
                case OUTPUT: DDRA = 0xFF; break;
            }
            break;

        case GPIOB:
            switch (direction) {
                case INPUT: DDRB = 0x00; break;
                case INPUT_PULLUP: DDRB = 0x00; PORTB = 0xFF; break;
                case OUTPUT: DDRB = 0xFF; break;
            }
            break;

        case GPIOC:
            switch (direction) {
                case INPUT: DDRC = 0x00; break;
                case INPUT_PULLUP: DDRC = 0x00; PORTC = 0xFF; break;
                case OUTPUT: DDRC = 0xFF; break;
            }
            break;

        case GPIOD:
            switch (direction) {
                case INPUT: DDRD = 0x00; break;
                case INPUT_PULLUP: DDRD = 0x00; PORTD = 0xFF; break;
                case OUTPUT: DDRD = 0xFF; break;
            }
            break;
    }
}

void GPIO_setPortValue (port_t port, value_t value){
    switch (port) {
        case GPIOA:
            PORTA = value;
            break;

        case GPIOB:
            PORTB = value;
            break;

        case GPIOC:
            PORTC = value;
            break;

        case GPIOD:
            PORTD = value;
            break;
    }
}

u8 GPIO_readPortValue(port_t port) {
    u8 value = 0;  // Default value
    switch (port) {
        case GPIOA: value = PINA; break;
        case GPIOB: value = PINB; break;
        case GPIOC: value = PINC; break;
        case GPIOD: value = PIND; break;
        }
    return value;  // Default return value
}


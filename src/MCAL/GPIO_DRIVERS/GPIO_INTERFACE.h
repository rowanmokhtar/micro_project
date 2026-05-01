#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "GPIO_PRIVATE.h"

/* ATmega328P has NO PORTA */
typedef enum {
    GPIOB,
    GPIOC,
    GPIOD
} port_t;

typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} pin_t;

typedef enum {
    INPUT,
    INPUT_PULLUP,
    OUTPUT
} direction_t;

typedef enum {
    LOW,
    HIGH
} value_t;

void    GPIO_setPinDirection (port_t port, pin_t pin, direction_t direction);
void    GPIO_setPinValue     (port_t port, pin_t pin, value_t value);
void    GPIO_togglePinValue  (port_t port, pin_t pin);
value_t GPIO_readPinValue    (port_t port, pin_t pin);

void    GPIO_setPortDirection(port_t port, direction_t direction);
void    GPIO_setPortValue    (port_t port, value_t value);
u8      GPIO_readPortValue   (port_t port);

#endif /* GPIO_INTERFACE_H */
#ifndef BATTERY_H
#define BATTERY_H


#include "../MCAL/ADC_DRIVERS/ADC_INTERFACE.h"
#include "../MCAL/GPIO_DRIVERS/GPIO_INTERFACE.h"


void BATTERY_init(void);

f32 BATTERY_getVoltage(void);


u8 BATTERY_isLow(void);

void BATTERY_updateLED(void);

#endif /* BATTERY_H */
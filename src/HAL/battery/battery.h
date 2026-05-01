#ifndef BATTERY_H
#define BATTERY_H

#include "ADC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "C:\Users\rowan\Documents\PlatformIO\Projects\micro project1\src\HAL\motor\motor.h"

void BATTERY_init(void);
f32  BATTERY_getVoltage(void);
void BATTERY_updateLED(Motor_State motorState);


#endif /* BATTERY_H */
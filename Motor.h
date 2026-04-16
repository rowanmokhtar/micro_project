#ifndef MOTOR_H_
#define MOTOR_H_

#include "GPIO_INTERFACE.h"

typedef enum {
    STOP,
    FORWARD,
    BACKWARD,
    RIGHT,
    LEFT
} Motor_State;

void Motor_init(void);
void Motor_move(Motor_State state);

#endif
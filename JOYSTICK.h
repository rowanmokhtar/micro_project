#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "../MCAL/GPIO DRIVERS/TYPES.h"

typedef struct{
    s16 x;
    s16 y;
} JOY_pos_t;

void JOY_init (void);

void JOY_read(JOY_pos_t* pos);

#endif

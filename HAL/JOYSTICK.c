#include "JOYSTICK.h"
#include "../MICRO_PROJECT/MCAL/ADC_DRIVERS/ADC_INTERFACE.h"

#define JOY_CH_X 0
#define JOY_CH_Y 1

#define CENTER 512
#define DEAD_ZONE 30

// normalize the value to be from -100 to 100
s16 normalize (u16 value)
{
    if (value > CENTER + DEAD_ZONE || value < CENTER - DEAD_ZONE){
        return ((value - CENTER) * 100) / CENTER;
    }
    else return 0;
}

void JOY_init ()
{
    ADC_init (JOY_CH_X, DIV_128);
    ADC_init (JOY_CH_Y, DIV_128);
}

void JOY_read (JOY_pos_t* pos)
{
    
    u16 ADC_x = ADC_read(JOY_CH_X);
    u16 ADC_y = ADC_read(JOY_CH_Y);

    pos->x = normalize (ADC_x);
    pos->y = normalize (ADC_y);
}

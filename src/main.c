#include "GPIO_INTERFACE.H"
#include "ADC_INTERFACE.H"
#include "joystick.h"
#include "motor.h"
#include "battery.h"

#define KILL_SW_PORT  GPIOD 
#define KILL_SW_PIN   PIN6

#define BAT_CHECK_INTERVAL  200U

static void delay_ms(u16 ms)
{
    while (ms--)     //delay
    {
        volatile u16 i;
        for (i = 0; i < 4000; i++);
    }
}

int main(void)
{
    //JOY_pos_t pos;          

    Motor_init();
    JOY_init();
    BATTERY_init();

    GPIO_setPinDirection(KILL_SW_PORT, KILL_SW_PIN, INPUT);

    //u16 bat_counter = 0;

    while (1)
    {
       
        Motor_init();
    JOY_init();
    BATTERY_init();
    GPIO_setPinDirection(KILL_SW_PORT, KILL_SW_PIN, INPUT);
}

while(1) {
 
    Motor_State currentState = STOP;
    
    static u8 system_started = 0; 

    if (GPIO_readPinValue(KILL_SW_PORT, KILL_SW_PIN) == HIGH) {
        currentState = STOP;
        system_started = 0;
    } else {
        JOY_pos_t pos;
        JOY_read(&pos);

        s16 x = pos.x;
        s16 y = pos.y;

        if (x != 0 || y != 0) {
            system_started = 1;
        }

        if (system_started == 0) {
          
            Motor_move(STOP);
        } else {
           
            s16 left  = y + x;
            s16 right = y - x;

            if (left > 0 && right > 0) currentState = FORWARD;
            else if (left < 0 && right < 0) currentState = BACKWARD;
            else if (left > 0 && right < 0) currentState =RIGHT;
            else if (left < 0 && right > 0) currentState =LEFT;
            else currentState = STOP;
        }
    }

    Motor_move(currentState);

    BATTERY_updateLED(currentState);

    delay_ms(1);
}
}
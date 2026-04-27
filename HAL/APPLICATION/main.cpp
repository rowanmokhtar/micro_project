

#include "../MCAL/GPIO_DRIVERS/GPIO_INTERFACE.h"
#include "../MCAL/ADC_DRIVERS/ADC_INTERFACE.h"
#include "JOYSTICK.h"
#include "Motor.h"
#include "BATTERY.h"

#define KILL_SW_PORT    GPIOD
#define KILL_SW_PIN     PIN6   

#define BAT_CHECK_INTERVAL  200U   


static void delay_ms(u16 ms)
{
    while (ms--)
    {
        volatile u16 i;
        for (i = 0; i < 4000; i++);
    }
}

int main(void)
{
    // Initialize peripherals
    Motor_init();      
    JOY_init ();    
    BATTERY_init();  

  
    GPIO_setPinDirection(KILL_SW_PORT, KILL_SW_PIN, INPUT);

    
    u16 bat_counter = 0;

    while (1)
    {
      
        if (GPIO_readPinValue(KILL_SW_PORT, KILL_SW_PIN) == HIGH)
        {
            Motor_move(STOP);  
        }
        else
        {
           
            s16 x = JOY_read(&pos);
            s16 y = JOY_read(&pos);   

            s16 left  = y + x;
            s16 right = y - x;

            if (left  >  255) left  =  255;
            if (left  < -255) left  = -255;
            if (right >  255) right =  255;
            if (right < -255) right = -255;

           
               if (left > 0 && right > 0)
                    Motor_move(FORWARD);
                else if (left < 0 && right < 0)
                    Motor_move(BACKWARD);
                else if (left > 0 && right < 0)
                    Motor_move(RIGHT);
                else if (left < 0 && right > 0)
                    Motor_move(LEFT);
                else
                    Motor_move(STOP);  
        }

// battery check 
        bat_counter++;
        if (bat_counter >= BAT_CHECK_INTERVAL)
        {
            bat_counter = 0;
            BATTERY_updateLED();   
        }

        
        delay_ms(1);

    } 

    return 0;
}
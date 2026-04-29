#include "BATTERY.h"


#define BAT_CH      ADC2       


#define DIV_RATIO   3.0f       


#define ADC_VREF    5.0f                                     


#define LOW_BAT     11.1f

#define LED_PORT    GPIOB
#define LED_PIN     PIN0

void BATTERY_init(void)
{
   
    ADC_init(AVCC, DIV_128);

  
    GPIO_setPinDirection(LED_PORT, LED_PIN, OUTPUT);
    GPIO_setPinValue(LED_PORT, LED_PIN, LOW);
}

f32 BATTERY_getVoltage(void)
{
    u16 raw = ADC_read(BAT_CH);

    
    f32 v_adc = ADC_convert_to_v(raw, ADC_VREF);

    return v_adc * DIV_RATIO;
}

u8 BATTERY_isLow(void)
{
    return (BATTERY_getVoltage() < LOW_BAT) ? 1 : 0;
}

void BATTERY_updateLED(void)
{
    if (BATTERY_isLow())
        GPIO_setPinValue(LED_PORT, LED_PIN, HIGH);  
    else
        GPIO_setPinValue(LED_PORT, LED_PIN, LOW);   
}